#include "PreProcessing.hpp"

PreProcessor::PreProcessor(const Scanner &scanner, const Parser &parser, Program &prog)
  : scanner{scanner}, parser{parser}, program{prog}
  {
    // Create set of all special characters that need spacing for token identification
    validSpecialCharacters.insert(';');
    validSpecialCharacters.insert('+');
    validSpecialCharacters.insert(':');
    validSpecialCharacters.insert(',');
  }

void PreProcessor::exec() {
  std::ifstream ifs(program.file.fullname());
  // Testing if file can be oppened
  if (!ifs.is_open()) {
    throw std::runtime_error("[ERR] " + program.file.fullname() + " could not be opened");
  }
  string line;
  string processed_line;
  unsigned int program_size = 0;
  vector<Token> tokens;
  // Used for verification if label is in a line before
  bool needs_concate = false;
  Token main_token;

  // Pre process each line individually
  while(std::getline(ifs, line)) {
    // Call function to remove all comentaries (all chars after ;)
    processed_line = removeComments(line);
    // Check if line is empty (all white spaces)
    if (processed_line.empty() ||
      std::all_of(processed_line.begin(), processed_line.end(),
        [](char c){
          return std::isspace(static_cast<unsigned char>(c));
      })) {
      continue;
    }
    // Add space between tokens to make process of separation easier
    processed_line = spaceTokens(processed_line);
    // Split line in tokens and get them all in uppercase
    tokens = scanner.splitIntoTokens(processed_line);
    // Check if last line parsed was just a label
    if (needs_concate) {
      // Concatenates with the last line
      program.tokens.back().insert(program.tokens.back().end(), tokens.begin(), tokens.end());
      needs_concate = false;
    } else {
      // If last line was not a lone label
      program.tokens.push_back(tokens);
      ++program_size;
    }
    if (tokens.back().type == TokenType::LABEL_COLON) {
      needs_concate = true;
    }

  }
  if (program_size != program.tokens.size()) {
    // cout << "Program counted: " << program_size << " Program size: " << program.tokens.size();
    throw std::runtime_error("[ERR] Program was not read correctly!");
  }
  for (unsigned int line = 0; line < program.tokens.size(); ++line) {
    parser.isExpressionValid(program.tokens.at(line), line);
    // Add label to equ_table
    main_token = parser.getInstructionOrDirective(program.tokens.at(line), line);
    substEqu(line);
    if (main_token.tvalue == "EQU") {
      dealingWithEqu(line);
      --line;
    } else if (main_token.tvalue == "IF") {
      if (program.tokens.at(line).back().type == TokenType::NUMBER_DECIMAL ||
          program.tokens.at(line).back().type == TokenType::NUMBER_HEX) {
        // If the argument is 0: erase this line and the next
        if (std::stoi(program.tokens.at(line).back().tvalue) == 0) {
          program.tokens.erase(program.tokens.begin() + line);
          program.tokens.erase(program.tokens.begin() + line);
          --line;
        } else { // If the argument is not 0: erase this line
          program.tokens.erase(program.tokens.begin() + line);
          --line;
        }
      }
    }
  }
  // Macro is dealt last, because if the macro contains an EQU or IF it is already resolved
  for (unsigned int line = 0; line < program.tokens.size(); ++line) {
    line = substMacro(line);
    main_token = parser.getInstructionOrDirective(program.tokens.at(line), line);
    if (main_token.tvalue == "MACRO") {
      dealingWithMacro(line);
      --line;
    }
  }
  macro_table.printMacros();
}

// Creates separation of special characters from the rest of tokens to
// make split easier
string PreProcessor::spaceTokens(string line) {
  string new_line;
  for (char const &character : line) {
    if (validSpecialCharacters.find(character) != validSpecialCharacters.end()) {
      new_line.push_back(' ');
      new_line.push_back(character);
      new_line.push_back(' ');
    } else {
      new_line.push_back(character);
    }
  }
  return new_line;
}

// Remove comments from the rest of the line
string PreProcessor::removeComments(string line) {
  return line.substr(0, line.find(";"));
}

void PreProcessor::writePreProcessedFile() {
  std::ofstream preprocessed_file;
  preprocessed_file.open(program.file.name() + ".pre");
  for (const vector<Token> &line : program.tokens) {
    for (const Token &token : line) {
      preprocessed_file << token.tvalue << " ";
    }
    preprocessed_file << endl;
  }
  preprocessed_file.close();
}

void PreProcessor::dealingWithEqu(int line) {
  if (parser.hasLabel(program.tokens.at(line))) {
    if (equ_table.isEquDefined(program.tokens.at(line).front())) {
      cout << "[SEMANTIC ERR] Line: " << line << " | Equ label already in use." << endl;
    } else {
      equ_table.addEqu(program.tokens.at(line).front(), program.tokens.at(line).back());
    }
  } else {
    cout << "[SYNTAX ERR] Line: " << line <<" | Missing label." << endl;
  }
  program.tokens.erase(program.tokens.begin() + line);
}

void PreProcessor::substEqu(int line) {
  // Redefines symbol acording to EQU
  for (unsigned int indx = 0; indx < program.tokens.at(line).size(); ++indx) {
    if (equ_table.isEquDefined(program.tokens.at(line).at(indx))) {
      program.tokens.at(line).at(indx) = equ_table.getEquToken(program.tokens.at(line).at(indx));
    }
  }
}

void PreProcessor::dealingWithMacro(int line) {
  Token main_token;
  bool found_end = false;
  string macro_name;
  int num_operands = 0;
  // Check if macro name is beign defined
  if (parser.hasLabel(program.tokens.at(line))) {
    // Check if the macro is being redefined
    if (macro_table.isMacroDefined(program.tokens.at(line).front())) {
      cout << "[SEMANTIC ERR] Line: " << line << " | Macro label already in use." << endl;
    } else {
      macro_name = program.tokens.at(line).front().tvalue;
      Macro macro = Macro(macro_name);
      // Body of the macro must be at the next line
      if ((line + 1) == program.tokens.size()) {
        cout << "[SYNTAX ERR] Line: " << line << " | Macro being defined in the last line." << endl;
      }
      // Get all operands
      for (const Token &token : program.tokens.at(line)) {
        if (token.type == TokenType::MACRO_PARAMETER) {
          ++num_operands;
          macro.addOperand(token.tvalue);
        }
      }
      program.tokens.erase(program.tokens.begin() + line);
      // For each line until the end, increment
      for (unsigned int macro_line = (line + 1); macro_line < program.tokens.size(); ++macro_line) {
        main_token = parser.getInstructionOrDirective(program.tokens.at(macro_line), macro_line);
        if (main_token.type == TokenType::ENDMACRO) {
          found_end = true;
          program.tokens.erase(program.tokens.begin() + macro_line);
          break;
        }
        macro.macro_definition.push_back(program.tokens.at(macro_line));
        program.tokens.erase(program.tokens.begin() + macro_line);
        --macro_line;
      }
      if (!found_end) {
        cout << "[SYNTATIC ERROR] Macro does not have an end!" << endl;
      }
      macro_table.insert(macro_name, macro);
    }
  } else {
    cout << "[SYNTAX ERR] Line: " << line <<" | Missing label." << endl;
  }
  program.tokens.erase(program.tokens.begin() + line);
}

int PreProcessor::substMacro(int line) {
  // Redefines symbol acording to MACRO
  std::vector<int>::iterator it;
  for (unsigned int indx = 0; indx < program.tokens.at(line).size(); ++indx) {
    if (macro_table.isMacroDefined(program.tokens.at(line).at(indx))) {
      program.tokens.erase(program.tokens.begin() + line);
      --line;
      // program.tokens.insert()
      cout << "MACRO FOUND!" << endl;
    }
  }
  return line;
}

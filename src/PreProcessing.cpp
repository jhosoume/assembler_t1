#include "PreProcessing.hpp"

PreProcessor::PreProcessor(const File &file, const Scanner &scanner, Program &prog)
  : input_file{file}, scanner{scanner}, program{prog}
  {
    // Create set of all special characters that need spacing for token identification
    validSpecialCharacters.insert(';');
    validSpecialCharacters.insert('+');
    validSpecialCharacters.insert(':');
    validSpecialCharacters.insert(',');
  }

void PreProcessor::exec() {
  std::ifstream ifs(input_file.fullname());
  // Testing if file can be oppened
  if (!ifs.is_open()) {
    throw std::runtime_error("[ERR] " + input_file.fullname() + " could not be opened");
  }
  string line;
  string processed_line;
  unsigned int program_size = 0;
  vector<Token> tokens;
  // Used for verification if label is in a line before
  bool needs_concate = false;

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
  preprocessed_file.open(input_file.name() + ".pre");
  for (const vector<Token> &line : program.tokens) {
    for (const Token &token : line) {
      preprocessed_file << token.tvalue << " ";
    }
    preprocessed_file << endl;
  }
  preprocessed_file.close();
}

#include "PreProcessing.hpp"

PreProcessor::PreProcessor(const File &file, const Parser &parser, Program &prog)
  : input_file{file}, parser{parser}, program{prog}
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
  vector<Token> tokens;
  bool needs_concate = false;

  int program_size = 0;
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
    tokens = parser.splitIntoTokens(processed_line);
    if (needs_concate) {
      program.tokens.back().insert(program.tokens.back().end(), tokens.begin(), tokens.end());
      needs_concate = false;
    } else {
      program.tokens.push_back(tokens);
    }
    if (tokens.back().type == TokenType::LABEL_COLON) {
      needs_concate = true;
    }
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

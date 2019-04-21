#include "PreProcessing.hpp"

PreProcessor::PreProcessor(File file)
  : input_file{file}
  {
    // Create set of all special characters that need spacing
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
  vector<string> tokens;

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
    cout << processed_line << endl;
    // Split line in tokens
    tokens = Parser::splitIntoTokens(processed_line);
  }
}

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

string PreProcessor::removeComments(string line) {
  return line.substr(0, line.find(";"));
}

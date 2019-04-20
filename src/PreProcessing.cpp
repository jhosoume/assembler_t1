#include "PreProcessing.hpp"

PreProcessor::PreProcessor(File file)
  : input_file{file}
  {
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

  while(std::getline(ifs, line)) {
    processed_line = spaceTokens(line);
    cout << processed_line << endl;
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

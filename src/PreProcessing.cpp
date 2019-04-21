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
  vector<string> tokens;

  while(std::getline(ifs, line)) {
    processed_line = removeComments(line);
    if (processed_line.empty() ||
      std::all_of(processed_line.begin(), processed_line.end(),
        [](char c){
          return std::isspace(static_cast<unsigned char>(c));
      }))
      continue;
    processed_line = spaceTokens(processed_line);
    cout << processed_line << endl;
    tokens = splitIntoTokens(processed_line);
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

vector<string> PreProcessor::splitIntoTokens(string line) {
  string delimiters = "\t   ";
  vector<string> line_words = split(line, delimiters);
  return line_words;
}

string PreProcessor::removeComments(string line) {
  string new_line;
  for (char const &character : line) {
  }
  return new_line;
}

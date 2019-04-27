#include "Program.hpp"

Program::Program()
  : num_lines{0}
  {}

void Program::showTokenswithType() {
  cout << endl << "Printing Tokens and Types" << endl;
  for (int line = 0; line < tokens.size(); ++line) {
    for (auto token : tokens.at(line)) {
      cout << line << " Token-> " << token.tvalue << " value-> " << TokenTypeToString(token.type) << endl;
    }
  }
}

void Program::showTokens() {
  for (int line = 0; line < tokens.size(); ++line) {
    cout << line << " ";
    for (auto token : tokens.at(line)) {
      cout << token.tvalue << " ";
    }
    cout << endl;
  }
}

#include "SecondPass.hpp"

SecondPass::SecondPass(const Parser &parser, const Program &prog, const SymbolTable &sbt)
  : parser{parser}, program{prog}, symbol_table{sbt}
  {}

void SecondPass::exec() {
  vector<Token> tokens;
  for (unsigned int line = 0; line < program.tokens.size(); ++line) {
    cout << line << " ";
    tokens = program.tokens.at(line);
    if (parser.hasLabel(tokens)) {
      tokens.assign(tokens.begin() + 2, tokens.end());
    }
    for (auto token : tokens) {
      cout << token.tvalue << " ";
    }
    cout << endl;
  }
}

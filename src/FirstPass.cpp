#include "FirstPass.hpp"

FirstPass::FirstPass(const Parser &parser, const Program &prog)
  : parser{parser}, program{prog}
  {}

SymbolTable FirstPass::exec() {
  for (int line = 0; line < program.tokens.size(); ++line) {
    cout << line << " ";
    for (auto token : program.tokens.at(line)) {
      cout << token.tvalue << " ";
    }
    cout << endl;
  }

  SymbolTable symbol_table = SymbolTable();
  return symbol_table;
}

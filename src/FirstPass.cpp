#include "FirstPass.hpp"

FirstPass::FirstPass(const Parser &parser, const Program &prog)
  : parser{parser}, program{prog}, text_section{false}, data_section{false}
  {}

SymbolTable FirstPass::exec() {
  SymbolTable symbol_table = SymbolTable();
  int program_counter = 0;
  for (unsigned int line = 0; line < program.tokens.size(); ++line) {
    if ( parser.hasLabel(program.tokens.at(line)) ) {
      symbol_table.addSymbol(program.tokens.at(line).front(), program_counter);
    }
    program_counter += parser.calculateSizeOfExpression(program.tokens.at(line), line);
  }
  symbol_table.listTable();
  program.total_size = program_counter;
  return symbol_table;
}

#include "FirstPass.hpp"

FirstPass::FirstPass(const Parser &parser, const Program &prog)
  : parser{parser}, program{prog}
  {}

SymbolTable FirstPass::exec() {
  SymbolTable symbol_table = SymbolTable();
  int program_counter = 0;
  Token main_token;
  for (unsigned int line = 0; line < program.tokens.size(); ++line) {
    int value = 0;
    int vec_size = 0;
    SymbolType s_type = SymbolType::INSTRUCTION;
    if ( parser.hasLabel(program.tokens.at(line)) ) {
      main_token = parser.getInstructionOrDirective(program.tokens.at(line));
      if (main_token.tvalue == "CONST") {
        s_type = SymbolType::CONST;
        if (program.tokens.at(line).back().type == TokenType::NUMBER_DECIMAL) {
          value = std::stoi(program.tokens.at(line).back().tvalue);
        } else if (program.tokens.at(line).back().type == TokenType::NUMBER_HEX) {
          value = std::stoi(program.tokens.at(line).back().tvalue, nullptr, 16);
        }
      } else if (main_token.tvalue == "SPACE") {
        s_type = SymbolType::SPACE;
        if (program.tokens.at(line).back().type == TokenType::NUMBER_DECIMAL) {
          vec_size = std::stoi(program.tokens.at(line).back().tvalue);
        } else if (program.tokens.at(line).back().type == TokenType::NUMBER_HEX) {
          vec_size = std::stoi(program.tokens.at(line).back().tvalue, nullptr, 16);
        }
      }
      symbol_table.addSymbol(program.tokens.at(line).front().tvalue, program_counter, s_type, value, vec_size);
    }
    program_counter += parser.calculateSizeOfExpression(program.tokens.at(line), line);
  }
  symbol_table.listTable();
  program.total_size = program_counter;
  return symbol_table;
}

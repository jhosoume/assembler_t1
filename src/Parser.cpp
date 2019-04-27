#include "Parser.hpp"

Parser::Parser(const InstructionTable &inst_t, const DirectiveTable &dir_t)
  : instruction_table{inst_t}, directive_table{dir_t}
{}

bool Parser::isExpressionValid(const vector<Token> &tokens) {
  return true;
}

bool Parser::checkNumOfLabels(const vector<Token> &tokens) {
  int num_labels = 0;
  for (const Token &token : tokens) {
    if(token.type == TokenType::LABEL_COLON)
  }

}

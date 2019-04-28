#include "Parser.hpp"

Parser::Parser(const InstructionTable &inst_t, const DirectiveTable &dir_t)
  : instruction_table{inst_t}, directive_table{dir_t}
{}

// Make sintatic analysis of a line of tokens (Expression)
bool Parser::isExpressionValid(const vector<Token> &tokens) {
  return true;
}

// Check if more than one labeld is defined in a line
bool Parser::checkNumOfLabels(const vector<Token> &tokens) {
  int num_labels = 0;
  for (const Token &token : tokens) {
    if(token.type == TokenType::LABEL_COLON) {
      ++num_labels;
    }
  }
  return num_labels > 1;
}


Token Parser::getInstructionOrDirective(const vector<Token> &tokens) {
  int num_dir_or_inst = 0;
  Token dir_or_inst;
  for (const Token &token : tokens) {
    if(token.type == TokenType::INSTRUCTION_TOKEN || token.type == TokenType::DIRECTIVE_TOKEN) {
      ++num_dir_or_inst;
      dir_or_inst = token;
    }
  }
  if (num_dir_or_inst > 1) {
    cout << "[ERR] line with more than one instruction or directive!" << endl;
  }
  return dir_or_inst;
}

int Parser::calculateSizeOfExpression()

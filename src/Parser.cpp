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
    if(token.type == TokenType::INSTRUCTION_TOKEN ||
       token.type == TokenType::DIRECTIVE_TOKEN   ||
       token.type == TokenType::SECTION           ||
       token.type == TokenType::MACRO             ||
       token.type == TokenType::ENDMACRO
    ) {
      ++num_dir_or_inst;
      dir_or_inst = token;
    }
  }
  if (num_dir_or_inst > 1) {
    cout << "[ERR] Line with more than one instruction or directive!" << endl;
  } else if (num_dir_or_inst <= 0) {
    cout << "[ERR] Line does not have a directive or an instruction!" << endl;
  }
  return dir_or_inst;
}

int Parser::calculateSizeOfExpression(const vector<Token> &tokens) {
  int size = 0;
  Token dir_inst_token = getInstructionOrDirective(tokens);
  if (dir_inst_token.type == TokenType::INSTRUCTION_TOKEN) {
    return instruction_table.get(dir_inst_token).size;
  } else if (dir_inst_token.type == TokenType::DIRECTIVE_TOKEN) {
    size = directive_table.get(dir_inst_token).size;
    if ((size == -1) &&
        (dir_inst_token.tvalue == "SPACE")) {
        if (tokens[tokens.size() - 2].type == TokenType::ADD_SYMBOL)
          return std::stoi(tokens.back().tvalue);
        else
          return 1;
    }
    return size;
  } else if (dir_inst_token.type == TokenType::SECTION) {
    return 0;
  } else if (directive_table.isPreProcessDirective(dir_inst_token)) {
    cout << "[ERR] Pre processement directive was not dealt correctly!" << endl;
    return 0;
  } else {
    cout << "[ERR] Line does not have a directive or an instruction!" << endl;
    return 0;
  }

}

#include "Parser.hpp"

Parser::Parser(const InstructionTable &inst_t, const DirectiveTable &dir_t)
  : instruction_table{inst_t}, directive_table{dir_t}
{}

// Make sintatic analysis of a line of tokens (Expression)
bool Parser::isExpressionValid(const vector<Token> &tokens) {
  return checkLabelValid(tokens);
}

bool Parser::checkLabelValid(const vector <Token> &tokens) {
  int num_labels = 0;
  for (unsigned int token_indx = 0; token_indx < tokens.size(); ++token_indx) {
    if (tokens.at(token_indx).type == TokenType::LABEL_COLON) {
      ++num_labels;
      // Verifies if colon has a symbol defining a label before
      if (token_indx <= 0 ||
          tokens.at(token_indx - 1).type != TokenType::SYMBOL) {
            cout << "[ERR] Colon is not accompanied by a label!" << endl;
            return false;
      }
    }
  }
  // Only valid if there is one or none labels
  bool result = num_labels < 1;
  if (!result)
    cout << "[ERROR] Expression has more than one label!";
  return result;
}

bool Parser::hasLabel(const vector <Token> &tokens) {
  for (const Token &token : tokens) {
    if (token.type == TokenType::LABEL_COLON) {
      return true;
    }
  }
  return false;
}

// Get the main token of the expression. All expressions needs a directive
// or an instruction
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

// Function to calculate the total size of the instruction or directive
int Parser::calculateSizeOfExpression(const vector<Token> &tokens) {
  int size = 0;
  Token dir_inst_token = getInstructionOrDirective(tokens);
  // All instructions have a defined size
  if (dir_inst_token.type == TokenType::INSTRUCTION_TOKEN) {
    return instruction_table.get(dir_inst_token).size;
  // Some directives have a variable size
  } else if (dir_inst_token.type == TokenType::DIRECTIVE_TOKEN) {
    size = directive_table.get(dir_inst_token).size;
    // If the directive is a space, it depends on the allocated size
    if (dir_inst_token.tvalue == "SPACE") {
        if (tokens.back().type == TokenType::NUMBER_DECIMAL)
          return std::stoi(tokens.back().tvalue);
        else if (tokens.back().type == TokenType::NUMBER_HEX)
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

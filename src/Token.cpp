#include "Token.hpp"

Token::Token(string value, TokenType type)
  : tvalue{value}, type{type}, valid{isValid()}
  {}

bool Token::isValid() {
  return true;
}

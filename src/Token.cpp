#include "Token.hpp"

Token::Token(string value)
  : value{value}, type{classifyToken()}, valid{isValid()}
  {}

TOKEN_TYPE Token::classifyToken() {
  return TOKEN_TYPE::SYMBOL;
}

bool Token::isValid() {
  return true;
}

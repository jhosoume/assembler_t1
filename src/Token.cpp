#include "Token.hpp"

Token::Token(string value)
  : value{value}, type{Parser::classifyToken(value)}, valid{isValid()}
  {}

bool Token::isValid() {
  return true;
}

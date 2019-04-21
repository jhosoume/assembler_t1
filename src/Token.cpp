#include "Token.hpp"

Token::Token(string value, TokenType type, bool valid)
  : tvalue{value}, type{type}, valid{valid}
  {}

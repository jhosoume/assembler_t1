#include "Token.hpp"

Token::Token(string value, TokenType type, bool valid)
  : tvalue{value}, type{type}, valid{valid}
  {}


bool Token::operator ==(const Token &other_token) {
    return tvalue == other_token.tvalue;
}

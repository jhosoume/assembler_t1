#ifndef TOKEN
#define TOKEN

#include <string>

#include "TokenType.hpp"

using ::std::string;


class Token {
public:
  Token(string, TokenType);
  ~Token() {}
  string tvalue;
  TokenType type;
  bool valid;

private:
  bool isValid();
};

#endif

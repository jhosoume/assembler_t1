#ifndef TOKEN
#define TOKEN

#include <string>

#include "TokenType.hpp"
#include "Parser.hpp"

using ::std::string;


class Token {
public:
  Token(string);
  ~Token() {}
  string  value;
  TokenType type;
  bool valid;

private:
  bool isValid();
};

#endif

#ifndef PARSER
#define PARSER

#include <string>

using ::std::string;

class Parser {
public:
  Token(string);
  ~Token() {}

  static TOKEN_TYPE classifyToken(string);
};

#endif

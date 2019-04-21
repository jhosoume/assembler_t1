#ifndef PARSER
#define PARSER

#include <string>
#include <vector>

#include "helper.hpp"
#include "Token.hpp"
#include "TokenType.hpp"

using ::std::string;
using ::std::vector;

class Parser {
public:
  Parser();
  ~Parser() {}

  // Split into Different tokens
  static vector<string> splitIntoTokens(string);
  // Classify each token
  static TokenType classifyToken(string);
};

#endif

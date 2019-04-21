#ifndef PARSER
#define PARSER

#include <string>
#include <vector>
#include <set>
#include <algorithm>

#include "helper.hpp"
#include "TokenType.hpp"
#include "Token.hpp"

using ::std::string;
using ::std::vector;
using ::std::set;

class Parser {
public:
  Parser();
  ~Parser() {}

  // Split into Different tokens
  static vector<Token> splitIntoTokens(string);
  // Classify each token
  static TokenType classifyToken(string);
private:
  set<char> validCharacters;
  set<char> validFirstCharacters;

};

#endif

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
  // Split into Different tokens
  vector<Token> splitIntoTokens(string);
  // Classify each token
  TokenType classifyToken(string);
  bool isTokenValid(string);

private:
  bool checkValidNumberOfChars(string);
  bool checkIfSymbolStartsCorrectly(string);
  bool checkIfAllCharactersAreValid(string);

  set<char> validCharacters;
  set<char> validFirstCharacters;


};

#endif

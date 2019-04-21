#include "Parser.hpp"

vector<string> Parser::splitIntoTokens(string line) {
  string delimiters = "\t   ";
  vector<string> line_words = split(line, delimiters);
  return line_words;
}
TokenType Parser::classifyToken(string) {
  return TokenType::SYMBOL;
}

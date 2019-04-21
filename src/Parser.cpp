#include "Parser.hpp"

Parser::Parser() {
  const string tmp_letters = "ABCDEFGHIJKLMNOPQRSTUVXWYZ";
  const string tmp_numbers = "0123456789";
  const string tmp_specials = "_";
  for (auto character : tmp_letters) {
    validCharacters.insert(character);
    validFirstCharacters.insert(character);
  }
  for (auto character : tmp_numbers) {
    validCharacters.insert(character);
  }
  for (auto character : tmp_specials) {
    validCharacters.insert(character);
    validFirstCharacters.insert(character);
  }
}

vector<Token> Parser::splitIntoTokens(string line) {
  string delimiters = "\t   ";
  vector<Token> tokens;
  vector<string> line_words = split(line, delimiters);
  for (auto word : line_words) {
    std::transform(word.begin(), word.end(), word.begin(), ::toupper);
    tokens.push_back(Token(word, classifyToken(word)));
  }
  return tokens;
}
TokenType Parser::classifyToken(string) {
  return TokenType::SYMBOL;
}

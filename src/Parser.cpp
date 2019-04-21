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

// Receives a line and separates it into tokens, returning a vector of all
// the tokens in the line, classiying them and checking if they are valid
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


TokenType Parser::classifyToken(string token) {
  if (token.compare("") == 0) {
      return TokenType::EMPTY;
  } else if (token.compare(" ") == 0) {
      return TokenType::EMPTY;
  } else if (token.compare("\t") == 0) {
      return TokenType::EMPTY;
  } else if (token.compare("\n") == 0) {
      return TokenType::EMPTY;
  } else if (token.compare(" ") == 0) {
      return TokenType::EMPTY;
  } else if (token.compare(" ") == 0) {
      return TokenType::EMPTY;
  } else if (token.compare(";") == 0) {
      return TokenType::COMMENT_SEMICOLON;
  } else if (token.compare(":") == 0) {
      return TokenType::LABEL_COLON;
  } else if (token.compare("MACRO") == 0) {
      return TokenType::MACRO;
  } else if (token.compare(",") == 0) {
      return TokenType::COMMA_ARG_SEPARATOR;
  } else if (token.at(0) == '&') {
      return TokenType::MACRO_PARAMETER;
  } else if (token.compare("+") == 0) {
      return TokenType::ADD_SYMBOL;
  }
  return TokenType::SYMBOL;
}

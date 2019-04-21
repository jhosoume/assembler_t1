#ifndef TOKEN
#define TOKEN

#include <string>

using ::std::string;

enum class TOKEN_TYPE {
  INVALID,            // Any characther that is not considered permited by the language
  NUMBER_DECIMAL,     // Number in decimal
  NUMBER_HEX,         // Number in hex
  SYMBOL,             // Any name as variables (labels)
  LABEL_COLON,        // Colon that separates label from definition
  MACRO,              // Macro definition
  DIRECTIVE,
  INSTRUCTION,
  COMMENT_SEMICOLON,
  COMMA_ARG_SEPARATOR,
  MACRO_PARAMETER,
  ADD_SYMBOL,         // + sign, utilized for vectors
  EMPTY               // spaces or empty lines
};

class Token {
public:
  Token(string);
  ~Token() {}
  string  value;
  TOKEN_TYPE type;
  bool valid;

private:
  TOKEN_TYPE classifyToken();
  bool isValid();
};

#endif

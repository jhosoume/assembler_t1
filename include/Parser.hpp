#ifndef PARSER
#define PARSER

#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>

#include "helper.hpp"
#include "TokenType.hpp"
#include "Token.hpp"
#include "InstructionTable.hpp"
#include "DirectiveTable.hpp"
#include "Program.hpp"

using ::std::string;
using ::std::vector;
using ::std::set;

class Parser {
public:
  Parser(const InstructionTable &, const DirectiveTable &);
  bool isExpressionValid(const vector <Token> &);

private:
  InstructionTable instruction_table;
  DirectiveTable directive_table;

};

#endif

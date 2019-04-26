#ifndef PROGRAM
#define PROGRAM

#include <string>
#include <map>
#include <vector>

#include "Token.hpp"
#include "SymbolTable.hpp"

using ::std::string;
using ::std::map;
using ::std::vector;

class Program {
public:
  Program();
  Program(int, vector< vector <Token> >);

  int num_lines;
  std::vector< std::vector<Token> > tokens;

};

#endif

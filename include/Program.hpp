#ifndef PROGRAM
#define PROGRAM

#include <string>
#include <map>
#include <vector>

#include "Token.hpp"
#include "SymbolTable.hpp"
#include "helper.hpp"

using ::std::string;
using ::std::map;
using ::std::vector;

class Program {
public:
  Program();

  void showTokenswithType();
  void showTokens();

  int num_lines;
  std::vector< std::vector<Token> > tokens;

};

#endif

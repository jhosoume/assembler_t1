#ifndef SECONDP
#define SECONDP

#include <iostream>
#include <string>
#include <fstream>

#include "Parser.hpp"
#include "Program.hpp"
#include "SymbolTable.hpp"
#include "Token.hpp"

using ::std::string;
using ::std::cout;
using ::std::endl;

class SecondPass {
public:
  SecondPass(const Parser &, const Program &, const SymbolTable &);
  void exec();

private:
  Parser parser;
  Program program;
  SymbolTable symbol_table;
};


#endif

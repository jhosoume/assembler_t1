#ifndef FIRSTP
#define FIRSTP

#include <iostream>
#include <string>

#include "Parser.hpp"
#include "Program.hpp"
#include "SymbolTable.hpp"

using ::std::string;
using ::std::cout;
using ::std::endl;

class FirstPass {
public:
  FirstPass(const Parser &, const Program &);
  SymbolTable exec();

private:
  Parser parser;
  Program program;
  bool text_section;
  bool data_section;
};


#endif

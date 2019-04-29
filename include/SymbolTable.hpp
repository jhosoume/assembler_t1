#ifndef SYMBOLTABLE
#define SYMBOLTABLE

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>


#include "Token.hpp"

using ::std::string;
using ::std::map;
using ::std::pair;
using ::std::cout;
using ::std::endl;
using ::std::pair;

class SymbolTable {
public:
  bool isSymbolDefined(const Token &);
  bool isSymbolDefined(const string &);

  int getSymbolAddress(const Token &);
  int getSymbolAddress(const string &);

  void addSymbol(string, int);
  void addSymbol(Token, int);

  void listTable();

private:
  map<string, int> definitions;
};

#endif

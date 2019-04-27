#ifndef SYMBOLTABLE
#define SYMBOLTABLE

#include <string>
#include <map>
#include <algorithm>
#include <cctype>


#include "Token.hpp"

using ::std::string;
using ::std::map;
using ::std::pair;

class SymbolTable {
public:
  bool isSymbolDefined(Token);
  bool isSymbolDefined(string);
  int getSymbolAddress(Token);
  int getSymbolAddress(string);
  void listTable();

private:
  map<string, int> definitions;
};

#endif

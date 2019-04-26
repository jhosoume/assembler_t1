#ifndef DIRECTIVET
#define DIRECTIVET

#include <string>
#include <map>
#include <vector>

#include "Directive.hpp"
#include "TokenType.hpp"
#include "helper.hpp"

using ::std::string;
using ::std::map;
using ::std::pair;

class DirectiveTable {
public:
  DirectiveTable();
  void printDirectives();

  map<string, Directive> directives;

};

#endif

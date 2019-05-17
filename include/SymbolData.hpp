#ifndef SYMBOLDATA
#define SYMBOLDATA

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

enum class Section {
  DATA,
  TEXT,
  PP_DIR // Pre processment directives
}


class SymbolData {
public:
  int address;
  int value = 0;
  Section section;


};

#endif

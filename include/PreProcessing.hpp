#ifndef PRE
#define PRE

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <list>
#include <set>
#include <vector>

#include "helper.hpp"
#include "Program.hpp"

using ::std::string;
using ::std::cout;
using ::std::endl;
using ::std::for_each;
using ::std::list;
using ::std::set;

class PreProcessor {
public:
  PreProcessor(File);
  void exec();

  ~PreProcessor() {}

private:
  File input_file;
  // Create space between tokens
  string spaceTokens(string);
  set<char> validSpecialCharacters;
};


#endif

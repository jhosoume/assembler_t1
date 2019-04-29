#ifndef PRE
#define PRE

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <list>
#include <set>
#include <vector>
#include <cctype>

#include "helper.hpp"
#include "Program.hpp"
#include "Scanner.hpp"

using ::std::string;
using ::std::cout;
using ::std::endl;
using ::std::for_each;
using ::std::list;
using ::std::set;

class PreProcessor {
public:
  PreProcessor(const File &, const Scanner &, Program &);
  void exec();
  void writePreProcessedFile();

private:
  File input_file;
  Scanner scanner;
  Program &program;
  // Show program
  // Valid Characters that are used as tokens
  set<char> validSpecialCharacters;
  // Create space between tokens
  string spaceTokens(string);
  // Remove lines with comments
  string removeComments(string);
};


#endif

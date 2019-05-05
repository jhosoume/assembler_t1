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
#include "Parser.hpp"
#include "EquTable.hpp"

using ::std::string;
using ::std::cout;
using ::std::endl;
using ::std::for_each;
using ::std::list;
using ::std::set;
using ::std::vector;

class PreProcessor {
public:
  PreProcessor(const Scanner &, const Parser &, Program &);
  void exec();
  void writePreProcessedFile();
  void dealingWithEqu(vector<Token>);

private:
  Scanner scanner;
  Parser parser;
  Program &program;
  EquTable equ_table;
  // Show program
  // Valid Characters that are used as tokens
  set<char> validSpecialCharacters;
  // Create space between tokens
  string spaceTokens(string);
  // Remove lines with comments
  string removeComments(string);
};


#endif

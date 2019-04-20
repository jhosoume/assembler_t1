#ifndef PRE
#define PRE

#include <iostream>
#include <string>
#include <fstream>
#include "helper.hpp"

using ::std::string;
using ::std::cout;
using ::std::endl;

class PreProcessor {
public:
  PreProcessor(File);
  void exec();

  ~PreProcessor() {}

private:
  File input_file;
  // Create space between tokens
  string spaceTokens(string);
};


#endif

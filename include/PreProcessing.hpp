#ifndef PRE
#define PRE

#include <iostream>
#include <string>
#include <fstream>
#include "helper.hpp"

class PreProcessor {
public:
  PreProcessor(File);
  void exec();

  ~PreProcessor() {}

private:
  File input_file;
};


#endif

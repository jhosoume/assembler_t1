#ifndef HELPER
#define HELPER

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

struct file_t {
  std::string filename;
  std::string extension;
};

void helpMessage();
void invalidArgumentMessage();
file_t getFileNameFromArg(int, char **);

#endif

#ifndef HELPER
#define HELPER

#include <iostream>
#include <string>
#include <cstring>

using ::std::string;

class File {
public:
  File(char *);
  string fullname();
  string extension();
  string name();
private:
  std::string filename;
  std::string ext;
};

void helpMessage();
void invalidArgumentMessage();
File getFileNameFromArg(int, char **);

#endif

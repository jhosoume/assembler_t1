#include "helper.hpp"

void helpMessage() {
  std::cout <<  "Usage: tradutor FILE..." << std::endl;
  std::cout <<  "Assembles FILE into a pre-processed text file (.pre) with the same \
    name as the original file and an object text file (.obj). All files will be \
    saved in the current directory." << std::endl;
}

void noFileMessage() {
  std::cout << "[ERR] FILE was not specified. Must be path plus filename and its extension." << std::endl;
}
void invalidArgumentMessage() {
  std::cout << "[ERR] FILE was not correctly specified." << std::endl;
}

File::File(char *file) {
  // Separates filename from its extension
  bool ext_bool = false;
  for (unsigned int indx = 0; indx < strlen(file); ++indx) {
    if (file[indx] == '.') {
      ext_bool = true;
      continue;
    }
    ext_bool ? ext.push_back(file[indx]) :
               filename.push_back(file[indx]);
  }
}

File getFileNameFromArg(int argc, char **argv) {
  // Check if number of inputs is correct, should have one argument
  if (argc < 2) {
    noFileMessage();
    helpMessage();
    exit(1);
  } else if (argc > 2) {
    invalidArgumentMessage();
    helpMessage();
    exit(1);
  }
  File file = File(argv[1]);
  return file;
}

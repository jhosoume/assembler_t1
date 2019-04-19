#include "helper.hpp"

void helpMessage() {
  std::cout <<  "Usage: tradutor FILE..." << std::endl;
  std::cout <<  "Assembles FILE into a pre-processed text file (.pre) with the same \
    name as the original file and an object text file (.obj). All files will be \
    saved in the current directory." << std::endl;
}

void invalidArgumentMessage() {
  std::cout << "[ERR] FILE was not specified. Must be path plus filename and its extension" << std::endl;
}

file_t getFileNameFromArg(int argc, char **argv) {
  // Check if number of inputs is correct, should have one argument
  if (argc != 2) {
    helpMessage();
    exit(1);
  }
  file_t file;
  for (unsigned int indx = 0, ext = 0; indx < strlen(argv[1]); ++indx) {
    if (argv[1][indx] == '.') {
      ext = 1;
      continue;
    }
    ext ? file.extension.push_back(argv[1][indx]) :
          file.filename.push_back(argv[1][indx]);
  }
  return file;
}

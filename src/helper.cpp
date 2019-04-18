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

std::string getFileNameFromArg(int argc, char **argv) {
  std::cout << argc << " " << argv << std::endl;
  return (std::string) argv;
}

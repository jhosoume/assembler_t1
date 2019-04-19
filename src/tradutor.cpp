#include "assembler.hpp"

int main(int argc, char **argv) {
  // Get file to be assembled
  File input_file = getFileNameFromArg(argc, argv);
  PreProcessor zero_run = PreProcessor(input_file);
  zero_run.exec();
  return 0;
}

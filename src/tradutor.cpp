#include "assembler.hpp"

int main(int argc, char **argv) {
  Parser parser = Parser();
  // Get file to be assembled
  File input_file = getFileNameFromArg(argc, argv);
  PreProcessor zero_run = PreProcessor(input_file, parser);
  InstructionTable instruction_table;
  instruction_table.printInstructions();
  DirectiveTable directive_table;
  directive_table.printDirectives();
  // zero_run.exec();
  return 0;
}

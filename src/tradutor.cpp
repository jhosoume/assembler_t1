#include "assembler.hpp"

int main(int argc, char **argv) {
  InstructionTable instruction_table = InstructionTable();
  DirectiveTable directive_table = DirectiveTable();
  Parser parser = Parser(instruction_table, directive_table);
  // Get file to be assembled
  File input_file = getFileNameFromArg(argc, argv);
  PreProcessor zero_run = PreProcessor(input_file, parser);
  // instruction_table.printInstructions();
  // directive_table.printDirectives();
  zero_run.exec();
  return 0;
}

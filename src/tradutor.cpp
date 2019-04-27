#include "assembler.hpp"

int main(int argc, char **argv) {
  Program prog = Program();
  InstructionTable instruction_table = InstructionTable();
  DirectiveTable directive_table = DirectiveTable();
  Parser parser = Parser(instruction_table, directive_table);
  // Get file to be assembled
  File input_file = getFileNameFromArg(argc, argv);
  PreProcessor zero_run = PreProcessor(input_file, parser, prog);
  // instruction_table.printInstructions();
  // directive_table.printDirectives();
  zero_run.exec();
  prog.showTokens();
  zero_run.writePreProcessedFile();
  return 0;
}

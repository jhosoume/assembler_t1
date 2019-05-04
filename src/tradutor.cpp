#include "assembler.hpp"

int main(int argc, char **argv) {
  InstructionTable instruction_table = InstructionTable();
  DirectiveTable directive_table = DirectiveTable();
  Scanner scanner = Scanner(instruction_table, directive_table);
  Parser parser = Parser(instruction_table, directive_table);
  // Get file to be assembled
  File input_file = getFileNameFromArg(argc, argv);
  Program prog = Program(input_file);
  PreProcessor zero_run = PreProcessor(scanner, prog);
  // instruction_table.printInstructions();
  // directive_table.printDirectives();
  zero_run.exec();
  // prog.showTokens();
  zero_run.writePreProcessedFile();
  FirstPass first_pass = FirstPass(parser, prog);
  SymbolTable symbol_table = first_pass.exec();
  SecondPass second_pass = SecondPass(parser,
                                      prog,
                                      symbol_table,
                                      instruction_table,
                                      directive_table);
  prog.showTokens();
  second_pass.exec();
  return 0;
}

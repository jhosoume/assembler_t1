#include "SecondPass.hpp"

SecondPass::SecondPass(const Parser &parser,
                       const Program &prog,
                       const SymbolTable &sbt,
                       const InstructionTable &inst_table,
                       const DirectiveTable &dir_table
                      )
  : parser{parser}, program{prog}, symbol_table{sbt}, instruction_table{inst_table},
    directive_table{dir_table}
  {}

void SecondPass::exec() {
  // Open file for writing the object file
  vector<Token> tokens;
  for (unsigned int line = 0; line < program.tokens.size(); ++line) {
    cout << line << " ";
    tokens = program.tokens.at(line);
    if (parser.hasLabel(tokens)) {
      tokens.assign(tokens.begin() + 2, tokens.end());
    }
    if (tokens.at(0).type == TokenType::INSTRUCTION_TOKEN) {
      exec_code.push_back(instruction_table.get(tokens.at(0)).op_code);
      cout << exec_code.back() << " ";
    }
    cout << endl;
  }
}

void SecondPass::writeObjectFile() {
  std::ofstream object_file;
  object_file.open(program.file.name() + ".obj");
  object_file.close();
}

void SecondPass::showObjectCode() {
    for (auto code : exec_code) {
      cout << code << " ";
    }
    cout << endl;
}

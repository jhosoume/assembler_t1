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
  int operand;
  for (unsigned int line = 0; line < program.tokens.size(); ++line) {
    cout << line << " ";
    tokens = program.tokens.at(line);
    if (parser.hasLabel(tokens)) {
      tokens.assign(tokens.begin() + 2, tokens.end());
    }
    if (tokens.at(0).type == TokenType::INSTRUCTION_TOKEN) {
      // If instruction, needs to add opcode then deal with operands
      exec_code.push_back(instruction_table.get(tokens.at(0)).op_code);
      cout << exec_code.back() << " ";
      parser.groupOps(program.tokens.at(line));
      // Check if has sum in line (Add in parse)
    } else if (tokens.at(0).tvalue == "CONST") {
      // If const, only add number to be in memory
      exec_code.push_back(std::stoi( tokens.back().tvalue) );
      cout << exec_code.back() << " ";
    } else if (tokens.at(0).tvalue == "SPACE") {
      // If space, add zeros to memory
      if (tokens.back().type == TokenType::NUMBER_DECIMAL) {
        for (int num_zeros = 0; num_zeros < std::stoi(tokens.back().tvalue); ++num_zeros) {
          exec_code.push_back(0);
          cout << exec_code.back() << " ";
        }
      } else {
        exec_code.push_back(0);
        cout << exec_code.back() << " ";
      }
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

#ifndef INSTRUCTIONT
#define INSTRUCTIONT

#include <string>
#include <map>
#include <vector>

#include "Instruction.hpp"
#include "TokenType.hpp"
#include "helper.hpp"

using ::std::string;
using ::std::map;
using ::std::pair;

class InstructionTable {
public:
  InstructionTable();
  void printInstructions();

private:
  map<string, Instruction> instructions;

};

#endif

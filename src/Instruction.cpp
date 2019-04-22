#include "Instruction.hpp"

Instruction::Instruction(string name, int n_op, int op_code, int size)
  : name{name}, num_operands{n_op}, op_code{op_code}, size{size}
  {}

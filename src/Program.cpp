#include "Program.hpp"

Program::Program()
  : num_lines{0}
  {}

Program::Program(int n_lines, vector < vector<Token> > tokens)
  : num_lines{n_lines}, tokens{tokens}
  {}

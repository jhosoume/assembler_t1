#include "Macro.hpp"

Macro::Macro(string name)
  : name{name} {}

int Macro::getNumOperands() {
  return operands_names.size();
}

void Macro::addOperand(string name) {
  operands_names.push_back(name);
}

void Macro::addOperandPosition(string name, int line, int indx) {
  Position macro_position;
  macro_position.line = line; macro_position.indx = indx;
  operands_positions[name].push_back(macro_position);
}

void Macro::addMacroLines(vector<Token> line_tokens) {
  macro_definition.push_back(line_tokens);
}

vector <Token> Macro::macroLineWithSubstitions(vector <Token> line_tokens) {
  //TODO
  return line_tokens;
}

#include "InstructionTable.hpp"

InstructionTable::InstructionTable() {
  instructions.insert( pair<string, Instruction>( "ADD",
                                                  Instruction("ADD", 1, 1, 2) ) );
  vector<TokenType> signature;
  signature.push_back(TokenType::INSTRUCTION_TOKEN);
  signature.push_back(TokenType::SYMBOL);
  instructions.at("ADD").signatures.push_back(signature);
  signature.clear();
  signature.push_back(TokenType::INSTRUCTION_TOKEN);
  signature.push_back(TokenType::SYMBOL);
  signature.push_back(TokenType::ADD_SYMBOL);
  signature.push_back(TokenType::NUMBER_DECIMAL);
  instructions.at("ADD").signatures.push_back(signature);
  instructions.insert( pair<string, Instruction>( "SUB",
                                                  Instruction("SUB", 1, 1, 2) ) );
}

// Print all possible signtures of all instructions
void InstructionTable::printInstructions() {
  for (const auto &pair_instruction : instructions) {
    Instruction instruction = pair_instruction.second;
    cout << "Instruction: " << instruction.name << endl;
    cout << "   Signatures: " << endl;
    for (auto signature : instruction.signatures) {
      cout << "       ";
      for (TokenType toktype : signature) {
        cout << TokenTypeToString(toktype) << " ";
      }
      cout << endl;
    }

  }

}

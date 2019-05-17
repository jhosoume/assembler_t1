#include "SymbolTable.hpp"

bool SymbolTable::isSymbolDefined(const Token &symbol) {
  return isSymbolDefined(symbol.tvalue);
}

bool SymbolTable::isSymbolDefined(const string &symbol) {
  return (definitions.count(symbol) != 0);
}

int SymbolTable::getSymbolAddress(const Token &symbol) {
  return getSymbolAddress(symbol.tvalue);
}

int SymbolTable::getSymbolAddress(const string &symbol) {
  return definitions.at(symbol).address;
}

void SymbolTable::addSymbol(string symbol, int addr, SymbolType s_type, int value, int vec_size) {
  SymbolData s_data = SymbolData(addr, value, s_type, vec_size);
  if ( isSymbolDefined(symbol) ) {
    cout << "[ERR] Symbol is being redefined!" << endl;
  }
  definitions.insert(pair <string, SymbolData> (symbol, s_data));
}

void SymbolTable::addSymbol(Token token, int addr) {
  addSymbol(token.tvalue, addr);
}

void SymbolTable::addSymbol(string symbol, int addr) {
  addSymbol(symbol, addr, SymbolType::INSTRUCTION, 0, 0);
}

void SymbolTable::listTable() {
  cout << "Listing Symbol Table" << endl;
  cout << "LABEL: Address" << endl;
  for (const auto &pair_symbol : definitions) {
    cout << pair_symbol.first << ": " << pair_symbol.second.address << " "
      << SymbolTypeToString(pair_symbol.second.symbol_type) << " " << pair_symbol.second.value
      << " "<< pair_symbol.second.vector_size << endl;
  }
}

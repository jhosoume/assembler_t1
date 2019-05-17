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

void SymbolTable::addSymbol(string symbol, int addr, Token main_token, int value, int vec_size) {
  SymbolData s_data = SymbolData(addr);
  if ( isSymbolDefined(symbol) ) {
    cout << "[ERR] Symbol is being redefined!" << endl;
  }
  definitions.insert(pair <string, SymbolData> (symbol, s_data));
}

void SymbolTable::addSymbol(Token token, int addr) {
  addSymbol(token.tvalue, addr);
}

void SymbolTable::addSymbol(string symbol, int addr) {
  addSymbol(symbol, addr, Token(), 0, 0);
}










void SymbolTable::listTable() {
  cout << "Listing Symbol Table" << endl;
  cout << "LABEL: Address" << endl;
  for (const auto &pair_symbol : definitions) {
    cout << pair_symbol.first << ": " << pair_symbol.second.address << endl;
  }
}

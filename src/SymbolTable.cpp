#include "SymbolTable.hpp"

bool SymbolTable::isSymbolDefined(const Token &symbol) {
    return (definitions.count(symbol.tvalue) != 0);
}

bool SymbolTable::isSymbolDefined(const string &symbol) {
    return (definitions.count(symbol) != 0);
}

int SymbolTable::getSymbolAddress(const Token &symbol) {
  return definitions.at(symbol.tvalue);
}

int SymbolTable::getSymbolAddress(const string &symbol) {
  return definitions.at(symbol);
}

void SymbolTable::addSymbol(string symbol, int addr) {
  definitions.insert(pair <string, int> (symbol, addr));
}

void SymbolTable::addSymbol(Token token, int addr) {
  definitions.insert(pair <string, int> (token.tvalue, addr));
}

void SymbolTable::listTable() {
  cout << "Listing Symbol Table" << endl;
  cout << "LABEL: Address" << endl;
  for (const auto &pair_symbol : definitions) {
    cout << pair_symbol.first << ": " << pair_symbol.second << endl;
  }
}

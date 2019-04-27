#include "SymbolTable.hpp"

bool SymbolTable::isSymbolDefined(Token symbol) {
    return (definitions.count(symbol.tvalue) != 0);
}

bool SymbolTable::isSymbolDefined(string symbol) {
    return (definitions.count(symbol) != 0);
}

int SymbolTable::getSymbolAddress(Token symbol) {
  return definitions.at(symbol.tvalue);
}

int SymbolTable::getSymbolAddress(string symbol) {
  return definitions.at(symbol);
}

void listTable() {

}

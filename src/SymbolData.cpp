#include "SymbolData.hpp"

SymbolData::SymbolData(int addr)
  : address{addr}, value{0}, symbol_type{SymbolType::INSTRUCTION}, vector_size{0}
  {}

SymbolData::SymbolData(int addr, SymbolType s_type)
  : address{addr}, value{0}, symbol_type{s_type}, vector_size{0}
  {}

SymbolData::SymbolData(int addr, int value, SymbolType s_type)
  : address{addr}, value{value}, symbol_type{s_type}, vector_size{0}
  {}

SymbolData::SymbolData(int addr, int value, SymbolType s_type, int v_size)
  : address{addr}, value{value}, symbol_type{s_type}, vector_size{v_size}
  {}

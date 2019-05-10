#include "MacroTable.hpp"

void MacroTable::printMacros() {
  //TODO
  for (const auto &pair_macro : macros) {
    Macro macro = pair_macro.second;
    cout << "Macro: " << macro.name << endl;
    // cout << "       Size: " << instruction.size << endl;
    // cout << " Signatures: " << endl;
    // for (auto signature : instruction.signatures) {
    //   cout << "       ";
    //   for (TokenType toktype : signature) {
    //     cout << TokenTypeToString(toktype) << " ";
    //   }
    // cout << endl;
    // }
  }
}

Macro MacroTable::get(const string &macro_name) {
  return macros.at(macro_name);
}

void MacroTable::insert(string macro_name, Macro macro) {
  macros.insert(pair<string, Macro>(macro_name, macro));
}

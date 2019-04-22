#include "DirectiveTable.hpp"

DirectiveTable::DirectiveTable() {
  vector<TokenType> signature;
  // CONST _________________________________________________________
  directives.insert( pair<string, Directive>( "CONST", Directive("CONST", 1, 1) ) );
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::NUMBER_DECIMAL);
  directives.at("CONST").signatures.push_back(signature);
  signature.clear();
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::NUMBER_HEX);
  directives.at("CONST").signatures.push_back(signature);
  signature.clear();
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::SYMBOL); //In case of EQU
  directives.at("CONST").signatures.push_back(signature);
  signature.clear();

  // SECTION _________________________________________________________
  directives.insert( pair<string, Directive>( "SECTION", Directive("SECTION", 1, 0) ) );
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::DATA_SECTION);
  directives.at("SECTION").signatures.push_back(signature);
  signature.clear();
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::TEXT_SECTION);
  directives.at("SECTION").signatures.push_back(signature);
  signature.clear();

  // SPACE _________________________________________________________
  // TODO! Check, space has variable size, depending on number
  directives.insert( pair<string, Directive>( "SPACE", Directive("SPACE", 1, -1) ) );
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  directives.at("SPACE").signatures.push_back(signature);
  signature.clear();
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::NUMBER_DECIMAL);
  directives.at("SPACE").signatures.push_back(signature);
  signature.clear();
  // signature.push_back(TokenType::DIRECTIVE_TOKEN);
  // signature.push_back(TokenType::NUMBER_HEX);
  // directives.at("SPACE").signatures.push_back(signature);
  // signature.clear();
  // signature.push_back(TokenType::DIRECTIVE_TOKEN);
  // signature.push_back(TokenType::SYMBOL);
  // directives.at("SPACE").signatures.push_back(signature);
  // signature.clear();

  // EQU _________________________________________________________
  directives.insert( pair<string, Directive>( "EQU", Directive("EQU", 1, 0) ) );
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::NUMBER_DECIMAL);
  directives.at("EQU").signatures.push_back(signature);
  signature.clear();
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::NUMBER_HEX);
  directives.at("EQU").signatures.push_back(signature);
  signature.clear();
  // signature.push_back(TokenType::DIRECTIVE_TOKEN);
  // signature.push_back(TokenType::SYMBOL); //In case it refers to another EQU for some reason
  // directives.at("EQU").signatures.push_back(signature);
  // signature.clear();

  // IF _________________________________________________________
  directives.insert( pair<string, Directive>( "IF", Directive("IF", 1, 0) ) );
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::SYMBOL);
  directives.at("IF").signatures.push_back(signature);
  signature.clear();
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::NUMBER_DECIMAL);
  directives.at("IF").signatures.push_back(signature);
  signature.clear();

  // MACRO _________________________________________________________
  directives.insert( pair<string, Directive>( "MACRO", Directive("MACRO", 0, 0) ) );
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  directives.at("MACRO").signatures.push_back(signature);
  signature.clear();

  // ENDMACRO  _________________________________________________________
  directives.insert( pair<string, Directive>( "ENDMACRO", Directive("ENDMACRO", 0, 0) ) );
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  directives.at("ENDMACRO").signatures.push_back(signature);
  signature.clear();

}

// Print all possible signtures of all directives
void DirectiveTable::printDirectives() {
  for (const auto &pair_directive : directives) {
    Directive directive = pair_directive.second;
    cout << " Directive: " << directive.name << endl;
    cout << "   Signatures: " << endl;
    cout << "         Size: " << directive.size << endl;
    for (auto signature : directive.signatures) {
      cout << "       ";
      for (TokenType toktype : signature) {
        cout << TokenTypeToString(toktype) << " ";
      }
      cout << endl;
    }

  }

}

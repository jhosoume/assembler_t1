#include "DirectiveTable.hpp"

DirectiveTable::DirectiveTable() {
  vector<TokenType> signature;
  directives.insert( pair<string, Directive>( "CONST", Directive("CONST", 1) ) );
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

  directives.insert( pair<string, Directive>( "SECTION", Directive("SECTION", 1) ) );
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::DATA_SECTION);
  directives.at("SECTION").signatures.push_back(signature);
  signature.clear();
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::TEXT_SECTION);
  directives.at("SECTION").signatures.push_back(signature);
  signature.clear();

  directives.insert( pair<string, Directive>( "SPACE", Directive("SPACE", 1) ) );
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::EMPTY);
  directives.at("SPACE").signatures.push_back(signature);
  signature.clear();
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::NUMBER_DECIMAL);
  directives.at("SPACE").signatures.push_back(signature);
  signature.clear();
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::NUMBER_HEX);
  directives.at("SPACE").signatures.push_back(signature);
  signature.clear();
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::SYMBOL);
  directives.at("SPACE").signatures.push_back(signature);
  signature.clear();

  directives.insert( pair<string, Directive>( "EQU", Directive("EQU", 1) ) );
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::NUMBER_DECIMAL);
  directives.at("EQU").signatures.push_back(signature);
  signature.clear();
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::NUMBER_HEX);
  directives.at("EQU").signatures.push_back(signature);
  signature.clear();
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::SYMBOL); //In case it refers to another EQU for some reason
  directives.at("EQU").signatures.push_back(signature);
  signature.clear();

  directives.insert( pair<string, Directive>( "IF", Directive("IF", 1) ) );
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  signature.push_back(TokenType::SYMBOL);
  directives.at("IF").signatures.push_back(signature);
  signature.clear();

  directives.insert( pair<string, Directive>( "MACRO", Directive("MACRO", 0) ) );
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  directives.at("MACRO").signatures.push_back(signature);
  signature.clear();

  directives.insert( pair<string, Directive>( "END", Directive("END", 0) ) );
  signature.push_back(TokenType::DIRECTIVE_TOKEN);
  directives.at("END").signatures.push_back(signature);
  signature.clear();

}

// Print all possible signtures of all directives
void DirectiveTable::printDirectives() {
  for (const auto &pair_directive : directives) {
    Directive directive = pair_directive.second;
    cout << "Directive: " << directive.name << endl;
    cout << "   Signatures: " << endl;
    for (auto signature : directive.signatures) {
      cout << "       ";
      for (TokenType toktype : signature) {
        cout << TokenTypeToString(toktype) << " ";
      }
      cout << endl;
    }

  }

}

#include "../include/Usuário.hpp"


// Setters
void Usuario::setNome(std::string _name) {this->name = _name;}
void Usuario::setCodigo(int cod) {this->code = cod;}
// Getters
std::string Usuario::getNome() {return this->name;}
int Usuario::getCodigo() {return this->code;}
#include "../include/Usuário.hpp"


// Setters
void Usuario::setNome(std::string _name) {this->nome = _name;}
void Usuario::setCodigo(int cod) {this->codigo = cod;}
// Getters
std::string Usuario::getNome() {return this->nome;}
int Usuario::getCodigo() {return this->codigo;}
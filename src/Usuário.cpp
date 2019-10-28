#include "../include/Usuário.hpp"
Usuario::Usuario(std::string _come, int _codigo) {
    this->setNome(_come);
    this->setCodigo(_codigo);
}
Usuario::Usuario() {}
Usuario::~Usuario() {}

void Usuario::printarNoArquivo(std::ofstream &outfile) {
    if(!outfile.is_open()) {
        std::cerr << "Erro de I/O" << std::endl;
        exit(1);
    }

    outfile << this->getCodigo() << ';' << this->getNome() << '\n';
}

void Usuario::printInfo() {
    std::cout << "Nome: " << this->getNome() << "\nCodigo: " << this->getCodigo() << std::endl;
}


// Setters
void Usuario::setNome(std::string _name)    {this->nome = _name;}
void Usuario::setCodigo(int cod)            {this->codigo = cod;}
// Getters
std::string Usuario::getNome()  {return this->nome;}
int Usuario::getCodigo()        {return this->codigo;}
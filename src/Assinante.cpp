#include "Assinante.hpp"

// Constructor
Assinante::Assinante() {}
Assinante::Assinante(std::string name, int codigo) {
    this->setNome(name);
    this->setCodigo(codigo);
}
// Destructor
Assinante::~Assinante() {

}

// Functions
void Assinante::printFavoritos() {
    std::list<Midia*>::iterator it;
    for(it = this->favoritos.begin(); it != this->favoritos.end(); it++){
        (*it)->printInfoProduto();
    }
}

void Assinante::insertFavorito(Midia* favorito) {
    this->favoritos.push_back(favorito);
}

void Assinante::removeFavorito(Midia* favorito) {
    this->favoritos.remove(favorito);
}

// Getters
std::list<Midia*> Assinante::getFavoritos() {return this->favoritos;}

// Arquivo TODO:
void Assinante::printarNoArquivo(std::ofstream &_outfile){}
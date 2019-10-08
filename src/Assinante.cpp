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
    std::list<Midia*>::iterator aux;
    for(aux = this->favoritos.begin(); aux != this->favoritos.end(); aux++){
        (*aux)->imprimeInfoProduto();
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
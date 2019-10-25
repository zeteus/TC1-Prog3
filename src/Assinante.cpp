#include "Assinante.hpp"

// Constructor
Assinante::Assinante() {}
Assinante::Assinante(std::string name, int codigo) : Usuario(name, codigo) {}
// Destructor
Assinante::~Assinante() {

}

// Functions
void Assinante::printFavoritos() {
    for(Midia *it : this->getFavoritos()){
        it->printInfoProduto();
        std::cout << '-' << std::endl;
    }
}

void Assinante::inserirFavorito(Midia* favorito) {
    this->favoritos.insert(favorito);
}

void Assinante::removeFavorito(Midia* favorito) {
    this->favoritos.erase(favorito);
}

// Getters
std::set<Midia*> Assinante::getFavoritos() {return this->favoritos;}

// Arquivo TODO:
// Overloading
void Assinante::printarNoArquivo(std::ofstream &_outfile){}
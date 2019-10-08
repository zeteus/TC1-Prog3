#include "Assinante.hpp"

Assinante::Assinante() {}

Assinante::Assinante(std::string name, int codigo) {
    this->setNome(name);
    this->setCodigo(codigo);
}

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

// Setters
void Assinante::setDigitalPlatform(PlataformaDigital *plataforma) {this->plataforma = plataforma;}

// Getters
PlataformaDigital* Assinante::getPlataformaDigital() {return this->plataforma;}
std::list<Midia*> Assinante::getFavoritos() {return this->favoritos;}

// Arquivo TODO:
void Assinante::printarNoArquivo(std::ofstream &_outfile){}
void Assinante::loadFile(std::ifstream &_infile){}
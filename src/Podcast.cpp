#include "Podcast.hpp"

// Constructors
Podcast::Podcast() {}
Podcast::Podcast(std::string name, Genero* genre, int seasonsQnt) {
    this->setNome(name);
    this->setGenero(genre);
    this->setQtdTemporadas(seasonsQnt);
}
// Destrutor
Podcast::~Podcast() {}

// Setter
void Podcast::setQtdTemporadas(int _qnt) {this->quantidadeTemporadas = _qnt;}

// Getter
int Podcast::getQtdTemporadas() {return this->quantidadeTemporadas;}

// Overloading
void Podcast::printarNoArquivo(std::ofstream &_outfile){};
void Podcast::printProductInfo(){};
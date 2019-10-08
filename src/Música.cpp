#include "Música.hpp"

// Constructors
Musica::Musica() {}
Musica::Musica(std::string name, std::string genre, int duration, int yr) {
    this->setNome(name);
    this->setGenero(genre);
    this->setDuracao(duration);
    this->setAnoLancamento(yr);
}
// Destructor
Musica::~Musica() {}

// Functions
void Musica::formataDuracao() {
    // TODO
}
void Musica::addAlbum(Album *album) {
    this->albums.push_back(album);
}

// Overloading , TODO:
void Musica::printInfoProduto() {}
void Musica::printarNoArquivo(std::ofstream &_outfile){}
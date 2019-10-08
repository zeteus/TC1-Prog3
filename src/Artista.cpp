#include "Artista.hpp"

// Contructor
Artista::Artista(std::string name, int code) {
    this->setNome(name);
    this->setCodigo(code);
}
// Destructor
Artista::~Artista() {}

// Functions
void Artista::addAlbum(Album* album) {
    albums.push_back(album);
}

// Getters
std::list<Album*> Artista::getAlbums() {return this->albums;}

// Overloading TODO:
void Artista::printarNoArquivo(std::ofstream &_outfile) {}
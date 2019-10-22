#include "Música.hpp"

// Constructors
Musica::Musica() {}
Musica::Musica(std::string name, Genero* genre, int duration, int yr) : Midia(name, rand(), genre) {
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
void Musica::printInfoProduto() {
    std::cout << "Nome: " << this->getNome() << std::endl;
    std::cout << "Codigo: " << this->getCodigo() << std::endl;
    std::cout << "Genero: " <<  this->getGenero()->getNome() << std::endl;
    std::cout << "Duração: " << this->getDuracao() << std::endl;
    std::cout << "Ano de Lançamento: " << this->getAnoLancamento() << std::endl;
}

void Musica::printarNoArquivo(std::ofstream &_outfile) {}
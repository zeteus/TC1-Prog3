#include "Álbum.hpp"

// Constructor
Album::Album(Artista* _artist, int _duration, int _yearLaunch, int _musicAmount, std::string _name) {
    this->setArtist();
    this->setDuracao();
    this->setAnoLancamento();
    this->setQuantidadeMusicas();
    this->setNome();
}

Album::Album() {}

Album::~Album() {
    musics.clear(); //deleta todos os elementos da lista e libera o espaço da memória
                    //torna uma composição
}

// Overloading
void Album::printarNoArquivo(std::ofstream &_outfile) {
    _outfile << "ÁLBUM " << this->getNome() << std::endl;
    _outfile << "|DURACAO:" << this->getDuracao() << std::endl;
    _outfile << "|ANO DE LANCAMENTO:" << this->getAnoLancamento() << std::endl;
    _outfile << "|QTD MUSICAS:" << this->getQuantidadeMusicas() << std::endl;
    _outfile << "|ARTISTA:" << this->getArtist() << std::endl;
    _outfile << "______________________________________" << std::endl;
}

// Getters
Artista* Album::getArtista() {return this->artista;}
int Album::getDuracao() {return this->duration;}
int Album::getAnoLancamento() {return this->launchYear;}
int Album::getQuantidadeMusicas() {return this->musicAmount;}
std::string Album::getNome() {return this->name;}

// Setters
void Album::setArtista(Artista* _artist) {this->artista = _artist;}
void Album::setDuracao(int _duration) {this->duration = _duration;}
void Album::setAnoLancamento(int _launchYear) {this->launchYear = _launchYear;}
void Album::setQuantidadeMusicas(int _musicAmount) {this->musicAmount = _musicAmount;}
void Album::setNome(std::string _name) {this->name = _name;}
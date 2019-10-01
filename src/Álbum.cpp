#include "Álbum.hpp"

Album::Album(Artista* _artist, int _duration, int _yearLaunch, int _musicAmount, std::string _name) {
    
}

Album::Album() {}

Album::~Album() {
    musics.clear(); //deleta todos os elementos da lista e libera o espaço da memória
                    //torna uma composição
}

// Overloading
void Album::printOnFile(std::ofstream &_outfile) {
    _outfile << "ÁLBUM " << this->getName() << std::endl;
    _outfile << "|DURACAO:" << this->getDuration() << std::endl;
    _outfile << "|ANO DE LANCAMENTO:" << this->getLaunchYear() << std::endl;
    _outfile << "|QTD MUSICAS:" << this->getMusicAmount() << std::endl;
    _outfile << "|ARTISTA:" << this->getArtist() << std::endl;
    _outfile << "______________________________________" << std::endl;
}

    //Setters e getters
Artista* Album::getArtist() {
    return this->artist;
    }
int Album::getDuration() {
    return this->duration;
    }
int Album::getLaunchYear() {
    return this->launchYear;
    }
int Album::getMusicAmount() {
    return this->musicAmount;
    }
std::string Album::getName() {
    return this->name;
    }

void Album::setArtist(Artista* _artist) {
    this->artist = _artist;
    }
void Album::setDuration(int _duration) {
    this->duration = _duration;
    }
void Album::setLaunchYear(int _launchYear) {
    this->launchYear = _launchYear;
    }
void Album::setMusicAmount(int _musicAmount) {
    this->musicAmount = _musicAmount;
    }
void Album::setName(std::string _name) {
    this->name = _name;
    }
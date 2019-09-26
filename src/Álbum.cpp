#include <iostream>
#include <string>
#include "Álbum.hpp"

Album::Album(Artista* _artist, int _duration, int _yearLaunch, int _musicAmount, string _name) {
    Album::setName(_name);
    Album::setArtista(_artist);
    Album::setDuration(_duration);
    Album::setYearLaunch(_yearLaunch);
    Album::setMusicAmount(_musicAmount);
}

Album::Album() {

}

Album::~Album() {

}

Artist* Album::getArtista() {
    return *this->artist;
}

void Album::imprimeNoArquivo(ofstream &_outfile) {
    _outfile << "DURACAO:" << this->duration << endl;
    _outfile << "ANO DE LANCAMENTO:" << this->yearLaunch << endl;
    _outfile << "QTD MUSICAS:" << this->musicAmount << endl;
    _outfile << "NOME:" << this->name << endl;
    _outfile << "ARTISTA:" << *this->artist << endl;
    _outfile << "______________________________________" << endl;
}

int getDuration() {
    return this->duration;
}

int getYearLaunch() {
    return this->yearLaunch;
}

int getMusicAmount() {
    return this->musicAmount;
}

string getName() {
    return this->name;
}

void Album::setArtista(Artista* _artist) {
    this->artist = _artist;

void setDuration(int _duration) {
    this->artist = _duration;
}

void setYearLaunch(int _yearLaunch) {
    this->artist = _yearLaunch;
}

void setMusicAmount(int _musicAmount) {
    this->artist = _musicAmount;
}

void setName(string _name){
    this->artist = _name;
}
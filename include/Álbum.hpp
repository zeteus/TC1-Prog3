#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Artista.hpp"

using namespace std::string;
using namespace ios::ofstream;

class Album {

private:
    Artista* artist;
public:
    int duration;
    int yearLaunch;
    int musicAmount;
    string name;
    
    // Constructor
    Album(Artista* _artist);
    Album();
    // Destructor
    ~Album();

    // Functions
    void imprimeNoArquivo(ofstream &_outfile);

    // getters
    Artista* getArtista();
    int getDuration();
    int getYearLaunch();
    int getMusicAmount();
    string getName();
    // setters
    void setArtista(Artista* _artist);
    void setDuration(int _duration);
    void setYearLaunch(int _yearLaunch);
    void setMusicAmount(int _musicAmount);
    void setName(string _name);
};
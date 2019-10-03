#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "Artista.hpp"
#include "Música.hpp"

class Musica;
class Artista;  // forward declarations

class Album {

private:
    // Attributes
    std::string name;
    int duration;
    int launchYear;
    int musicAmount;

    // Relations
    Artista* artist;
    std::list<Musica*> musics;

    // Setters
    void setArtist(Artista* _artist);
    void setDuration(int _duration);
    void setLaunchYear(int _launchYear);
    void setMusicAmount(int _musicAmount);
    void setName(std::string _name);

public:    
    // Constructors
    Album(Artista* _artist, int _duration, int _yearLaunch, int _musicAmount, std::string _name);
    Album();
    // Destructor
    ~Album();

    // Getters
    Artista* getArtist();
    int getDuration();
    int getLaunchYear();
    int getMusicAmount();
    std::string getName();

    // Overloading
    void printOnFile(std::ofstream &_outfile);
};
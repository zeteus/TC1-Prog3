#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Artista.hpp"
#include "Música.hpp"

class Artista;  //evita include loop

class Album {

private:
    std::string name;
    int duration;
    int launchYear;
    int musicAmount;

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

    // Overloading, virtual para evitar chamar o da classe-mãe
    virtual void printOnFile(std::ofstream &_outfile);

    // Getters
    Artista* getArtist();
    int getDuration();
    int getLaunchYear();
    int getMusicAmount();
    std::string getName();

};
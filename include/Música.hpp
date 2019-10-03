#pragma once

#include <iostream>
#include <list>

#include "Mídia.hpp"
#include "Álbum.hpp"

class Album;    // Forward declaration

class Musica: public Midia {

private:
    // Attributes
    int duration;
    int launchYear;

    // Relation
    std::list<Album*> albums;

    // Fuctions
    void formatDuration();
    void addAlbum(Album* album);

    // Setters
    void setDuration(int duration);
    void setLaunchYear(int launchYear);

public:
    // Constructor
    Musica();
    Musica(std::string name, bool expl, std::string genre, int duration, int yr);
    // Destructor
    ~Musica();

    // Getters
    int getDuration();
    int getLaunchYear();

    // Overloading
    void printProductInfo();
    void printOnFile(std::ofstream &_outfile);
    void loadFile(std::ifstream &_infile);
};
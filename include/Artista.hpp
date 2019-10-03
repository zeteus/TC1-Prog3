#pragma once

#include "Produtor.hpp"
#include "Álbum.hpp"

#include <list>
#include <fstream>

class Album;    // forward declaration

class Artista: public Produtor {

private:
    // Relation
    std::list<Album*> albums;

public:
    // Constructor
    Artista(std::string name, int code);
    // Destructor
    ~Artista();

    // Functions
    void addAlbum();

    // Getters
    std::list<Album*> getAlbums();

    // Overloading
    void printOnFile(std::ofstream &_outfile);
    void loadFile(std::ifstream &_infile);
};
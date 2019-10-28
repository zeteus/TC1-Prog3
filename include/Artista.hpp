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

    // Functions
    void addAlbum(Album* album);

public:
    // Constructor
    Artista(std::string name, int code);
    // Destructor
    ~Artista();

    // Getters
    std::list<Album*> getAlbums();
};
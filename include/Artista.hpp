#pragma once
#include "Produtor.hpp"
#include "Álbum.hpp"
#include <list>
#include <fstream>

class Album;    // forward declaration

class Artista: public Produtor {

private:
    std::list<Album*> albums;
public:
    // Constructor
    Artista();
    // Destructor
    ~Artista();

    // Functions
    void addAlbum();

    // Getters
    std::list<Album*> getAlbums();

    // Overloading, virtual para evitar chamar o da classe-mãe
    virtual void printOnFile(std::ofstream &_outfile);
    virtual void loadFile(std::ifstream &_infile);
};
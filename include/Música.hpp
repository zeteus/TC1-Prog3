#pragma once

#include <iostream>
#include <list>

#include "Mídia.hpp"
#include "Álbum.hpp"

class Album;    // Forward declaration

class Musica: public Midia {

private:
    // Relation
    std::list<Album*> albums;

    // Fuctions
    void formataDuracao();
    void addAlbum(Album* album);

public:
    // Constructor
    Musica();
    Musica(std::string name, Genero* genre, int duration, int yr);
    // Destructor
    ~Musica();

    // Overloading
    void printInfoProduto();
    void printarNoArquivo(std::ofstream &_outfile);
};
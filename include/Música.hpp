#pragma once

#include <iostream>
#include <list>

#include "Mídia.hpp"
#include "Álbum.hpp"

class Album;    // Forward declaration

class Musica: public Midia {

private:
    // Relation
    Album* album;

public:
    // Constructor
    Musica();
    Musica(std::string name, int cod, Midia::Genero* genre, float duration, int yr);
    // Destructor
    ~Musica();
    void setAlbum(Album *a);
    Album* getAlbum();

    // Overloading
    void printInfoProduto();
    char getTipo();
    void printarNoArquivo(std::ofstream &_outfile);
};
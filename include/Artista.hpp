#pragma once
#include "Produtor.hpp"
#include "Álbum.hpp"
#include <list>
#include <fstream>

class Album;    //evita include loop

class Artista: public Produtor {

private:
    std::list<Album*> albums;
public:
    Artista();
    ~Artista();

    // Overloading, virtual para evitar chamar o da classe-mãe
    virtual void printOnFile(std::ofstream &_outfile);
    virtual void loadFile(std::ifstream &_infile);
};
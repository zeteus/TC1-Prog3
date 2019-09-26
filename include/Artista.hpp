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
};
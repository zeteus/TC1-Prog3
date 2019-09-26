#pragma once
#include "Produtor.hpp"
#include "Álbum.hpp"
#include <list>

class Artista: private Produtor {

private:
    std::list<Album*> albums;
public:
    Artista();
    ~Artista();
};
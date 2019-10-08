#pragma once

#include <list>
#include <iostream>

#include "Usuário.hpp"
#include "PlataformaDigital.hpp"
#include "Mídia.hpp"

class Midia;
class PlataformaDigital; // forward declarations

class Assinante: public Usuario {

private:
    // Relations
    PlataformaDigital* plataforma;
    std::list<Midia*> favoritos;

    // Setters
    void setDigitalPlatform(PlataformaDigital *platform);
public:
    // Functions
    void printFavoritos();
    void insertFavorito(Midia* favorito);
    void removeFavorito(Midia* favorito);

    // Constructor
    Assinante();
    Assinante(std::string name, int codigo);
    // Destructor
    ~Assinante();

    // Getters
    PlataformaDigital* getDigitalPlatform();
    std::list<Midia*> getFavoritos();

    // Overloading
    void printarNoArquivo(std::ofstream &_outfile);
    void loadFile(std::ifstream &_infile);
};
#pragma once

#include <list>
#include "Usuário.hpp"
#include "PlataformaDigital.hpp"
#include "Mídia.hpp"

class Midia;
class PlataformaDigital; // forward declaration

class Assinante: private Usuario {

public:
    
    PlataformaDigital* platform;
    std::list<Midia*> midias;

    void imprimeFavoritos();
    void inserirFavorito(Midia* favorite);
    void removerFavorito(Midia* favorite);

    // Constructor
    Assinante();
    Assinante(std::string name, int codigo);
    // Destructor
    ~Assinante();

    // Setters
    void setDigitalPlatform(PlataformaDigital *platform);
    // Getters
    PlataformaDigital* getDigitalPlatform();
    std::list<Midia*> getFavoritos();

    // Overloading
    void printOnFile(std::ofstream &_outfile);
    void loadFile(std::ifstream &_infile);
};
#pragma once

#include <list>
#include "Usuário.hpp"
#include "PlataformaDigital.hpp"
#include "Mídia.hpp"

class Midia;
class PlataformaDigital; // forward declaration

class Assinante: private Usuario {

private:
    PlataformaDigital* platform;

    std::list<Midia*> midias;

    // Setters
    void setDigitalPlatform(PlataformaDigital *platform);
public:
    // Constructor
    Assinante();
    // Destructor
    ~Assinante();

    // Getters
    PlataformaDigital* getDigitalPlatform();

    // Overloading, virtual para evitar chamar o da classe-mãe
    virtual void printOnFile(std::ofstream &_outfile);
    virtual void loadFile(std::ifstream &_infile);
};
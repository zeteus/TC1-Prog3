#pragma once

#include "Usuário.hpp"
#include "PlataformaDigital.hpp"

class PlataformaDigital; //evita include loop

class Assinante: private Usuario {

private:
    PlataformaDigital* platform;

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
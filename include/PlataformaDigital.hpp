#pragma once
#include "Assinante.hpp"
#include <list>

class Assinante;    //evita include loop

class PlataformaDigital {

private:
    std::string nome;
    std::list<Assinante*> assinantes;
public:
    PlataformaDigital();
    ~PlataformaDigital();

    void printOnFile(std::ofstream &_outfile);
    void loadFile(std::ifstream &_infile);
};
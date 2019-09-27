#pragma once
#include "Assinante.hpp"
#include "Mídia.hpp"
#include <list>

class Assinante;    //evita include loop

class PlataformaDigital {

private:
    std::string name;
    std::list<Assinante*> subscribers;
    std::list<Midia*> registeredProducts;

    // Setters
    void setName(std::string name);
public:
    // Constructor
    PlataformaDigital();
    // Destructor
    ~PlataformaDigital();

    //Getters
    std::string getName();

    // Functions
    void printOnFile(std::ofstream &_outfile);
    void loadFile(std::ifstream &_infile);
};
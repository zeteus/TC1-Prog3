#pragma once

#include "Usuário.hpp"
#include "Mídia.hpp"
#include <fstream>
#include <list>
#include <iostream>

class Midia;    // Forward declaration

class Produtor: public Usuario {

private:
    std::list<Midia*> launchedProducts;
protected:
    std::string biografy;
    // Setter
    void setBiografy(std::string biografy);

public:
    // Constructors
    Produtor();
    Produtor(std::string _name);
    // Destructor
    ~Produtor();

    // Functions
    void createProduct();
    void printLaunchedProducts();

    // Overloading, virtual para evitar chamar o da classe-mãe
    virtual void printOnFile(std::ofstream &outfile);
    virtual void loadFile(std::ifstream &infile);
    // Getters
    std::string getBiografy();
    std::list<Midia*> getLaunchedProducts();
};
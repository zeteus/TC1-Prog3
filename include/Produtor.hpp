#pragma once

#include "Usuário.hpp"
#include "Mídia.hpp"
#include <fstream>
#include <list>
#include <iostream>

class Produtor: private Usuario {

private:
    std::list<Midia*> launchedProducts;
protected:
    std::string biografy;

public:
    Produtor();
    Produtor(std::string _nome);
    ~Produtor();
    
    void createProduct();
    void printLaunchedProducts();
    std::list<Midia*> getLaunchedProducts();
    virtual void printOnFile(std::ofstream &outfile);
    virtual void loadFile(std::ifstream &infile);

    // Setters and Getters
    void setBiografy(std::string biografy);
    std::string getBiografy();
};
#pragma once

#include "Usuário.hpp"
#include "Mídia.hpp"
#include "PlataformaDigital.hpp"
#include <fstream>
#include <list>
#include <iostream>

class PlataformaDigital;
class Midia;    // Forward declarations

class Produtor: public Usuario {

private:
    // Relações
    std::list<Midia*> launchedProducts;

public:
    // Functions
    void createProduct();
    void printLaunchedProducts();

    // Getters
    std::list<Midia*> getLaunchedProducts();

    // Constructors
    Produtor();
    Produtor(std::string _name);
    // Destructor
    ~Produtor();

    // Overloading, virtual para evitar ser chamado pelos herdeiros
    virtual void printOnFile(std::ofstream &outfile);
    virtual void loadFile(std::ifstream &infile);
};
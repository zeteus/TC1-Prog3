#pragma once

#include <fstream>
#include <list>
#include <iostream>

#include "Usuário.hpp"
#include "Mídia.hpp"
#include "PlataformaDigital.hpp"

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
    void addLaunchedProducts(Midia* launchedProducts);
    void removeLaunchedProducts(Midia* launchedProducts);

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
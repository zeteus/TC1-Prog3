#pragma once

#include <iostream>

class Usuario {

protected:
    std::string name;

    void setName(std::string _name);
    std::string getName();

    // Virtual para evitar chamar o da classe-mãe
    virtual void printOnFile(std::ofstream &outfile) = 0;
    virtual void loadFile(std::ifstream &infile) = 0;
};

// Não tem construtor, jamais será instânciado
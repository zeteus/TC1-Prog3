#pragma once

#include <iostream>
#include <fstream>

class Usuario {

public:
    // Virtual para evitar chamar o da classe-mãe
    virtual void printOnFile(std::ofstream &outfile) = 0;
    virtual void loadFile(std::ifstream &infile) = 0;

    // Getters
    virtual std::string getName();
    virtual int getCodigo();

protected:
    std::string name;
    int codigo;

    // Setters
    virtual void setCodigo(int cod);
    virtual void setName(std::string _name);

};

// Não tem construtor, jamais será instânciado
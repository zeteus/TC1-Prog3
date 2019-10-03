#pragma once

#include <iostream>
#include <fstream>

class Usuario {

protected:
    // Attributes
    std::string name;
    int code;

    // Setters
    void setCode(int cod);
    void setName(std::string _name);

public:
    // Virtual puta para evitar ser chamado
    virtual void printOnFile(std::ofstream &outfile) = 0;
    virtual void loadFile(std::ifstream &infile) = 0;

    // Getters
    virtual std::string getName();
    virtual int getCode();
};

// Não tem construtor, jamais será instânciado
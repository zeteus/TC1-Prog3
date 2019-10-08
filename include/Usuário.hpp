#pragma once

#include <iostream>
#include <fstream>

class Usuario {

protected:
    // Attributes
    std::string nome;
    int codigo;

    // Setters
    void setCodigo(int cod);
    void setNome(std::string _name);

public:
    // Virtual puta para evitar ser chamado
    virtual void printarNoArquivo(std::ofstream &outfile) = 0;
    virtual void loadFile(std::ifstream &infile) = 0;

    // Getters
    std::string getNome();
    int getCodigo();
};//henrique esteve aqui

// Não tem construtor, jamais será instânciado
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
    Usuario(std::string _come, int _codigo);
    Usuario();
    virtual ~Usuario();

    void printInfo();
    // Virtual puta para evitar ser chamado
    virtual void printarNoArquivo(std::ofstream &outfile);

    // Getters
    std::string getNome();
    int getCodigo();
};
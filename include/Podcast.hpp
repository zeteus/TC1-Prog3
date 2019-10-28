#pragma once

#include <iostream>

#include "Mídia.hpp"
#include "Podcaster.hpp"

class Podcast: public Midia {

private:
    // Attribute
    int quantidadeTemporadas;

    // Setters
    void setQtdTemporadas(int qnt);

public:
    // Getters
    int getQtdTemporadas();

    // Constructor
    Podcast();
    Podcast(std::string name, int cod, Midia::Genero* genre, float duracao, int ano, int seasonsQnt);
    // Destructor
    ~Podcast();

    // Overloading
    void printInfoProduto();
    char getTipo();
    void printarNoArquivo(std::ofstream &_outfile);
};
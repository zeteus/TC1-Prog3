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
    Podcast(std::string name, Genero* genre, int seasonsQnt);
    // Destructor
    ~Podcast();

    // Overloading
    void printInfoProduto();
    void printarNoArquivo(std::ofstream &_outfile);
};
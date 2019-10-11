#pragma once

#include <list>
#include <iostream>

#include "Usuário.hpp"
#include "Mídia.hpp"

class Midia;

class Assinante: public Usuario {

private:
    // Relations
    std::list<Midia*> favoritos;

public:
    // Functions
    void printAssinante();
    void printFavoritos();
    void inserirFavorito(Midia* favorito);
    void removeFavorito(Midia* favorito);

    // Constructor
    Assinante();
    Assinante(std::string name, int codigo);
    // Destructor
    ~Assinante();

    // Getters
    std::list<Midia*> getFavoritos();

    // Overloading
    void printarNoArquivo(std::ofstream &_outfile);
};
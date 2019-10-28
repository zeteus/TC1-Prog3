#pragma once

#include <set>
#include <iostream>

#include "Usuário.hpp"
#include "Mídia.hpp"

class Midia;

class Assinante: public Usuario {

private:
    // Relations
    std::set<Midia*> favoritos;

public:
    // Functions
    void printFavoritos();
    void inserirFavorito(Midia* favorito);
    void removeFavorito(Midia* favorito);

    // Constructor
    Assinante();
    Assinante(std::string name, int codigo);
    // Destructor
    ~Assinante();

    // Getters
    std::set<Midia*> getFavoritos();

};
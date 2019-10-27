#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <exception>

#include "defines.h"
#include "Música.hpp"

class Musica;       // Fwd declaration

class Album {

private:
    // Attributes
    std::string nome;
    int codigo;
    float duracao;
    int anoLancamento;
    int quantidadeMusicas;

    // Relation
    std::list<Musica*> musics;

    // Setters
    void setDuracao(float _duration);
    void setAnoLancamento(int _launchYear);
    void setQuantidadeMusicas(int _musicAmount);
    void setCodigo(int _cod);
    void setNome(std::string _name);

public:    
    // Constructors
    Album(std::string nome, int codigo, float duracao, int ano, int qtd);
    Album();
    // Destructor
    ~Album();

    // Getters
    float getDuracao();
    int getAnoLancamento();
    int getQuantidadeMusicas();
    int getCodigo();
    std::string getNome();

    // Functions
    void addMusic(Musica* music);
    void printMe();

    // Overloading
    void printarNoArquivo(std::ofstream &_outfile);
};
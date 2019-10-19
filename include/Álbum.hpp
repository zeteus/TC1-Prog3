#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "Música.hpp"

class Musica;       // Fwd declaration

class Album {

private:
    // Attributes
    std::string nome;
    int codigo;
    int duracao;
    int anoLancamento;
    int quantidadeMusicas;

    // Relation
    std::list<Musica*> musics;

    // Setters
    void setDuracao(int _duration);
    void setAnoLancamento(int _launchYear);
    void setQuantidadeMusicas(int _musicAmount);
    void setCodigo(int _cod);
    void setNome(std::string _name);

public:    
    // Constructors
    Album(std::string nome, int codigo, int duracao, int ano, int qtd);
    Album();
    // Destructor
    ~Album();

    // Getters
    int getDuracao();
    int getAnoLancamento();
    int getQuantidadeMusicas();
    int getCodigo();
    std::string getNome();

    // Functions
    void addMusic(Musica* music);

    // Overloading
    void printarNoArquivo(std::ofstream &_outfile);
};
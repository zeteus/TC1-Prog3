#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "Artista.hpp"
#include "Música.hpp"

class Musica;
class Artista;  // forward declarations

class Album {

private:
    // Attributes
    std::string nome;
    int duracao;
    int anoLancamento;
    int quantidadeMusicas;

    // Relations
    Artista* artista;
    std::list<Musica*> musics;

    // Setters
    void setArtista(Artista* _artista);
    void setDuracao(int _duration);
    void setAnoLancamento(int _launchYear);
    void setQuantidadeMusicas(int _musicAmount);
    void setNome(std::string _name);

public:    
    // Constructors
    Album(Artista* _artist, int _duration, int _yearLaunch, int _musicAmount, std::string _name);
    Album();
    // Destructor
    ~Album();

    // Getters
    Artista* getArtista();
    int getDuracao();
    int getAnoLancamento();
    int getQuantidadeMusicas();
    std::string getNome();

    // Functions
    void addMusic(Musica* music);

    // Overloading
    void printarNoArquivo(std::ofstream &_outfile);
};
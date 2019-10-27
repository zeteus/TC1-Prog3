#pragma once

#include <iostream>
#include <sstream>
#include <list>
#include <set>
#include <unordered_map>

#include "Artista.hpp"
#include "Álbum.hpp"
#include "Música.hpp"
#include "Podcast.hpp"
#include "Podcaster.hpp"
#include "Assinante.hpp"
#include "Mídia.hpp"
#include "Produtor.hpp"
#include "Mídia.hpp"

class PlataformaDigital {

private:
    // Attribute
    std::string nome;

    // Relations
    std::set<Assinante*>       assinantes;
    std::set<Midia*>           produtosRegistrados;
    std::set<Produtor*>        produtores;
    std::set<Midia::Genero*>   generos;
    std::set<Album*>           albumsCadastrados;

public:
    // Constructors
    PlataformaDigital();
    PlataformaDigital(std::string _nome);
    // Destructor
    ~PlataformaDigital();

    //Setters
    void setNome(std::string _nome);
    //Getters
    std::string getNome();
    std::set<Assinante*>       getAssinantes();
    std::set<Midia*>           getProdutosRegistrados();
    std::set<Produtor*>        getProdutores();
    std::set<Midia::Genero*>   getGeneros();
    std::set<Album*>           getAlbumsCadastrados();

    // Functions
    void printProdutos();
    void printProdutos(std::string _genre);
    void printProdutores();
    void printAssinantes();
    void printGeneros();
    void printAlbuns();
    void addAssinante(Assinante* _subscriber);
    void removeAssinante(Assinante* _subscriber);
    void addProduto(Midia* _newProduct, std::set<Produtor*> _producers);
    void addAlbum(Album *album);
    void exportLibrary();
    void generateReports();


    // Arquivo
    void printarNoArquivo(std::ofstream &_outfile);
    void loadFileUsuarios(std::ifstream &_infile);
    void loadFileGeneros(std::ifstream &_infile);
    void loadFileMidias(std::ifstream &_infile);
    void loadFileFavoritos(std::ifstream &_infile);
};
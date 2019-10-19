#pragma once

#include <iostream>
#include <sstream>
#include <list>

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
    std::list<Assinante*>       assinantes;
    std::list<Midia*>           produtosRegistrados;
    std::list<Produtor*>        produtores;
    std::list<Midia::Genero*>   generos;
    std::list<Album*>           albumsCadastrados;

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
    std::list<Assinante*>       getAssinantes();
    std::list<Midia*>           getProdutosRegistrados();
    std::list<Produtor*>        getProdutores();
    std::list<Midia::Genero*>   getGeneros();
    std::list<Album*>           getAlbumsCadastrados();

    // Functions
    void printProdutos(std::string _genre);
    void printAssinantes();
    void addAssinante(Assinante* _subscriber);
    void removeAssinante(Assinante* _subscriber);
    void addProduto(Midia* _newProduct, std::list<Produtor*> _producers);
    void addAlbum(Album *album);
    void exportLibrary();
    void generateReports();

    // Manipulação das estruturas de dados
    void addGenero(Midia::Genero *_genre);

    // Arquivo
    void printarNoArquivo(std::ofstream &_outfile);
    void loadFileUsuarios(std::ifstream &_infile);
    void loadFileGeneros(std::ifstream &_infile);
    void loadFileMidias(std::ifstream &_infile);
    void loadFileFavoritos(std::ifstream &_infile);
};
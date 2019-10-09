#pragma once

#include <iostream>
#include <list>

#include "Assinante.hpp"
#include "Mídia.hpp"
#include "Produtor.hpp"
#include "Mídia.hpp"

class PlataformaDigital {

private:
    // Attribute
    std::string nome;

    // Relations
    std::list<Assinante*> assinantes;
    std::list<Midia*> produtosRegistrados;
    std::list<Produtor*> produtores;
    std::list<Midia::Genero*> generos;

public:
    // Constructors
    PlataformaDigital();
    PlataformaDigital(std::string name);
    // Destructor
    ~PlataformaDigital();

    //Setters
    void setNome(std::string name);
    //Getters
    std::string getNome();
    std::list<Assinante*> getSubscribers();
    std::list<Midia*> getRegisteredProducts();

    // Functions
    void printProducts(std::string genre);
    void printSubscribers();
    void insertSubscriber(Assinante* subscriber);
    void removeSubscriber(Assinante* subscriber);
    void insertProducer(Midia* newProduct, std::list<Produtor*> producers);
    void removeProducer(Produtor* producer);
    void addGenre(Midia::Genero* genre);
    void removeGenre(Midia::Genero* genre);
    void addMidia(Midia* midia);
    void removeMidia(Midia* midia);
    void exportLibrary();
    void generateReports();

    void printarNoArquivo(std::ofstream &_outfile);
    void loadFile(std::ifstream &_infile);
};
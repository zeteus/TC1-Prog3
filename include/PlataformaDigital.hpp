#pragma once

#include "Assinante.hpp"
#include "Mídia.hpp"
#include "Produtor.hpp"
#include "Mídia.hpp"
#include <iostream>
#include <list>

class Genero;
class Produtor;
class Midia;
class Assinante;    // forward declarations

class PlataformaDigital {

private:
    // Attributes
    std::string name;

    // Relations
    std::list<Assinante*> subscribers;
    std::list<Midia*> registeredProducts;
    std::list<Produtor*> producers;
    std::list<Genero*> genres;

public:
    // Constructors
    PlataformaDigital();
    PlataformaDigital(std::string name);
    // Destructor
    ~PlataformaDigital();

    //Setters
    void setName(std::string name);
    //Getters
    std::string getName();
    std::list<Assinante*> getSubscribers();
    std::list<Midia*> getRegisteredProducts();

    // Functions
    void printProducts(std::string genre);
    void printSubscribers();
    void insertSubscriber(Assinante* subscriber);
    void removeSubscriber(Assinante* subscriber);
    void insertProduct(Midia* newProduct, std::list<Produtor*> producers);
    void exportLibrary();
    void generateReports();

    void printOnFile(std::ofstream &_outfile);
    void loadFile(std::ifstream &_infile);
};
#pragma once

#include "Assinante.hpp"
#include "Mídia.hpp"
#include <iostream>
#include <list>

class Midia;
class Assinante;    // forward declaration

class PlataformaDigital {

private:
    std::string name;
    std::list<Assinante*> subscribers;
    std::list<Midia*> registeredProducts;

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
    void insertSubscriber(Assinante* subscribers);
    void removeSubscriber(Assinante* subscribers);
    int  insertProduct(Midia* newProduct, std::string producerName);
    int  selectSubscriber();
    void insertProductSubscriber();
    void printOnFile(std::ofstream &_outfile);
    void loadFile(std::ifstream &_infile);
    void exportLibrary();
    void generateReports();
};
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

    // Setters
    void setName(std::string name);
public:
    // Constructors
    PlataformaDigital();
    PlataformaDigital(std::string name);
    // Destructor
    ~PlataformaDigital();

    //Getters
    std::string getName();
    std::list<Assinante*> getSubscribers();
    std::list<Midia*> getRegisteredProducts();

    // Functions
    void printOnFile(std::ofstream &_outfile);
    void loadFile(std::ifstream &_infile);
    void printProducts(std::string genre);
    void printSubscribers();
    void insertSubscriber();
    void removeSubscriber();
    int insertProduct(Midia* newProduct, std::string producerName);
    int selectSubscriber();
    void insertProductSubscriber();
    void exportLibrary();
    void generateReports();
};
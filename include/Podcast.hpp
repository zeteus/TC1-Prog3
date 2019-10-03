#pragma once

#include <iostream>

#include "Mídia.hpp"
#include "Podcaster.hpp"

class Podcast: public Midia {

private:
    // Attribute
    int seasonsQnt;

    // Setters
    void setSeasonsQnt(int qnt);

public:
    // Getters
    int getSeasonsQnt();

    // Constructor
    Podcast();
    Podcast(std::string name, bool expl, std::string genre, int seasonsQnt);
    // Destructor
    ~Podcast();

    // Overloading
    void printProductInfo();
    void printOnFile(std::ofstream &_outfile);
    void loadFile(std::ifstream &_infile);
};
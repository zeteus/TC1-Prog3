#pragma once
#include "Mídia.hpp"

class Podcast: public Midia {

private:
    int seasonsQnt;

    //Setters
    void setSeasonsQnt(int qnt);

public:
    // Constructor
    Podcast();
    Podcast(std::string name, bool expl, std::string genre, int seasonsQnt);
    // Destructor
    ~Podcast();

    // Overloading, virtual para evitar chamar o da classe-mãe
    virtual void printOnFile(std::ofstream &_outfile);
    virtual void loadFile(std::ifstream &_infile);
};
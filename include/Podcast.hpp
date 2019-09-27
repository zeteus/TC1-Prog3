#pragma once
#include "Mídia.hpp"

class Podcast: public Midia {

private:

public:
    Podcast();
    ~Podcast();

    // Overloading, virtual para evitar chamar o da classe-mãe
    virtual void printOnFile(std::ofstream &_outfile);
    virtual void loadFile(std::ifstream &_infile);
};
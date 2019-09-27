#pragma once
#include "Produtor.hpp"
#include "Podcast.hpp"
#include <list>
#include <fstream>

class Podcaster: public Produtor {

private:
    std::list<Podcast*> podcasts;
public:
    // Constructor
    Podcaster();
    // Destructor
    ~Podcaster();

    // Overloading, virtual para evitar chamar o da classe-mãe
    virtual void printOnFile(std::ofstream &_outfile);
    virtual void loadFile(std::ifstream &_infile);
};
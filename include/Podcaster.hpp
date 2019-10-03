#pragma once

#include <list>
#include <fstream>

#include "Produtor.hpp"
#include "Podcast.hpp"

class Podcaster: public Produtor {

private:
    std::list<Podcast*> podcasts;


public:
    // Constructor
    Podcaster(std::string name, int code);
    // Destructor
    ~Podcaster();

    // Getters
    std::list<Podcast*> getPodcasts();

    // Overloading, virtual para evitar dos herdeiros chamarem
    virtual void printOnFile(std::ofstream &_outfile);
    virtual void loadFile(std::ifstream &_infile);
};
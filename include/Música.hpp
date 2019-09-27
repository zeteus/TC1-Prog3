#pragma once
#include "Mídia.hpp"
#include <iostream>

class Musica: public Midia {

private:
    int duration;
    int launchYear;

    void formattedDuration();

public:
    // Constructor
    Musica();
    // Destructor
    ~Musica();
    

    // Setters
    void setDuration(int _duration);
    void setLaunchYear(int _launchYear);
    // Getters
    int getDuration();
    int getLaunchYear();

    // Functions
    void printProductInfo();
    // Overloading, virtual para evitar chamar o da classe-mãe
    virtual void printOnFile(std::ofstream &_outfile);
    virtual void loadFile(std::ifstream &_infile);
};
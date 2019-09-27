#pragma once
#include "Mídia.hpp"
#include <iostream>

class Musica: public Midia {

private:
    int duration;
    int launchYear;

    // Fuctions
    void formattedDuration();

    // Setters
    void setDuration(int duration);
    void setLaunchYear(int launchYear);

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
    // Overloading, virtual para evitar chamar o da classe-mãe
    void printProductInfo();
    virtual void printOnFile(std::ofstream &_outfile);
    virtual void loadFile(std::ifstream &_infile);
};
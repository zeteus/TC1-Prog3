#include "Produtor.hpp"

Produtor::Produtor() {}

Produtor::Produtor(std::string _name){
    this->setName(_name);
}

Produtor::~Produtor() {
    this->launchedProducts.clear(); //forma a composição
}


void Produtor::printOnFile(std::ofstream &outfile){}

void Produtor::loadFile(std::ifstream &infile){}


    // Setters and Getters

void Produtor::setBiografy(std::string biografy) {this->biografy = biografy;}
std::string Produtor::getBiografy() {return this->biografy;}
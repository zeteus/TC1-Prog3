#include "Produtor.hpp"

Produtor::Produtor() {}

Produtor::Produtor(std::string _name){
}

Produtor::~Produtor() {
    this->launchedProducts.clear(); //forma a composição
}


void Produtor::printOnFile(std::ofstream &outfile){}

void Produtor::loadFile(std::ifstream &infile){}

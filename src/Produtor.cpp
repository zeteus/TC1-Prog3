#include "Produtor.hpp"

Produtor::Produtor() {

}

Produtor::~Produtor() {
    this->launchedProducts.clear(); //forma a composição
}

    // Setters and Getters

void Produtor::setBiografy(std::string biografy) {this->biografy = biografy;}
std::string Produtor::getBiografy() {return this->biografy;}
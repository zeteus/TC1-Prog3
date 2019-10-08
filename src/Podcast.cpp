#include "Podcast.hpp"

Podcast::Podcast() {

}

Podcast::~Podcast() {

}

void Podcast::printarNoArquivo(std::ofstream &_outfile){};
void Podcast::loadFile(std::ifstream &_infile){};
void Podcast::printProductInfo(){};
void Podcast::addSubscriber(Assinante* subscriber){};
void Podcast::removeSubscriber(Assinante* subscriber){};
void Podcast::addProducer(Produtor* producer){};
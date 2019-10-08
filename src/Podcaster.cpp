#include "Podcaster.hpp"

Podcaster::Podcaster(std::string name, int code) {
    this->setNome();
    this->setCodigo();
}

Podcaster::~Podcaster() {}

// Overloading
void Podcaster::printarNoArquivo(std::ofstream &_outfile) {
    // TODO
}
void Podcaster::loadFile(std::ifstream &_infile) {
    // TODO
}

void addPodcast(Podcast* podcast) {
    this->podcasts.push_back(podcast);
}

void removePodcast(Podcast* podcast) {
    this->podcasts.remove(podcast);
}
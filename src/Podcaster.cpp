#include "Podcaster.hpp"

// Constructor
Podcaster::Podcaster(std::string name, int code) {
    this->setNome();
    this->setCodigo();
}
// Destructor
Podcaster::~Podcaster() {}

// Overloading
void Podcaster::printarNoArquivo(std::ofstream &_outfile) {
    // TODO
}

// Functions
void addPodcast(Podcast* podcast) {
    this->podcasts.push_back(podcast);
}

void removePodcast(Podcast* podcast) {
    this->podcasts.remove(podcast);
}
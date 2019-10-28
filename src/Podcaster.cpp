#include "Podcaster.hpp"

// Constructor
Podcaster::Podcaster(std::string name, int code) {
    this->setNome(name);
    this->setCodigo(code);
}
// Destructor
Podcaster::~Podcaster() {}

// Functions
void Podcaster::addPodcast(Podcast* podcast) {
    this->podcasts.push_back(podcast);
}

void Podcaster::removePodcast(Podcast* podcast) {
    this->podcasts.remove(podcast);
}

// Getter
std::list<Podcast*> Podcaster::getPodcasts() {return this->podcasts;}
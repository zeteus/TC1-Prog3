#pragma once
#include "Produtor.hpp"
#include "Podcast.hpp"
#include <list>
#include <fstream>

class Podcaster: public Produtor {

private:
    std::list<Podcast*> podcasts;
public:
    Podcaster();
    ~Podcaster();
};
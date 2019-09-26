#pragma once
#include "Produtor.hpp"
#include "Podcast.hpp"
#include <list>

class Podcaster: private Produtor {

private:
    std::list<Podcast*> podcasts;
public:
    Podcaster();
    ~Podcaster();
};
#pragma once
#include "Assinante.hpp"
#include <list>

class Assinante;    //evita include loop

class PlataformaDigital {

private:
    std::list<Assinante*> assinantes;
public:
    PlataformaDigital();
    ~PlataformaDigital();
};
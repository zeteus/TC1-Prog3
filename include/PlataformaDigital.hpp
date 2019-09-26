#pragma once
#include "Assinante.hpp"
#include <list>

class PlataformaDigital {

private:
    std::list<Assinante*> assinantes;
public:
    PlataformaDigital();
    ~PlataformaDigital();
};
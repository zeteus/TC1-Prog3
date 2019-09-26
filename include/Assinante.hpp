#pragma once

#include "Usuário.hpp"
#include "PlataformaDigital.hpp"

class PlataformaDigital; //evita include loop

class Assinante: private Usuario {

private:
    PlataformaDigital* platform;
public:
    Assinante();
    ~Assinante();
};
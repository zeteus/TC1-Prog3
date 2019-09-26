#pragma once

#include "Usuário.hpp"
#include "PlataformaDigital.hpp"

class Assinante: private Usuario {

private:
    PlataformaDigital* platform;
public:
    Assinante();
    ~Assinante();
};
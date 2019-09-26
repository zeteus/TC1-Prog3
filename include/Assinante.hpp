#pragma once

#include "Usuário.hpp"
#include "PlataformaDigital.hpp"

class Assinante: private Usuario {

private:
    PlataformaDigital* plataforma;
public:
    Assinante();
    ~Assinante();
};
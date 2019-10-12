#pragma once
// Lib para manipular os arquivos

#include "defines.h"
#include <list>
#include <iostream>
#include <fstream>

// Carrega todos os gêneros na memória, nos vetores 'sigla' e 'nome'
void carregaGenero(std::string filepath, std::list<std::string> &sigla, std::list<std::string> &nome);
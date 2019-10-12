#pragma once
// Lib para manipular os arquivos

#include "defines.h"
#include <list>
#include <iostream>
#include <fstream>

// Carrega todos os gêneros na memória, nos vetores 'sigla' e 'nome'
void carregaGenero(std::string filepath, std::list<std::string> genero[2]);
void carregaMidia(std::string filepath, std::list<std::string> &nomeMidia, std::list<std::string> &album, std::list<std::string> &anoPublicacao, std::list<std::string> &generoMidia, std::list<int> &codigoMidia, std::list<std::list<int>> &produtorMidia, std::list<int> &duracao, std::list<int> &qntSeasons, std::list<char> &tipoMidia);
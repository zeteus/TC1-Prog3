#pragma once
// Lib para manipular os arquivos

#include "defines.h"
#include <list>
#include <iostream>
#include <fstream>

using std::string;
using std::getline;
using std::list;

// Carrega todos os gêneros na memória
void carregaGenero(string filepath, list<string> genero[2]);
// Carrega todas as mídias na memória
void carregaMidia(string filepath, list<string> &nomeMidia, list<string> &album, list<string> &anoPublicacao, list<string> &generoMidia, list<int> &codigoMidia, list<list<int>> &produtorMidia, list<int> &duracao, list<int> &qntSeasons, list<char> &tipoMidia);
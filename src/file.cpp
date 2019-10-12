#include "file.hpp"

// Carrega todos os gêneros na memória, nos vetores 'sigla' e 'nome'
void carregaGenero(std::string filepath, std::list<std::string> genero[2]) {
    std::ifstream infile;
    infile.open(filepath, std::ios::in);
    if(!infile.is_open()){
        std::cerr << _BOLDRED << "Erro ao abrir o arquivo " << _RESET << _RED << filepath << "! Terminando o programa..." << std::endl;
        exit(1);
    }

    std::string str;
    getline(infile, str);   //ignora a primeira linha
    while(!infile.eof()){
        std::getline(infile, str, ';');
        genero[0].push_back(str);
        std::getline(infile, str, '\n');
        genero[1].push_back(str);
    }

    infile.close();
}

void carregaMidia(std::string filepath, std::list<std::string> &codigoMidia, std::list<std::string> &nomeMidia, std::list<std::string> &tipoMidia, std::list<std::string> &produtores, std::list<std::string> &duracao, std::list<std::string> &genero, std::list<std::string> &season, std::list<std::string> &album, std::list<std::string> &publicacao) {
    std::ifstream infile;
    infile.open(filepath, std::ios::in);
    if(!infile.is_open()){
        std::cerr << _BOLDRED << "Erro ao abrir o arquivo " << _RESET << _RED << filepath << "! Terminando o programa..." << std::endl;
        exit(1);
    }

    std::string str;
    getline(infile, str);   //ignora a primeira linha
    while(!infile.eof()){

    }

    infile.close();
}
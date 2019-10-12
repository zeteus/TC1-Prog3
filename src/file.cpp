#include "file.hpp"

std::ifstream* abreEChecaIn(std::string filepath) {
    std::ifstream *infile = (std::ifstream*) malloc(sizeof(std::ifstream));
    infile->open(filepath, std::ios::in);
    if(!infile->is_open()){
        std::cerr << _BOLDRED << "Erro ao abrir o arquivo " << _RESET << _RED << filepath << "! Terminando o programa..." << std::endl;
        exit(1);
    }
    return infile;
}

// Carrega todos os gêneros na memória, nos vetores 'sigla' e 'nome'
void carregaGenero(std::string filepath, std::list<std::string> &sigla, std::list<std::string> &nome) {
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
        sigla.push_back(str);
        std::getline(infile, str, '\n');
        nome.push_back(str);
    }
    
    infile.close();
}
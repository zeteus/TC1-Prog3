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
void carregaMidia(std::string filepath, std::list<std::string> &nomeMidia, std::list<std::string> &album, std::list<std::string> &anoPublicacao, std::list<std::string> &generoMidia, std::list<int> &codigoMidia, std::list<std::list<int>> &produtorMidia, std::list<int> &duracao, std::list<int> &qntSeasons, std::list<char> &tipoMidia) {
    std::ifstream infile;
    infile.open(filepath, std::ios::in);
    if(!infile.is_open()){
        std::cerr << _BOLDRED << "Erro ao abrir o arquivo " << _RESET << _RED << filepath << "! Terminando o programa..." << std::endl;
        exit(1);
    }

    std::string str, str2;
    std::list<int> produtores;
    int num;
    char ch;
    getline(infile, str);   //ignora a primeira linha
    while(!infile.eof()){
        std::getline(infile, str, ';');
        std::cout << str;
        codigoMidia.push_back(stoi(str));
        std::getline(infile, str, ';');
        nomeMidia.push_back(str);
        std::getline(infile, str, ';');
        tipoMidia.push_back(str[0]);
        std::getline(infile, str, ';');
        std::cout << str;

        while(std::getline(infile, str2, ','))
        std::cout << str2;
            produtores.push_back(stoi(str2));
        produtorMidia.push_back(produtores);

        std::getline(infile, str, ';');
        std::cout << str;
        duracao.push_back(stoi(str));
        std::getline(infile, str, ';'); //TODO: Ajeitar pra pegar só o primeiro
        generoMidia.push_back(str);
        std::getline(infile, str, ';');
        std::cout << str;
        qntSeasons.push_back(stoi(str));
        std::getline(infile, str, ';');
        album.push_back(str);
        std::getline(infile, str, ';');
        anoPublicacao.push_back(str);
        produtores.clear();
    }

    infile.close();
}
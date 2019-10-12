#include "file.hpp"

// Carrega todos os gêneros na memória, nos vetores 'sigla' e 'nome'
void carregaGenero(string filepath, list<string> genero[2]) {
    std::ifstream infile;
    infile.open(filepath, std::ios::in);
    if(!infile.is_open()){
        std::cerr << _BOLDRED << "Erro ao abrir o arquivo " << _RESET << _RED << filepath << "! Terminando o programa..." << std::endl;
        exit(1);
    }

    string str;
    getline(infile, str);   //ignora a primeira linha
    while(!infile.eof()){
        getline(infile, str, ';');
        genero[0].push_back(str);
        getline(infile, str, '\n');
        genero[1].push_back(str);
    }

    infile.close();
}
void carregaMidia(string filepath, list<string> &nomeMidia, list<string> &album, list<string> &anoPublicacao, list<string> &generoMidia, list<int> &codigoMidia, list<list<int>> &produtorMidia, list<int> &duracao, list<int> &qntSeasons, list<char> &tipoMidia) {
    std::cout << "Chegou aqui porra";
    std::ifstream infile;
    infile.open(filepath, std::ios::in);
    if(!infile.is_open()){
        std::cerr << _BOLDRED << "Erro ao abrir o arquivo " << _RESET << _RED << filepath << "! Terminando o programa..." << std::endl;
        exit(1);
    }

    std::cout << "Chegou aqui caralho";

    string str;
    list<int> produtores;
    int num;
    float fl;
    char ch;
    getline(infile, str);   //ignora a primeira linha
    while(!infile.eof()){
        infile >> num;      // lê o primeiro nº o código
        codigoMidia.push_back(num);
        infile.ignore();    // ignora o ';'
        getline(infile, str, ';'); // pega tudo até o próximo ';', o nome
        nomeMidia.push_back(str);
        infile >> ch;       // lê o próximo char, o tipo
        tipoMidia.push_back(ch);
        infile.ignore();    // ignora o ';'
        infile >> num;      // lê o próximo nº, o produtor
        produtores.push_back(num);
        infile >> ch;       // lê o próximo char, para testar.
        while(ch == ','){   // para múltiplos produtores
            infile >> num;  // lê o próximo nº, o produtor adicional
            produtores.push_back(num);
            infile >> ch;   // lê o próximo char, para testar.
            std::cout << ch;
        }                   // o próximo ';' já está skipado
        produtorMidia.push_back(produtores); // adiciona a lista montada na lista de lista
        infile >> fl;       // lê o próximo nº, duração
        infile.ignore();    // ignora o ';'
        getline(infile, str, ';');  // lê tudo até o próximo ';', os gêneros
        // TODO: Fazer pegar apenas o primeiro gênero.
        infile >> num;      // lê o próximo nº, a temporada
        infile.ignore();    // ignora o ';'
        getline(infile, str, ';');  // lê tudo até o próximo ';', o álbum
        album.push_back(str);
        getline(infile, str, ';');  // lê tudo até o próximo ';', o ano de publicação
        anoPublicacao.push_back(str);

    }

    infile.close();
}
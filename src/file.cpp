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
        std::cout << "Chegou aqui porra" << std::endl;
    std::ifstream infile;
    infile.open(filepath, std::ios::in);
    if(!infile.is_open()){
        std::cerr << _BOLDRED << "Erro ao abrir o arquivo " << _RESET << _RED << filepath << "! Terminando o programa..." << std::endl;
        exit(1);
    }

        std::cout << "Chegou aqui caralho" << std::endl;

    string str;
    list<int> produtores;
    int num;
    float fl, num2;
    char ch;
    getline(infile, str);   //ignora a primeira linha
        std::cout << "Linha ignorada: " << str << std::endl;
    while(!infile.eof()){
        infile >> num;      // lê o primeiro nº o código
            std::cout << "cod: " << num << ';' << std::endl;
        codigoMidia.push_back(num);
        infile.ignore();    // ignora o ';'
        getline(infile, str, ';'); // pega tudo até o próximo ';', o nome
            std::cout << "Nome: " << str << ';' << std::endl;
        nomeMidia.push_back(str);
        infile >> ch;       // lê o próximo char, o tipo
            std::cout << "Tipo: " << ch << ';' << std::endl;
        tipoMidia.push_back(ch);
        infile.ignore();    // ignora o ';'
        infile >> num;      // lê o próximo nº, o produtor
            std::cout << "Produtor: " << num << ';' << std::endl;
        produtores.push_back(num);
        infile >> ch;       // lê o próximo char, para testar.
        while(ch == ','){   // para múltiplos produtores
            infile >> num;  // lê o próximo nº, o produtor adicional
                std::cout << "Produtor: " << num << ';' << std::endl;
            produtores.push_back(num);
            infile >> ch;   // lê o próximo char, para testar no condicional.
                std::cout << "*" << ch << "*";
        }                   // o próximo ';' já está skipado
        produtorMidia.push_back(produtores); // adiciona a lista montada na lista de lista
        infile >> num;          // lê o próximo nº, duração inteira
        infile.ignore();        // ignora a ','
        infile >> num2;         // lê o próximo nº, duração decimal
        fl = num + num2/100;    // tempo total
            std::cout << "Duração: " << fl << ';' << std::endl;
        infile.ignore();    // ignora o ';'
        getline(infile, str, ';');  // lê tudo até o próximo ';', os gêneros
            std::cout << "Generos: " << str << ';' << std::endl;
        // TODO: Fazer pegar apenas o primeiro gênero.
        getline(infile, str, ';');  // lê o próximo nº, a temporada
        if(str == "") num = 0;
        else num = stoi(str);
            std::cout << "Season: " << num << ';' << std::endl;
        // infile.ignore();            // ignora o ';'
        getline(infile, str, ';');     // lê tudo até o próximo ';', o álbum
            std::cout << "Album: " << str << ';' << std::endl;
        album.push_back(str);
        getline(infile, str);  // lê tudo até o próximo '\n', o ano de publicação
            std::cout << "Publicacao: " << str << ';' << std::endl;
        anoPublicacao.push_back(str);

    }

    infile.close();
}
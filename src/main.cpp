#include "defines.h"     //corzinhas bonitas
#include "file.hpp"     // manipulação de arquivo
#include "../include/PlataformaDigital.hpp"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[]) {
    if(argc != 9){
        cout << _BOLDRED << "Checa essas entrada aí bro." << _RESET << endl;
        exit(1);
    }

    char* in;
    string pathUsuario;
    string pathFavoritos;
    string pathMidias;
    string pathGeneros;

    for(int i = 1; i < argc; i++) {
        in = argv[i];
        if(in[0] == '-') {
            switch(in[1]){
                case 'u':
                case 'U':
                    pathUsuario = argv[i + 1];
                break;
                case 'f':
                case 'F':
                    pathFavoritos = argv[i + 1];
                break;
                case 'm':
                case 'M':
                    pathMidias = argv[i + 1];
                break;
                case 'g':
                case 'G':
                    pathGeneros = argv[i + 1];
                break;
                default:
                    cout << _BOLDRED << "Alguma flag tá bizonha. Só aceito 'u', 'f', 'm' e 'g'!" << _RESET << endl;
                    exit(1);
            }
        }
    }

    cout << pathUsuario << endl;
    cout << pathFavoritos << endl;
    cout << pathMidias << endl;
    cout << pathGeneros << endl;

    cout << "Lendo arquivo gêneros..." << endl;

    std::list<string> genero[2], midia[9];

    carregaGenero(pathGeneros, genero);

    std::list<string>::iterator it;
    for(it = genero->begin(); it != genero->end(); it++){
        cout << (*it)[0] << ';' << (*it)[1] << endl;
    }

    for(int i = 0; i < 2; i++)
        genero[i].clear();

    return 0;
}
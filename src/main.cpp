#include "defines.h"     //corzinhas bonitas
#include "../include/PlataformaDigital.hpp"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::list;
using std::ifstream;

template <typename typeA>
void printList(list<typeA> a) {
    typename list<typeA>::iterator it;
    for(it = a.begin(); it != a.end(); it++)
        cout << *it << endl;
}

int main(int argc, char* argv[]) {
    if(argc != 9){
        cout << _BOLDRED << "Checa essas entrada aí bro." << _RESET << endl;
        exit(4);
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
                    exit(4);
            }
        }
    }

    ifstream usuario;
    usuario.open(pathUsuario, std::ios::in);
    ifstream generos;
    generos.open(pathGeneros, std::ios::in);
    ifstream midia;
    midia.open(pathMidias, std::ios::in);
    ifstream favoritos;
    favoritos.open(pathFavoritos, std::ios::in);

    PlataformaDigital plat = PlataformaDigital("Spotify++");

    plat.loadFileUsuarios(usuario);
    plat.loadFileGeneros(generos);
    plat.loadFileMidias(midia);
    plat.loadFileFavoritos(favoritos);

    plat.generateReports();
    plat.exportLibrary();

    return 0;
}
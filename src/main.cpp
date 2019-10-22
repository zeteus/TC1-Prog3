#include "defines.h"     //corzinhas bonitas
#include "file.hpp"     // manipulação de arquivo
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

    ifstream usuario;
    usuario.open(pathUsuario, std::ios::in);
    ifstream generos;
    generos.open(pathGeneros, std::ios::in);
    ifstream midia;
    midia.open(pathMidias, std::ios::in);
    ifstream favoritos;
    favoritos.open(pathFavoritos, std::ios::in);

    // criando os produtos para poder testar
    PlataformaDigital plat = PlataformaDigital("Contrutor sem parametro");;
    Midia::Genero *genre = new Midia::Genero("Modao", "MD");
    Musica *music = new Musica("Menino da Porteira", genre, 2.45, 2001);
    Podcast *pod = new Podcast("Critical Role", genre, 3);

    // cout << "MUSICA:" << endl;
    // music->printInfoProduto();
    // cout << "PODCAST:" << endl;
    // pod->printInfoProduto();

    genre->addMidia(music);
    genre->addMidia(pod);
    
    // cout << "Lendo arquivos de entradas..." << endl;
    // plat.loadFileUsuarios(usuario);
    // plat.loadFileGeneros(generos);
    // plat.loadFileMidias(midia);
    // plat.loadFileFavoritos(favoritos);

    // plat.printGeneros();
    
    Produtor *prod = new Produtor("Sergio Reis", 69);
    std::list<Produtor*> producers;
    producers.push_back(prod);

    // plat.addProduto(pod, producers);
    plat.addProduto(pod, producers);
    plat.addProduto(music, producers);
    plat.printProdutos("abc");
    // plat.printProdutos("abc");
    // platTest.addProduto(pod,producers);
    // platTest.printProdutos("abc");

    delete genre;

    return 0;
}
#include "Produtor.hpp"

Produtor::Produtor() {}

Produtor::Produtor(std::string _name){
    this->setNome();
}

Produtor::~Produtor() {
    this->produtosDesenvolvidos.clear(); //forma a composição
}


void Produtor::printarNoArquivo(std::ofstream &outfile) {
    // fazer uma funcao pra printar aqui em amigo
    // TODO
}

void Produtor::loadFile(std::ifstream &infile) {
    // fazer uma funcao pra dar load aqui meu amigo
    // TODO
}

std::list<Midia*> Produtor::getProdutosDesenvolvidos() {
    return this->produtosDesenvolvidos;
}

void Produtor::imprimeProdutosDesenvolvidos() {
    std::list<Midia*>::iterator aux;
    for(aux = this->produtosDesenvolvidos.begin(); aux != this->produtosDesenvolvidos.end(); aux++){
        (*aux)->imprimeInfoProduto();
    }
}

void addProdutoDesenvolvido(Midia* produtoDesenvolvido) {
    this->produtosDesenvolvidos.push_back(produtoDesenvolvido);
}

void removeProdutosDesenvolvidos(Midia* produtosDesenvolvidos) {
    this->produtosDesenvolvidos.remove(produtoDesenvolvido);
}
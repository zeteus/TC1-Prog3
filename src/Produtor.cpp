#include "Produtor.hpp"

// Constructors
Produtor::Produtor() {}
Produtor::Produtor(std::string _name, int  codigo){
    this->setNome(_name);
    this->setCodigo(codigo);
}
// Destructor
Produtor::~Produtor() {
    this->produtosDesenvolvidos.clear(); //forma a composição
}

// Functions
void Produtor::printarNoArquivo(std::ofstream &outfile) {
    // fazer uma funcao pra printar aqui em amigo
    // TODO
}

std::list<Midia*> Produtor::getProdutosDesenvolvidos() {
    return this->produtosDesenvolvidos;
}

void Produtor::imprimeProdutosDesenvolvidos() {
    std::list<Midia*>::iterator aux;
    for(aux = this->produtosDesenvolvidos.begin(); aux != this->produtosDesenvolvidos.end(); aux++){
        (*aux)->printInfoProduto();
    }
}

void Produtor::addProdutoDesenvolvido(Midia* produtoDesenvolvido) {
    this->produtosDesenvolvidos.push_back(produtoDesenvolvido);
}

void Produtor::removeProdutosDesenvolvidos(Midia* produtoDesenvolvido) {
    this->produtosDesenvolvidos.remove(produtoDesenvolvido);
}
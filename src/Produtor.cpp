#include "Produtor.hpp"

// Constructors
Produtor::Produtor() {}
Produtor::Produtor(std::string _come, int  _codigo) : Usuario(_come, _codigo) {}
// Destructor
Produtor::~Produtor() {}

// Functions
void Produtor::printarNoArquivo(std::ofstream &outfile) {
    outfile << this->getNome() << ';' << this->getCodigo() << '\n';
}

std::list<Midia*> Produtor::getProdutosDesenvolvidos() {
    return this->produtosDesenvolvidos;
}

void Produtor::imprimeProdutosDesenvolvidos() {
    for(Midia *it : this->getProdutosDesenvolvidos())
        it->printInfoProduto();
}

void Produtor::addProdutoDesenvolvido(Midia* produtoDesenvolvido) {
    this->produtosDesenvolvidos.push_back(produtoDesenvolvido);
}

void Produtor::removeProdutosDesenvolvidos(Midia* produtoDesenvolvido) {
    this->produtosDesenvolvidos.remove(produtoDesenvolvido);
}
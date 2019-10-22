#include "Álbum.hpp"

// Constructor
Album::Album(std::string nome, int codigo, int duracao, int ano, int qtd) {
    this->setDuracao(duracao);
    this->setAnoLancamento(ano);
    this->setCodigo(codigo);
    this->setQuantidadeMusicas(qtd);
    this->setNome(nome);
}

Album::Album() {}

Album::~Album() {
    musics.clear(); //deleta todos os elementos da lista e libera o espaço da memória
                    //torna uma composição
}

// Overloading
void Album::printarNoArquivo(std::ofstream &_outfile) {
    _outfile << "ÁLBUM " << this->getNome() << std::endl;
    _outfile << "|DURACAO:" << this->getDuracao() << std::endl;
    _outfile << "|ANO DE LANCAMENTO:" << this->getAnoLancamento() << std::endl;
    _outfile << "|QTD MUSICAS:" << this->getQuantidadeMusicas() << std::endl;
    _outfile << "|CODIGO:" << this->getCodigo() << std::endl;
    _outfile << "______________________________________" << std::endl;
}

// Getters
int Album::getDuracao() {return this->duracao;}
int Album::getAnoLancamento() {return this->anoLancamento;}
int Album::getQuantidadeMusicas() {return this->quantidadeMusicas;}
int Album::getCodigo() {return this->codigo;}
std::string Album::getNome() {return this->nome;}

// Setters
void Album::setDuracao(int _duration) {this->duracao = _duration;}
void Album::setAnoLancamento(int _launchYear) {this->anoLancamento = _launchYear;}
void Album::setQuantidadeMusicas(int _musicAmount) {this->quantidadeMusicas = _musicAmount;}
void Album::setNome(std::string _name) {this->nome = _name;}
void Album::setCodigo(int codigo) {this->codigo = codigo;}
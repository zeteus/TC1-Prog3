#include "Podcast.hpp"

// Constructors
Podcast::Podcast() {}
Podcast::Podcast(std::string name, Genero* genre, int seasonsQnt) : Midia(name, rand(), genre) {
    this->setDuracao(rand());
    this->setAnoLancamento(rand());
    this->setQtdTemporadas(seasonsQnt);
}
// Destrutor
Podcast::~Podcast() {}

// Setter
void Podcast::setQtdTemporadas(int _qnt) {this->quantidadeTemporadas = _qnt;}

// Getter
int Podcast::getQtdTemporadas() {return this->quantidadeTemporadas;}

// Overloading
void Podcast::printarNoArquivo(std::ofstream &_outfile) {

}

void Podcast::printInfoProduto() {
    std::cout << "Nome: " << this->getNome() << std::endl;
    std::cout << "Codigo: " << this->getCodigo() << std::endl;
    std::cout << "Genero: " <<  this->getGenero()->getNome() << std::endl;
    std::cout << "Duração: " << this->getDuracao() << std::endl;
    std::cout << "Ano de Lançamento: " << this->getAnoLancamento() << std::endl;
    std::cout << "Seasons: " << this->getQtdTemporadas() << std::endl;
}
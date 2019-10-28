#include "Podcast.hpp"

// Constructors
Podcast::Podcast() {}
Podcast::Podcast(std::string name, int cod, Midia::Genero* genre, float duracao, int ano, int seasonsQnt) : Midia(name, cod, genre, duracao, ano) {
    this->setQtdTemporadas(seasonsQnt);
}
// Destrutor
Podcast::~Podcast() {}

// Setter
void Podcast::setQtdTemporadas(int _qnt) {this->quantidadeTemporadas = _qnt;}

// Getter
int Podcast::getQtdTemporadas() {return this->quantidadeTemporadas;}

// Overloading
void Podcast::printarNoArquivo(std::ofstream &outfile) {
    if(!outfile.is_open()) {
        std::cerr << "Erro de I/O" << std::endl;
        exit(1);
    }   
    
    outfile << this->getNome() << ";Música;";
    for(auto p : this->getProdutores()) {
        outfile << p->getCodigo();
        if(*this->getProdutores().rbegin() != p){ // Se não for o último
            outfile <<',';
        }
    }
    outfile << ';' << this->getDuracao() << ';' << this->getGenero()->getNome() << this->getQtdTemporadas() << ";;" << this->getAnoLancamento() << '\n';
}

// Overloading
void Podcast::printInfoProduto() {
    std::cout << "Nome: "               << this->getNome()                  << std::endl;
    std::cout << "Codigo: "             << this->getCodigo()                << std::endl;
    std::cout << "Genero: "             << this->getGenero()->getNome()     << std::endl;
    std::cout << "Ano de Lançamento: "  << this->getAnoLancamento()         << std::endl;
    std::cout << "Seasons: "            << this->getQtdTemporadas()         << std::endl;
}
char Podcast::getTipo() {return 'P';}
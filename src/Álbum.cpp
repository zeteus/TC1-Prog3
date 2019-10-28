#include "Álbum.hpp"

// Constructor
Album::Album(std::string nome, int codigo, float duracao, int ano, int qtd) {
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

void Album::addMusic(Musica* music) {
    this->setQuantidadeMusicas(this->getQuantidadeMusicas() + 1);
    this->getMusicas().push_back(music);
    this->setDuracao(this->getDuracao() + music->getDuracao());
    if (music->getAnoLancamento() > this->getAnoLancamento())
        this->setAnoLancamento(music->getAnoLancamento());
        // Atualiza ano de lançamento do álbum pro ano mais recente das músicas dele (???)
}

void Album::printMe() {
    std::cout << "ÁLBUM: " << this->getNome() << std::endl;
    std::cout << "|DURACAO:" << this->getDuracao() << std::endl;
    std::cout << "|ANO DE LANCAMENTO:" << this->getAnoLancamento() << std::endl;
    std::cout << "|QTD MUSICAS:" << this->getQuantidadeMusicas() << std::endl;
    std::cout << "|CODIGO:" << this->getCodigo() << std::endl;
    std::cout << "______________________________________" << std::endl;
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
float Album::getDuracao() {return this->duracao;}
int Album::getAnoLancamento() {return this->anoLancamento;}
int Album::getQuantidadeMusicas() {return this->quantidadeMusicas;}
int Album::getCodigo() {return this->codigo;}
std::string Album::getNome() {return this->nome;}
std::list<Musica*> Album::getMusicas() {return this->musics;}

// Setters
void Album::setDuracao(float _duration) {this->duracao = _duration;}
void Album::setAnoLancamento(int _launchYear) {this->anoLancamento = _launchYear;}
void Album::setQuantidadeMusicas(int _musicAmount) {this->quantidadeMusicas = _musicAmount;}
void Album::setNome(std::string _name) {this->nome = _name;}
void Album::setCodigo(int codigo) {this->codigo = codigo;}
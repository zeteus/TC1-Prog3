#include "PlataformaDigital.hpp"

// Constructors
PlataformaDigital::PlataformaDigital() {}
PlataformaDigital::PlataformaDigital(std::string _name) {
    this->setNome(_name);
}
// Destructor
PlataformaDigital::~PlataformaDigital() {}

// Functions
void PlataformaDigital::printProdutos(std::string _genre) {
    std::list<Midia*>::iterator it;
    for(it = this->produtosRegistrados.begin(); it != this->produtosRegistrados.end(); it++){
        (*it)->printInfoProduto();
    }
}

void PlataformaDigital::printAssinantes() {
    std::list<Assinante*>::iterator it;
    for(it = this->assinantes.begin(); it != this->assinantes.end(); it++){
        (*it)->printAssinante();
        std::cout << "Favoritos: " << std::endl;
        (*it)->printFavoritos();
    }
}
void PlataformaDigital::addAssinante(Assinante *_subscriber) {
    this->assinantes.push_back(_subscriber);
}

void PlataformaDigital::removeAssinante(Assinante*_subscriber) {
    this->assinantes.remove(_subscriber);
}

void PlataformaDigital::addProduto(Midia* _newProduct, std::list<Produtor*> _producers) {
    this->produtosRegistrados.push_back(_newProduct);
    std::list<Produtor*>::iterator it;
    for(it = this->produtores.begin(); it != this->produtores.end(); it++){
        this->produtores.push_back(*it);
    }
}

void PlataformaDigital::exportLibrary() { /* TODO: */}
void PlataformaDigital::generateReports() { /* TODO: */}

// Setters
void PlataformaDigital::setNome(std::string _name) {this->nome = _name;}
// Getters
std::list<Assinante*>PlataformaDigital::getAssinantes() {return this->assinantes;}
std::list<Midia*> PlataformaDigital::getProdutosRegistrados() {return this->produtosRegistrados;}
std::list<Produtor*> PlataformaDigital::getProdutores() {return this->produtores;}
std::list<Midia::Genero*> PlataformaDigital::getGeneros() {return this->generos;}
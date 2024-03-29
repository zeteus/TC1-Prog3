#include "Mídia.hpp"

int Midia::qtdProdutos = 0;      // Iniciando a variável estática ao carregar a classe

// Constructors
Midia::Midia() {}
Midia::Midia::Midia(std::string name, int cod, Genero* genre, float duracao, int ano){
    this->setNome(name);
    this->setCodigo(cod);
    this->setGenero(genre);
    this->setDuracao(duracao);
    this->setAnoLancamento(ano);
}
// Destructor
Midia::~Midia() {
    this->setQtdProdutos(this->getQtdProdutos() - 1);
}

// Functions
void Midia::addAssinante(Assinante *subscriber) {
    this->assinantes.push_back(subscriber);
}
void Midia::removeAssinante(Assinante *subscriber) {
    this->assinantes.remove(subscriber);
}
void Midia::addProdutor(Produtor* p) {
    this->produtores.push_back(p);
}


// Setters
void Midia::setNome(std::string name) {this->nome = name;}
void Midia::setCodigo(int _code) {this->codigo = _code;}
void Midia::setDuracao(float _duration) {this->duracao = _duration;}
void Midia::setAnoLancamento(int _launchYr) {this->anoLancamento = _launchYr;}
void Midia::setGenero(Midia::Genero *genero) {this->genero = genero;}
void Midia::setQtdProdutos(int qnt) {Midia::qtdProdutos = qnt;}
void Midia::setProdutores(std::list<Produtor*> prods) {this->produtores = prods;}

// Getters
std::string Midia::getNome() {return this->nome;}
int Midia::getCodigo() {return this->codigo;}
float Midia::getDuracao() {return this->duracao;}
int Midia::getAnoLancamento() {return this->anoLancamento;}
Midia::Genero* Midia::getGenero() {return this->genero;}
int Midia::getQtdProdutos() {return Midia::qtdProdutos;}
std::list<Produtor*> Midia::getProdutores() {return this->produtores;}

//---------GENERO ".cpp"
// Constructors
Midia::Genero::Genero() {}
Midia::Genero::Genero(std::string name, std::string sigla) {
    this->setNome(name);
    this->setSigla(sigla);
}
// Destructor
Midia::Genero::~Genero() {}

// Functions
void Midia::Genero::addMidia(Midia* midia) {
    this->midias.push_back(midia);
}
void Midia::Genero::removeMidia(Midia* midia) {
    this->midias.remove(midia);
}

// Setters
void Midia::Genero::setNome(std::string name) {this->nome = name;}
void Midia::Genero::setSigla(std::string sigla) {this->sigla = sigla;}

// Getters
std::string Midia::Genero::getNome() {return this->nome;}
std::string Midia::Genero::getSigla() {return this->sigla;}
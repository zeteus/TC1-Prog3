#include "Mídia.hpp"

int Midia::productQnt = 0;      // Iniciando a variável estática ao carregar a classe

// Constructors
Midia::Midia() {}
Midia::Midia(std::string name, int cod, Genero *genre){
}

// Destructor
Midia::~Midia() {
    this->genre->~Genero();    // Destroi o genero de dentro, para não perde referência
    this->setProductQnt(this->getProductQnt() - 1);
}

void Midia::printProductInfo() {}
void Midia::printarNoArquivo(std::ofstream &_outfile) {}
void Midia::loadFile(std::ifstream &_infile) {}

// Setters
void Midia::setProductQnt(int qnt) {Midia::productQnt = qnt;}
void Midia::setNome(std::string name) {this->name = name;}
void Midia::setGenre(Genero *genre) {this->genre = genre;}

// Getters
int Midia::getProductQnt() {return Midia::productQnt;}
std::string Midia::getNome() {return this->name;}
Midia::Genero* Midia::getGenre() {return this->genre;}

// Functions
void Midia::addSubscriber(Assinante* subscriber){};
void Midia::removeSubscriber(Assinante* subscriber){};
void Midia::addProducer(Produtor* producer){};

//---------GENERO ".cpp"
// Constructors
Midia::Genero::Genero() {}
Midia::Genero::Genero(std::string name, std::string abreviation) {
    this->setNome(name);
    this->setAbreviation(abreviation);
}

// Destructor
Midia::Genero::~Genero() {}

// Setters
void Midia::Genero::setNome(std::string name) {this->name = name;}
void Midia::Genero::setAbreviation(std::string abreviation) {this->abreviation = abreviation;}

// Getters
std::string Midia::Genero::getNome() {return this->name;}
std::string Midia::Genero::getAbreviation() {return this->abreviation;}
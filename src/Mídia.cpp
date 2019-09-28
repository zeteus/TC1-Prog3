#include "Mídia.hpp"

// Constructors
Midia::Midia() {}
Midia::Midia(std::string name, bool expl, std::string genre){
    this->setName(name);
    this->setIsExplicit(expl);
    this->setGenre(genre);
    this->setProductQnt(this->getProductQnt() + 1);
}

// Destructor
Midia::~Midia() {
    this->genre->~Genero();    // Destroi o genero de dentro, para não perde referência
    this->setProductQnt(this->getProductQnt() - 1);
}

void Midia::printProductInfo() {}
void Midia::printOnFile(std::ofstream &_outfile) {}
void Midia::loadFile(std::ifstream &_infile) {}

// Setters
void Midia::setProductQnt(int qnt) {Midia::productQnt = qnt;}
void Midia::setIsExplicit(bool expl) {this->isExplicit = expl;}
void Midia::setName(std::string name) {this->name = name;}
void Midia::setGenre(Genero *genre) {this->genre = genre;}
void Midia::setGenre(std::string genreName) {           // legibilizar o constructor
    Genero *genre = new Genero(genreName, genreName);   //? Como gerar a abreviação?
    this->genre = genre;
}

// Getters
int Midia::getProductQnt() {return Midia::productQnt;}
bool Midia::getIsExplicit() {return this->isExplicit;}
std::string Midia::getName() {return this->name;}
Midia::Genero* Midia::getGenre() {return this->genre;}

//---------GENERO ".cpp"
// Constructors
Midia::Genero::Genero() {}
Midia::Genero::Genero(std::string name, std::string abreviation){
    this->setName(name);
    this->setAbreviation(abreviation);
}

// Destructor
Midia::Genero::~Genero() {}

// Setters
void Midia::Genero::setName(std::string name) {this->name = name;}
void Midia::Genero::setAbreviation(std::string abreviation) {this->abreviation = abreviation;}

// Getters
std::string Midia::Genero::getName() {return this->name;}
std::string Midia::Genero::getAbreviation() {return this->abreviation;}

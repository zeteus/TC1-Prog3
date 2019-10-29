#include "Música.hpp"

// Constructors
Musica::Musica() {}
Musica::Musica(std::string name, int cod, Midia::Genero* genre, float duracao, int ano) : Midia(name, cod, genre, duracao, ano) {
    setAlbum(NULL);
}
// Destructor
Musica::~Musica() {}

// Setter
void Musica::setAlbum(Album* a) {this->album = a;}
// Getter
Album* Musica::getAlbum() {return this->album;}

// Functions
char Musica::getTipo() {return 'M';}

// Overloading
void Musica::printInfoProduto() {
    std::cout << "Nome: "               << this->getNome()                  << std::endl;
    std::cout << "Codigo: "             << this->getCodigo()                << std::endl;
    std::cout << "Genero: "             <<  this->getGenero()->getNome()    << std::endl;
    std::cout << "Duração: "            << this->getDuracao()               << std::endl;
    std::cout << "Ano de Lançamento: "  << this->getAnoLancamento()         << std::endl;
}

void Musica::printarNoArquivo(std::ofstream &outfile) {
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
    outfile << ';' << this->getDuracao() << ';' << this->getGenero()->getNome() << ";;";    // ;; -> ñ tem temporada
    if(this->getAlbum() != NULL)
        outfile << this->getAlbum()->getCodigo();
    outfile << ';' << this->getAnoLancamento() << '\n';

}
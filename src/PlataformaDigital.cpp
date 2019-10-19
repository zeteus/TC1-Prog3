#include "PlataformaDigital.hpp"

// Constructors
PlataformaDigital::PlataformaDigital() {}
PlataformaDigital::PlataformaDigital(std::string _name) {
    this->setNome(_name);
}
// Destructor
PlataformaDigital::~PlataformaDigital() {
    std::list<Midia::Genero*>::iterator itGeneros;
    for(itGeneros = this->generos.begin(); itGeneros != this->generos.end(); itGeneros++)
        delete (*itGeneros);
    this->generos.clear();
    std::list<Assinante*>::iterator itAssinantes;
    for(itAssinantes = this->assinantes.begin(); itAssinantes != this->assinantes.end(); itAssinantes++)
        delete (*itAssinantes);
    this->assinantes.clear();
    std::list<Produtor*>::iterator itProdutores;
    for(itProdutores = this->produtores.begin(); itProdutores != this->produtores.end(); itProdutores++)
        delete (*itProdutores);
    this->produtores.clear();
    std::list<Album*>::iterator itAlbumsCadastrados;
    for(itAlbumsCadastrados = this->albumsCadastrados.begin(); itAlbumsCadastrados != this->albumsCadastrados.end(); itAlbumsCadastrados++)
        delete (*itAlbumsCadastrados);
    this->albumsCadastrados.clear();
    std::list<Midia*>::iterator itProdutosRegistrados;
    for(itProdutosRegistrados = this->produtosRegistrados.begin(); itProdutosRegistrados != this->produtosRegistrados.end(); itProdutosRegistrados++)
        delete (*itProdutosRegistrados);
    this->produtosRegistrados.clear();
}

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

void PlataformaDigital::removeAssinante(Assinante *_subscriber) {
    this->assinantes.remove(_subscriber);
    delete _subscriber;
}

void PlataformaDigital::addProduto(Midia* _newProduct, std::list<Produtor*> _producers) {
    this->produtosRegistrados.push_back(_newProduct);
    std::list<Produtor*>::iterator it;
    for(it = this->produtores.begin(); it != this->produtores.end(); it++){
        this->produtores.push_back(*it);
    }
}

void PlataformaDigital::addAlbum(Album *album) {
    this->albumsCadastrados.push_back(album);
}

void PlataformaDigital::printGeneros() {
    std::list<Midia::Genero*>::iterator it;
    for(it = this->generos.begin(); it != this->generos.end(); it++)
        std::cout << (*it)->getNome() << ';' << (*it)->getSigla() << std::endl;
}

// File
void PlataformaDigital::loadFileUsuarios(std::ifstream &infile) {

}
void PlataformaDigital::loadFileGeneros(std::ifstream &infile) {
    if(!infile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de genero! Saindo do programa..." << std::endl;
        exit(1);
    }

    std::string sigla;
    std::string nome;
    std::string str;
    std::stringstream ss;
    std::getline(infile, sigla);
    while(!infile.eof()) {
        getline(infile, str);
        if(str.empty()){
            std::cout << "Jordana" << std::endl;
            break;
        }
        std::cout << "Berilhes";
        ss = std::stringstream(str);
        getline(ss, sigla, ';');
        getline(ss, nome);
        this->generos.push_back(new Midia::Genero(nome, sigla));
        
    }
}

void PlataformaDigital::loadFileMidias(std::ifstream &infile) {
    if(!infile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de midias! Saindo do programa..." << std::endl;
        exit(1);
    }

    infile.ignore(5000, '\n');   //ignora a primeira linha
    std::stringstream ss, ss2;
    std::string str;

    std::string nome, nomeAlbum, gen;
    int cod, temp, codAlbum, ano;
    std::list<int> codProdutores;
    char type;
    float duracao;
    size_t pos = -1;
    while(!infile.eof()) {
        try {
        getline(infile, str);
        if(str.compare("\n"))
            break;
            // std::cout << str << std::endl;
        ss = std::stringstream(str, std::ios::in);
        getline(ss, str, ';');
        cod = std::stoi(str);
            std::cout << "Codigo: " << cod << std::endl;
        getline(ss, nome, ';');
            std::cout << "Nome: " << nome << std::endl;
        getline(ss, str, ';');
            // std::cout << str << std::endl;
        type = str.at(0);
            std::cout << "Tipo: " << type << std::endl;
        getline(ss, str, ';');
            std::cout << "Prod (antes de separar): " << str << std::endl;
        ss2 = std::stringstream(str, std::ios::in);
        while(ss2 >> str) {
            while ((pos = str.rfind(',')) != std::string::npos) {   //acha as vírgulas
                str.erase(pos, 1);  //apaga os caracteres não vírgula, até a vírgula
            }
            codProdutores.push_back(stoi(str));
        }
            std::cout << "Produtores: ";
            std::list<int>::iterator it;
            for(it = codProdutores.begin(); it != codProdutores.end(); it++) {
                std::cout << *it << std::endl;
            }
        getline(ss, str, ';');
            // std::cout << str << std::endl;
        pos = str.find(',');
            // std::cout << pos << std::endl;
        if(pos != std::string::npos)
            str.replace(pos, 1, 1, '.');
        duracao = std::stof(str);
            std::cout << "Duração: " << duracao << std::endl;
        getline(ss, str, ';');
            std::cout << "Gênero (antes de separar): " << str << std::endl;
        if((pos = str.find(',')) != std::string::npos)
            str.erase(pos, std::string::npos);
        gen = str;
            std::cout << "Gênero: " << gen << std::endl;
        getline(ss, str, ';');
            std::cout << "Temporadas str: " << str << std::endl;
        if(!str.empty())
            temp = stoi(str);
        else
            temp = 0;
        std::cout << "Temporadas: " << temp << std::endl;
        getline(ss, nomeAlbum, ';');
            std::cout << "Album str: " << nomeAlbum << std::endl;
        if(nomeAlbum.empty())
            nomeAlbum = "\0";
        std::cout << "Album: " << nomeAlbum << std::endl;
        getline(ss, str, ';');
            std::cout << "codAlbum str: " << str << std::endl;
        if(!str.empty())
            codAlbum = stoi(str);
        else
            codAlbum = 0;
            std::cout << "codAlbum: " << codAlbum << std::endl;
        getline(ss, str, '\n');
        ano = stoi(str);
            std::cout << "Ano: " << str << std::endl;
            std::cout << "--------------------------" << std::endl << std::endl;

        Midia::Genero *cGenero = new Midia::Genero(gen, gen);
        switch(type)
            case 'M':
                Midia *cMidia = new Musica(nome, cGenero, duracao, ano);


        codProdutores.clear(); // reseta a lista de produtores pra ser usada novamente
        } catch(std::invalid_argument) {
            std::cerr << _BOLDRED << "Alguma entrada no arquivo de mídia parece estranha! Linha de código de mídia " << cod << "ou a próxima." << _RESET << std::endl;
        }
    }
}

void PlataformaDigital::loadFileFavoritos(std::ifstream &infile) {}

void PlataformaDigital::exportLibrary() { /* TODO: */}
void PlataformaDigital::generateReports() { /* TODO: */}

// Setters
void PlataformaDigital::setNome(std::string _name) {this->nome = _name;}
// Getters
std::list<Assinante*>PlataformaDigital::getAssinantes() {return this->assinantes;}
std::list<Midia*> PlataformaDigital::getProdutosRegistrados() {return this->produtosRegistrados;}
std::list<Produtor*> PlataformaDigital::getProdutores() {return this->produtores;}
std::list<Midia::Genero*> PlataformaDigital::getGeneros() {return this->generos;}
std::list<Album*> PlataformaDigital::getAlbumsCadastrados() {return this->albumsCadastrados;}
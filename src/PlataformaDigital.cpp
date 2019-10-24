#include "PlataformaDigital.hpp"

// Constructors
PlataformaDigital::PlataformaDigital() {}
PlataformaDigital::PlataformaDigital(std::string _name) {
    this->setNome(_name);
}
// Destructor
PlataformaDigital::~PlataformaDigital() {
    for(Midia::Genero* itGeneros : this->getGeneros())
        delete itGeneros;
    this->generos.clear();

    for(Assinante* itAssinantes : this->getAssinantes())
        delete itAssinantes;
    this->assinantes.clear();

    for(Produtor* itProdutores : this->getProdutores())
        delete itProdutores;
    this->produtores.clear();

    for(Album* itAlbumsCadastrados : this->getAlbumsCadastrados())
        delete itAlbumsCadastrados;
    this->albumsCadastrados.clear();

    for(Midia* itProdutosRegistrados : this->getProdutosRegistrados())
        delete itProdutosRegistrados;
    this->produtosRegistrados.clear();
}

// Functions
void PlataformaDigital::printProdutos(std::string _genre) { //TODO: ignorando o gênero por enquanto
    for(Midia *it : this->getProdutosRegistrados()){
        std::cout << "CARALHO " << std::endl;
        it->printInfoProduto();
    }
}

void PlataformaDigital::addProduto(Midia* _newProduct, std::set<Produtor*> _producers) {
    this->produtosRegistrados.insert(_newProduct);
    for(Produtor *it : _producers)
        this->produtores.insert(it);
    std::cout << "PORRA " << std::endl;
}

void PlataformaDigital::printAssinantes() {
    for(Assinante *it : this->getAssinantes()){
        it->printInfo();
        std::cout << "Favoritos: " << std::endl;
        it->printFavoritos();
    }
}

void PlataformaDigital::printProdutores() {
    for(Produtor *it : this->getProdutores())
        it->printInfo();
}


void PlataformaDigital::addAssinante(Assinante *_subscriber) {
    this->assinantes.insert(_subscriber);
}

void PlataformaDigital::removeAssinante(Assinante *_subscriber) {
    this->assinantes.erase(_subscriber);
    delete _subscriber;
}

void PlataformaDigital::addAlbum(Album *album) {
    this->albumsCadastrados.insert(album);
}

void PlataformaDigital::printGeneros() {
    for(Midia::Genero* it : this->getGeneros())
        std::cout << it->getNome() << ';' << it->getSigla() << std::endl;
}

// File
void PlataformaDigital::loadFileUsuarios(std::ifstream &infile) {
    if(!infile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de usuarios! Saindo do programa..." << std::endl;
        exit(1);
    }
    int codigo;
    std::string str, nome;
    char tipo;
    std::stringstream ss;
    infile.ignore(5000, '\n');   //ignora a primeira linha

    while(!infile.eof()) {
        getline(infile, str);
        if(str.empty())
            break;
        ss = std::stringstream(str);
        // ss.getline
        getline(ss, str, ';');
        try{
            codigo = stoi(str);
        } catch(std::invalid_argument) {
            std::cerr << _BOLDRED << "Alguma entrada no arquivo de usuário parece estranha! Linha de código de usuário " << codigo << "ou a anterior." << _RESET << std::endl;
            exit(1);
        }
        getline(ss, str, ';');
        tipo = str.at(0);
        getline(ss, nome);

        // Usuario *u;
        Usuario *u;
        switch(tipo) {
            case 'U':
            case 'u':
                // u = new Usuario(nome, codigo);
                // ele pensa que pode existir, coitado
                // std::cout << "SORRIZO RONALDO" << std::endl;
            break;
            case 'P':
            case 'p':
                u = new Produtor(nome, codigo);
                this->produtores.insert((Produtor*) u);
                // std::cout << "DESGRAÇADO" << std::endl;
            break;
            case 'A':
            case 'a':
                u = new Assinante(nome, codigo);
                this->assinantes.insert((Assinante*) u);
                // std::cout << "FILHO DA PUTA" << std::endl;
            break;
            default:
                std::cerr << _BOLDRED << "Tipo de usuário inválido! Cheque o primeiro usuário de código " << codigo << "." << std::endl;
        }
    }
    infile.close();
}
void PlataformaDigital::loadFileGeneros(std::ifstream &infile) {
    if(!infile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de generos! Saindo do programa..." << std::endl;
        exit(1);
    }

    std::string sigla;
    std::string nome;
    std::string str;
    std::stringstream ss;
    infile.ignore(5000, '\n');   //ignora a primeira linha
    try{
        while(!infile.eof()) {
            getline(infile, str);
            if(str.empty()){
                    // std::cout << "Jordana" << std::endl;
                break;
            }
                // std::cout << "Berilhes";
            ss = std::stringstream(str);
            getline(ss, sigla, ';');
            getline(ss, nome);
            this->getGeneros().insert(new Midia::Genero(nome, sigla));
            
        }
    } catch(std::invalid_argument) {
            std::cerr << _BOLDRED << "Alguma entrada no arquivo de gênero parece estranha! Linha de gênero " << sigla << "ou a anterior." << _RESET << std::endl;
            exit(1);
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
            // std::cout << "Nome: " << nome << std::endl;
        getline(ss, str, ';');
            // std::cout << str << std::endl;
        type = str.at(0);
            // std::cout << "Tipo: " << type << std::endl;
        getline(ss, str, ';');
            // std::cout << "Prod (antes de separar): " << str << std::endl;
        ss2 = std::stringstream(str, std::ios::in);
        while(ss2 >> str) {
            while ((pos = str.rfind(',')) != std::string::npos) {   //acha as vírgulas
                str.erase(pos, 1);  //apaga os caracteres não vírgula, até a vírgula
            }
            codProdutores.push_back(stoi(str));
        }
            // std::cout << "Produtores: ";
            std::list<int>::iterator it;
            for(it = codProdutores.begin(); it != codProdutores.end(); it++) {
                // std::cout << *it << std::endl;
            }
        getline(ss, str, ';');
            // std::cout << str << std::endl;
        pos = str.find(',');
            // std::cout << pos << std::endl;
        if(pos != std::string::npos)
            str.replace(pos, 1, 1, '.');
        duracao = std::stof(str);
            // std::cout << "Duração: " << duracao << std::endl;
        getline(ss, str, ';');
            // std::cout << "Gênero (antes de separar): " << str << std::endl;
        if((pos = str.find(',')) != std::string::npos)
            str.erase(pos, std::string::npos);
        gen = str;
            // std::cout << "Gênero: " << gen << std::endl;
        getline(ss, str, ';');
            // std::cout << "Temporadas str: " << str << std::endl;
        if(!str.empty())
            temp = stoi(str);
        else
            temp = 0;
            // std::cout << "Temporadas: " << temp << std::endl;
        getline(ss, nomeAlbum, ';');
            // std::cout << "Album str: " << nomeAlbum << std::endl;
        if(nomeAlbum.empty())
            nomeAlbum = "\0";
        // std::cout << "Album: " << nomeAlbum << std::endl;
        getline(ss, str, ';');
            // std::cout << "codAlbum str: " << str << std::endl;
        if(!str.empty())
            codAlbum = stoi(str);
        else
            codAlbum = 0;
            // std::cout << "codAlbum: " << codAlbum << std::endl;
        getline(ss, str, '\n');
        ano = stoi(str);
            // std::cout << "Ano: " << str << std::endl;
            // std::cout << "--------------------------" << std::endl << std::endl;

        std::set<Midia::Genero*>::iterator itGeneros;
        for(itGeneros = this->generos.begin(); itGeneros != this->generos.end(); itGeneros++) {
            if((*itGeneros)->getNome().compare(gen))
            std::cout << "Genero já existe" << std::endl;
            break;
        }
        Midia::Genero *cGenero;
        if(itGeneros != this->generos.end())
            cGenero = new Midia::Genero(gen, gen);
        else cGenero = *itGeneros;

        Midia *cMidia;
        switch(type) {
            case 'M':
                cMidia = new Musica(nome, cGenero, duracao, ano);
                break;
            case 'P':
                cMidia = new Podcast(nome, cGenero, temp);
                break;
            default:
                std::cerr << _BOLDRED << "Algo de errado ao criar as mídias. Cheque o arquivo de entrada." << _RESET << std::endl << "A que causou problema foi: " << std::endl << "Cód " << cod << " Nome " << nome << " Gen " << gen << std::endl;
        }


        std::set<Produtor*>::iterator itProdutorPlat;
        std::list<int>::iterator itProdutorInt;
        for(itProdutorPlat = this->produtores.begin(); itProdutorPlat != this->produtores.end(); itProdutorPlat++) {
// TODO: criar os produtores ou sei lá oq
        }

        // this->addProduto(cMidia,);

        // codProdutores.clear(); // reseta a lista de produtores pra ser usada novamente
        } catch(std::invalid_argument) {
            std::cerr << _BOLDRED << "Alguma entrada no arquivo de mídia parece estranha! Linha de código de mídia " << cod << "ou a anterior." << _RESET << std::endl;
        }
    }
}

void PlataformaDigital::loadFileFavoritos(std::ifstream &infile) {}

void PlataformaDigital::exportLibrary()   { /* TODO: */}
void PlataformaDigital::generateReports() { /* TODO: */}

// Setters
void PlataformaDigital::setNome(std::string _name) {this->nome = _name;}
// Getters
std::set<Assinante*>PlataformaDigital::getAssinantes()        {return this->assinantes;}
std::set<Midia*> PlataformaDigital::getProdutosRegistrados()  {return this->produtosRegistrados;}
std::set<Produtor*> PlataformaDigital::getProdutores()        {return this->produtores;}
std::set<Midia::Genero*> PlataformaDigital::getGeneros()      {return this->generos;}
std::set<Album*> PlataformaDigital::getAlbumsCadastrados()    {return this->albumsCadastrados;}
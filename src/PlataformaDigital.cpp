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
        it->printInfoProduto();
    }
}

void PlataformaDigital::addProduto(Midia* _newProduct, std::set<Produtor*> _producers) {
    this->produtosRegistrados.insert(_newProduct);
    for(Produtor *it : _producers)
        this->produtores.insert(it);
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
            this->generos.insert(new Midia::Genero(nome, sigla));
            
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

    // Ignora a primeira linha
    infile.ignore(5000, '\n');

    // Inicia as strings auxiliares
    std::stringstream ss, ss2;
    std::string str;

    // Inicia as variaveis finais
    std::string nome;
    std::string nomeAlbum;
    std::string gen;
    int cod;
    int temp;
    int codAlbum;
    int ano;
    char type;
    float duracao;
    std::set<int> codProdutores;
    std::list<std::string> listGen;
    size_t pos = -1;

    while(getline(infile, str)) {
        try {
        ss = std::stringstream(str);

        // Lê o código
        getline(ss, str, ';');
        cod = std::stoi(str);

        // Lê o nome
        getline(ss, nome, ';');

        // Lê o tipo
        getline(ss, str, ';');
        // Seleciona  o primeiro char de 'str'
        type = str.at(0);

        // Cria uma lista de produtores
        getline(ss, str, ';');
        ss2 = std::stringstream(str);
        while(ss2 >> str) {
            while ((pos = str.rfind(',')) != std::string::npos) {   //acha as vírgulas
                str.erase(pos, 1);  //apaga os caracteres não vírgula, até a última vírgula
            }
            codProdutores.insert(stoi(str));
        }

        // Lê a duração
        getline(ss, str, ';');
        pos = str.find(',');
        if(pos != std::string::npos)
            // Troca a vírgula por um ponto, para converter para float
            str.replace(pos, 1, 1, '.');
        duracao = std::stof(str);

        // Cria uma lista de gêneros
        getline(ss, str, ';');
        ss2 = std::stringstream(str);
        while(ss2 >> str) {
            while ((pos = str.rfind(',')) != std::string::npos) {   //acha as vírgulas
                str.erase(pos, 1);  //apaga os caracteres não vírgula, até a última vírgula
            }
            listGen.push_back(str);
        }

        // Lê a temporada
        getline(ss, str, ';');
        temp = !str.empty() ? stoi(str) : 0;

        // Lê o Álbum
        getline(ss, nomeAlbum, ';');

        // Lê o código do Álbum
        getline(ss, str, ';');
        codAlbum = !str.empty() ? stoi(str) : 0;

        // Lê o Ano de Publicação
        getline(ss, str, '\n');
        ano = stoi(str);
        
        } catch(std::invalid_argument) {
            std::cerr << _BOLDRED << "Alguma entrada no arquivo de mídia parece estranha! Linha de código de mídia " << cod << "ou a anterior." << _RESET << std::endl;
        }

        // Cria uma mídia para ser definida
        Midia *midia;
        // Verifica se algun genero da lista existe
        Midia::Genero *genre = NULL;
            for(std::string itstr : listGen){
                for(Midia::Genero *itgen : this->getGeneros())
                    // Gênero encontrado
                    if(itgen->getSigla() == itstr){
                        genre = itgen;
                        break;
                    }
                // Gênero foi encontrado
                if(genre != NULL) break;
            }
            // Genero não existe
            if(genre == NULL) break;

        // Verifica se algum produtor da lista existe
        std::set<Produtor*> setProdutores;
            for(int itProdInt : codProdutores)
                for(Produtor *itProdPlat : this->getProdutores())
                    if(itProdPlat->getCodigo() == itProdInt) // Produtor encontrado
                        setProdutores.insert(itProdPlat);

        switch(type) {
            case 'P':
            case 'p':                
                midia = new Podcast(nome, genre, temp);
            break;
            case 'M':
            case 'm':
                midia = new Musica(nome, genre, duracao, ano);
            break;
        }
        
        if(!setProdutores.empty())
            this->addProduto(midia, setProdutores);
        else
            std::cout << "Produtor VAZIO!!!\n";
        

        codProdutores.clear();
        setProdutores.clear();
        listGen.clear();
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
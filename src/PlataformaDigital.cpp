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
void PlataformaDigital::printProdutos() {
    for(Midia *it : this->getProdutosRegistrados())
        it->printInfoProduto();
}

void PlataformaDigital::printProdutos(std::string _genre) {
    for(Midia *it : this->getProdutosRegistrados()){
        if(it->getGenero()->getSigla() == _genre || it->getGenero()->getNome() == _genre)
            it->printInfoProduto();
    }
}

std::list<Midia*> PlataformaDigital::getProdutos(std::string gen) {
    std::list<Midia*> produtos;
    for(auto &it : this->getProdutosRegistrados())
        if(it->getGenero()->getNome() == gen)
            produtos.push_back(it);
    return produtos;
}

void PlataformaDigital::addProduto(Midia* _newProduct, std::set<Produtor*> _producers) {
    this->produtosRegistrados.insert(_newProduct);
    for(Produtor *it : _producers) {
        this->produtores.insert(it);
        it->addProdutoDesenvolvido(_newProduct);
    }
}

void PlataformaDigital::printAssinantes() {
    for(Assinante *it : this->getAssinantes()){
        it->printInfo();
        std::cout << "Favoritos: " << std::endl;
        it->printFavoritos();
        std::cout << "---------------------" << std::endl;
    }
}

void PlataformaDigital::printProdutores() {
    for(Produtor *it : this->getProdutores())
        it->printInfo();
}

void PlataformaDigital::printAlbuns() {
    for(Album *itAlbum : this->getAlbumsCadastrados()) {
        itAlbum->printMe();
        std::cout << std::endl;
    }
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
                u = new Assinante(nome, codigo);
                this->assinantes.insert((Assinante*) u);
            break;
            case 'P':
            case 'p':
                u = new Podcaster(nome, codigo);
                this->produtores.insert((Produtor*) u);
            break;
            case 'A':
            case 'a':
                u = new Artista(nome, codigo);
                this->produtores.insert((Produtor*) u);
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
            if(str.empty())
                continue;
            ss = std::stringstream(str);
            getline(ss, sigla, ';');
            getline(ss, nome, '\n');
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
            codProdutores.insert(std::stoi(str));
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

        std::set<Produtor*> setProdutores;
        Produtor* p = NULL;
        // Assumindo que todos os produtores da lista são diferentes
        // (Não há dupla entrada de produtores)
        // Para cada produtor de entrada...
        for(int pCod : codProdutores) {
            // ... percorre os produtores registrados...
            for(Produtor *produtorPlataforma : this->getProdutores()) {
                // ...e encontra o de mesmo código
                if(produtorPlataforma->getCodigo() == pCod)
                    p = produtorPlataforma;
            }
            // Caso não tenha encontrado
            if(p == NULL)
                p = new Produtor("Artista desconhecido", pCod);
            setProdutores.insert(p);
        }

        // Verifica se algum genero da lista existe
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

        Midia *midia;
        switch(type) {
            case 'P':
            case 'p':
                midia = new Podcast(nome, cod, genre, temp, ano, duracao);
            break;
            case 'M':
            case 'm':
                Album *albumDaMusica = NULL;
                if(codAlbum != 0) {
                    for (Album *itAlbuns : this->getAlbumsCadastrados())
                        if (itAlbuns->getCodigo() == codAlbum) {
                            nomeAlbum = itAlbuns->getNome();
                            albumDaMusica = itAlbuns;
                            break;
                        }

                    if (albumDaMusica == NULL) {    // Não foi encontrado álbum já existente para a música
                        albumDaMusica = new Album(nomeAlbum, codAlbum, duracao, ano, 1);
                        this->addAlbum(albumDaMusica);
                    }
                    }

                midia = new Musica(nome, cod, genre, duracao, ano, duracao);

                if(codAlbum != 0)
                    albumDaMusica->addMusic((Musica*) midia);

            break;
        }

        if(!setProdutores.empty())
            this->addProduto(midia, setProdutores);
        else {
            std::cout << _BOLDRED << "Lista de produtores VAZIA!!!" << _RESET << std::endl;
        }

        // Mídia já está pronta

        codProdutores.clear();
        setProdutores.clear();
        listGen.clear();
    }
}


void PlataformaDigital::loadFileFavoritos(std::ifstream &infile) {
    if(!infile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de favoritos! Saindo do programa..." << std::endl;
        exit(1);
    }



    // Definição de variável
    std::stringstream ss;
    std::string str;
    std::set<int> setFavoritos;
    int cod;
    size_t pos = -1;

    getline(infile, str);    // Ignora a primeira linha
    while(getline(infile, str, '\n')){
        ss = std::stringstream(str);
        // Lê o codigo
        getline(ss, str, ';');

        if(!str.empty())
            try {
                cod = std::stoi(str);
                // Se o último caractere de 'ss' não for ';'
                // i.e. se a lista de favoritos não for vazia)
                if(ss.str().size() - str.size() - 2 != 0) {
                    while(getline(ss, str, ','))
                        if(!str.empty())
                            setFavoritos.insert(std::stoi(str));
                } else continue;

            } catch (const std::invalid_argument& e){
                std::cerr << _BOLDRED << "Alguma entrada no arquivo de favoritos parece estranha! Argumento de stoi inválido! Cód de entrada: " << cod + 1 << " ou a anterior." << _RESET << std::endl;
                std::cerr << "Erro: " << e.what() << std::endl;
                exit(1);
            }  catch (const std::out_of_range& e){
                std::cerr << _BOLDRED << "Alguma entrada no arquivo de favoritos parece estranha! Stoi out of range! Cód de entrada: " << cod  + 1<< " ou a anterior." << _RESET << std::endl;
                std::cerr << "Erro: " << e.what() << std::endl;
                exit(1);
            }


        // Procurando o assinante
        Assinante *a = NULL;
        for(Assinante *Aaux : this->getAssinantes())
            if(Aaux->getCodigo() == cod)
                a = Aaux;
        if(a == NULL)   // Não foi encontrado assinante
            continue;   // Passa para a próxima linha

        // Procurando as mídias
        Midia *favmidia = NULL;
        // Pra cada código em 'setFavoritos'...
        for(int codMidia : setFavoritos)
            // ...busca a respectiva mídia...
            for(Midia *midia : this->getProdutosRegistrados())
                if(midia->getCodigo() == codMidia)
                    //  ...e a adiciona no assinante.
                    a->inserirFavorito(midia);
        // encontrar o usuário com o código lido e inserir a mídia

        setFavoritos.clear();
    }
}

bool cmp_codAss(Assinante *a, Assinante *b) {
    return a->getCodigo() < b->getCodigo();
}

bool cmp_nomesMidia(Midia *a, Midia *b) {
    return a->getNome() < b->getNome();
}


bool cmp_nomesProd(Produtor *a, Produtor *b) {
    return a->getNome() < b->getNome();
}

void PlataformaDigital::exportLibrary()   {}
void PlataformaDigital::generateReports() {
    std::ofstream filestats;
    std::ofstream fileprods;
    std::ofstream filefavs;
    filestats.open("output/1-estatisticas.txt", std::ios::out);
    fileprods.open("output/2-produtores.csv", std::ios::out);
    filefavs.open("output/3-favoritos.csv", std::ios::out);
    if(!(filestats.is_open() && fileprods.is_open() && filefavs.is_open())) {
        std::cerr << _BOLDRED << "Verifique se a pasta \"output\" existe no diretório de onde está executando o programa." << _RESET << std::endl;
        exit(1);
    }

    float tempo = 0;

    for(Assinante *itAssinante : this->getAssinantes()) {
        for(Midia *itMidia : itAssinante->getFavoritos()) {
            tempo += itMidia->getDuracao();
        }
    }
    std::stringstream ss;
    std::string str;

    size_t pos;
    ss << tempo;
    getline(ss, str);
    pos = str.find('.');
    if(pos != std::string::npos)
            // Troca o ponto por uma vírgula
            str.replace(pos, 1, 1, ',');

    filestats << "Horas Consumidas: " << str << std::endl << std::endl;

    str.clear();
    tempo = 0;

    std::unordered_map<Midia::Genero*,unsigned int> mapGeneros;
    for(Midia::Genero *itGen : this->getGeneros()) {
        for(Midia *itMidia : this->getProdutosRegistrados()) {
            if(itMidia->getGenero() == itGen)
                mapGeneros[itGen]++;
        }
    }

    std::pair<Midia::Genero*,unsigned int> genMaisOuvido;
    for(std::pair<Midia::Genero*,unsigned int> it : mapGeneros)
        if(it.second > genMaisOuvido.second)
            genMaisOuvido = it;

    std::map<unsigned int, Midia::Genero*> mapGenerosOrd;
    float duracaoGenMaisOuvido = 0;
    for(auto &it : this->getProdutos(genMaisOuvido.first->getNome())) {
        duracaoGenMaisOuvido += it->getDuracao();
    }

    filestats << "Gênero mais ouvido: " <<  genMaisOuvido.first->getNome() << " - " << duracaoGenMaisOuvido << " minutos\n\n";

    filestats << "Mídias por Gêneros:\n";

    for(std::pair<Midia::Genero*,unsigned int> itMap : mapGeneros)
        filestats << itMap.first->getSigla() << ':' << itMap.second << '\n';

    filestats << "\nTop 10 Mídias:\n";

    std::unordered_map<Midia*,int> mapMidias;
    for(auto &itAssinante : this->getAssinantes()) {
        for(auto &itFav : itAssinante->getFavoritos())
            mapMidias[itFav]++;
    }

    std::unordered_map<Midia*,int> mapMidias2 = mapMidias;

    int cont = 0;
    while(!mapMidias.empty() && cont < 10) {
        std::pair<Midia*,int> maisOcorre;
        for(auto &it : mapMidias) {
            if(it.second > maisOcorre.second)
                maisOcorre = it;
        }
        filestats << maisOcorre.first->getNome() << ':' << maisOcorre.first->getGenero()->getNome() << ':' << maisOcorre.second << '\n';
        mapMidias.erase(maisOcorre.first);
        cont++;
    }
    mapMidias.clear();

    filestats << "\nTop 10 Produtores:\n";

    for(auto &itAssinante : this->getAssinantes()) {
        for(auto &itFav : itAssinante->getFavoritos())
            mapMidias[itFav]++;
    }

    std::unordered_map<Produtor*,int> mapProdutores;
    for(auto &itProd : this->getProdutores()) {
        for(auto &itMidia : itProd->getProdutosDesenvolvidos()) {
            mapProdutores[itProd] += mapMidias2[itMidia];
        }
    }

    cont = 0;
    while(!mapProdutores.empty() && cont < 10) {
        std::pair<Produtor*,int> maisOcorre;
        for(auto &it : mapProdutores) {
            if(it.second > maisOcorre.second)
                maisOcorre = it;
        }
        filestats << maisOcorre.first->getNome() << ':' << maisOcorre.second << '\n';
        mapProdutores.erase(maisOcorre.first);
        cont++;
    }

    filestats.close();

    std::list<Produtor*> produtoresOrd;
    for(auto &itProdPlat : this->getProdutores())
            produtoresOrd.push_back(itProdPlat);

    produtoresOrd.sort(cmp_nomesProd);

    std::list<Midia*> jordana;
    for(auto &p : produtoresOrd) {
        for(auto &m : p->getProdutosDesenvolvidos())
            jordana.push_back(m);
        jordana.sort(cmp_nomesMidia);
        fileprods << p->getNome() << ';';
        for(auto &m : jordana) {
            fileprods << m->getNome();
            if(!(m == *jordana.rbegin()))
                fileprods << ", ";
        }
        jordana.clear();
        fileprods << '\n';
    }

    fileprods.close();

    std::list<Assinante*> assinantes = this->getAssinantes;

    assinantes.sort(cmp_codAss);

    for(auto &a : assinantes) {
        for(auto &m : a->getFavoritos())
            jordana.push_back(m);
        jordana.sort();

    // filefavs << a->getCodigo() << ';';
    }

    filefavs.close();
}

// Setters
void PlataformaDigital::setNome(std::string _name) {this->nome = _name;}
// Getters
std::set<Assinante*>PlataformaDigital::getAssinantes()        {return this->assinantes;}
std::set<Midia*> PlataformaDigital::getProdutosRegistrados()  {return this->produtosRegistrados;}
std::set<Produtor*> PlataformaDigital::getProdutores()        {return this->produtores;}
std::set<Midia::Genero*> PlataformaDigital::getGeneros()      {return this->generos;}
std::set<Album*> PlataformaDigital::getAlbumsCadastrados()    {return this->albumsCadastrados;}
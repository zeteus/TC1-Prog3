#pragma once

#include <iostream>
#include <list>

#include "Assinante.hpp"
#include "Produtor.hpp"

class Produtor;
class Assinante;    // forward declaration

class Midia {
public:
    class Genero {
    private:
        // Attributes
        std::string nome;
        std::string sigla;

        // Relations
        std::list<Midia*> midias;
        
        // Setters
        void setNome(std::string name);
        void setSigla(std::string Sigla);

    public:
        // Constructors
        Genero();
        Genero(std::string name, std::string sigla);
        // Destructor
        ~Genero();

        // Functions
        void addMidia(Midia* midia);
        void removeMidia(Midia* midia);

        // Getters
        std::string getNome();
        std::string getSigla();
    };

    protected:
        // Attributes
        std::string nome;
        float   duracao;
        int     codigo;
        int     anoLancamento;
        char    tipo;

        // Relations
        std::list<Assinante*>   assinantes;
        Genero*          genero;
        std::list<Produtor*> produtores;

        // Setters
        void setNome(std::string _name);
        void setCodigo(int _code);
        void setDuracao(float _duracao);
        void setAnoLancamento(int _launchYear);
        void setGenero(Genero *genre);
        static void setQtdProdutos(int qnt);
        void setProdutores(std::list<Produtor*> p);

public:
    // Attribute
    static int qtdProdutos;

    // Constructors
    Midia();
    Midia(std::string name, int cod, Genero* genre, float duracao, int ano);
    // Destructor
    virtual ~Midia();

    // Getters
    Genero*         getGenero();
    std::string     getNome();
    float           getDuracao();
    int             getCodigo();
    int             getAnoLancamento();
    int             getQtdProdutos();
    virtual char    getTipo() = 0;
    std::list<Produtor*> getProdutores();

    void addAssinante(Assinante *subscriber);
    void addProdutor(Produtor *produtor);
    void removeAssinante(Assinante *subscriber);
    // Functions, virtual evita ser chamado pelos herdeiros
    virtual void printInfoProduto() = 0;
    virtual void printarNoArquivo(std::ofstream &_outfile) = 0;
};
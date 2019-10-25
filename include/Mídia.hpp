#pragma once

#include <iostream>
#include <list>

#include "Assinante.hpp"
#include "Produtor.hpp"

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

        // Relations
        std::list<Assinante*>   assinantes;
        Midia::Genero*          genero;

        // Setters
        void setNome(std::string _name);
        void setCodigo(int _code);
        void setDuracao(float _duracao);
        void setAnoLancamento(int _launchYear);
        void setGenero(Midia::Genero *genre);
        static void setQtdProdutos(int qnt);

public:
    // Attribute
    static int qtdProdutos;

    // Constructors
    Midia();
    Midia(std::string name, int cod, Genero *genre, int ano, float duracao);
    // Destructor
    ~Midia();

    // Getters
    Midia::Genero*  getGenero();
    std::string     getNome();
    float   getDuracao();
    int     getCodigo();
    int     getAnoLancamento();
    int     getQtdProdutos();

    // Functions, virtual evita ser chamado pelos herdeiros
    void addAssinante(Assinante *subscriber);
    void removeAssinante(Assinante *subscriber);
    virtual void printInfoProduto() = 0;
    virtual void printarNoArquivo(std::ofstream &_outfile) = 0;
};
#pragma once

#include <iostream>
#include <list>

#include "PlataformaDigital.hpp"
#include "Assinante.hpp"
#include "Produtor.hpp"

class PlataformaDigital;
class Produtores;
class Assinante;    // forward declaration

class Midia {
    class Genero {
        private:
            // Attributes
            std::string name;
            std::string abreviation;

            // Relations
            std::list<Midia*> midias;
            PlataformaDigital* platform;
            
            // Setters
            void setName(std::string name);
            void setAbreviation(std::string abreviation);
        public:
            // Constructors
            Genero();
            Genero(std::string name, std::string sigla);
            // Destructor
            ~Genero();

            // Getters
            std::string getName();
            std::string getAbreviation();
    };
protected:
    // Attributes
    std::string name;
    int code;

    // Relations
    std::list<Assinante*> assinantes;
    std::list<Produtores*> produtores;
    Genero* genre;
    PlataformaDigital* plataforma;

    // Setters
    void setName(std::string name);
    void setCode(int code);
    static void setProductQnt(int qnt);
    void setGenre(Genero *genre);
    void setPlatform(PlataformaDigital* platform);

public:
    // Attribute
    static int productQnt;

    // Constructors
    Midia();
    Midia(std::string name, int cod, Genero *genre);
    // Destructor
    ~Midia();


    // Getters
    std::string getName();
    int getProductQnt();
    Genero* getGenre();

    // Functions, virtual evita ser chamado pelos herdeiros
    virtual void printProductInfo() = 0;
    virtual void printOnFile(std::ofstream &_outfile) = 0;
    virtual void loadFile(std::ifstream &_infile) = 0;

};
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
            std::string name;
            std::string abreviation;

            std::list<Midia*> midias;

            
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
    std::string name;
    int codigo;

    // Relações
    std::list<Assinante*> assinantes;
    std::list<Produtores*> produtores;
    Genero* genre;
    PlataformaDigital* plataforma;

    // Setters
    void setName(std::string name);
    static void setProductQnt(int qnt);
    void setGenre(Genero *genre);

public:
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

    // Functions
    virtual void printProductInfo() = 0;
    static void printProductQnt();
    virtual void printOnFile(std::ofstream &_outfile) = 0;
    virtual void loadFile(std::ifstream &_infile) = 0;

};
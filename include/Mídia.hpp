#pragma once

#include <iostream>

class Midia {
protected: 
    std::string name;
private:
    bool explict;
    // Setters
    void setExplicit(bool expl);
    void setName(std::string name);
    void setProductQnt(int qtd);

    class Genero {
        private:
            Midia* midia;
            std::string name;
            std::string abrev;
        public:
            // Constructors
            Genero();
            Genero(std::string name, std::string sigla);
            // Destructor
            ~Genero();
    };
    Genero* genre;

public:
    static int productQnt;
    // Constructors
    Midia();
    Midia(std::string name, bool expl, std::string genre);
    // Destructor
    ~Midia();


    // Getters
    std::string getName();
    bool getExplicit();
    int getProductQnt();

    // Functions
    virtual void printProductInfo();
    void printProductQnt();

    // Overloading, virtual para evitar chamar o da classe-mãe
    virtual void printOnFile(std::ofstream &_outfile);
    virtual void loadFile(std::ifstream &_infile);
};
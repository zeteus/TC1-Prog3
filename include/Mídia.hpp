#pragma once

#include <iostream>

class Midia {
protected: 
    std::string name;
private:
    bool isExplicit;

    class Genero {
        private:
            std::string name;
            std::string abreviation;
            
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

    Genero* genre;

    // Setters
    void setIsExplicit(bool expl);
    void setName(std::string name);
    void setProductQnt(int qnt);
    void setGenre(Genero *genre);
    void setGenre(std::string genreName);

public:
    static int productQnt;
    // Constructors
    Midia();
    Midia(std::string name, bool expl, std::string genre);
    // Destructor
    ~Midia();


    // Getters
    std::string getName();
    bool getIsExplicit();
    int getProductQnt();
    Genero* getGenre();

    // Functions
    virtual void printProductInfo();
    void printProductQnt();

    // Overloading, virtual para evitar chamar o da classe-mãe
    virtual void printOnFile(std::ofstream &_outfile);
    virtual void loadFile(std::ifstream &_infile);
};
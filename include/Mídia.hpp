#pragma once

class Midia {
private:
    class Genero {
        private:
            Midia* midia;
        public:
            Genero();
            ~Genero();
    };
    Genero* genre;

public:
    Midia();
    ~Midia();

    // Overloading, virtual para evitar chamar o da classe-mãe
    virtual void printOnFile(std::ofstream &_outfile);
    virtual void loadFile(std::ifstream &_infile);
};
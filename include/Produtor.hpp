#pragma once

#include <fstream>
#include <list>
#include <iostream>

#include "Usuário.hpp"
#include "Mídia.hpp"

class Midia;    // Forward declarations

class Produtor: public Usuario {

private:
    // Relações
    std::list<Midia*> produtosDesenvolvidos;

public:
    // Functions
    void imprimeProdutosDesenvolvidos();
    void addProdutoDesenvolvido(Midia* produtoDesenvolvido);
    void removeProdutosDesenvolvidos(Midia* produtosDesenvolvidos);

    // Getters
    std::list<Midia*> getProdutosDesenvolvidos();

    // Constructors
    Produtor();
    Produtor(std::string _name);
    // Destructor
    ~Produtor();

    // Overloading, virtual para evitar ser chamado pelos herdeiros
    virtual void printarNoArquivo(std::ofstream &outfile);
};
#include "../include/defines.h" //corzinhas
#include <iostream>
#include <fstream>

using std::cerr;
using std::cout;
using std::string;

template<typename type>
type readCSV(std::ifstream infile){
    type data;
    infile >> data;
    return data;
}


template <typename type>
void writeCSV(std::ofstream outfile, type data){
    outfile << data << ',';
}

void lineBreakCSV(std::ofstream outfile){
    outfile << '\n';
}

int main() {
    string outfileName = "output.csv";
    string infileName = "input.csv";


    std::ofstream outfile;
    std::ifstream infile;
    outfile.open(outfileName, std::ios::out);
    if(!outfile.is_open()){
        cerr << _BOLDRED << "Erro ao abrir o arquivo \"" << outfileName << "\"." << _RESET << "Verifique se ele existe. Saindo...\n";
        exit(1);
    }
    infile.open(infileName, std::ios::in);
    if(!infile.is_open()){
        cerr << _BOLDRED << "Erro ao abrir o arquivo \"" << infileName << "\"." << _RESET << "Verifique se ele existe. Saindo...\n";
        exit(1);
    }
}
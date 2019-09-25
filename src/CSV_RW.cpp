#include "../include/CSV_RW.hpp"

void CSV_RW::lineBreak(){
    *this->fileptr << '\n';
}

template <typename type>
void CSV_RW::writeValue(type v){
    this->fileptr << v << ',';
}

    //Construtor e descontrutor
CSV_RW::CSV_RW(string filename){
    fstream fileptr;
    fileptr.open(filename, std::ios::out | std::ios::in);
    if(!fileptr.is_open())
        std::cerr << _BOLDRED << "Houve algum erro ao abrir o arquivo \"" << filename << _RESET << "Por favor, cheque se ele existe. Continuando...\n";
    
    this->setFileptr(&fileptr);
    this->setFilename(filename);
}

CSV_RW::~CSV_RW(){
    if(this->fileptr->is_open())
        this->fileptr->close();
}

    //Setters e getter
void        CSV_RW::setFileptr(fstream *fileptr){this->fileptr = fileptr;}
fstream*    CSV_RW::getFileptr(){return this->fileptr;}
void        CSV_RW::setFilename(string filename){this->filename = filename;}
string      CSV_RW::getFilename(){return this->filename;}
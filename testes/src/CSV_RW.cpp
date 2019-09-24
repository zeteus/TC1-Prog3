#include "../include/CSV_RW.hpp"









CSV_RW::CSV_RW(string filename){
    fstream fileptr;
    fileptr.open(filename);
    
}

    //Setters e getter
void        CSV_RW::setFileptr(fstream *fileptr){this->fileptr = fileptr;}
fstream*    CSV_RW::getFileptr(){return this->fileptr;}
void        CSV_RW::setFilename(string filename){this->filename = filename;}
string      CSV_RW::getFilename(){return this->filename;}
void        CSV_RW::setBuffer(string buffer){this->buffer = buffer;}
string      CSV_RW::getBuffer(){return this->buffer;}
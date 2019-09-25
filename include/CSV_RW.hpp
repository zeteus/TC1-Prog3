/*----------------
 *  Define o comportamento padrão para importação
 *  e exportação no formato CSV.
 *-----------------*/

#ifndef CSV_RW_
#define CSV_RW_

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "defines.h"

using std::string;
using std::fstream;

class CSV_RW{
    private:
        fstream *fileptr;

        void setFileptr(fstream *fileptr);
        fstream* getFileptr();

    protected:
        string filename;

        void setFilename(string filename);
        string getFilename();

    public:
        CSV_RW(string filename);
        CSV_RW(fstream fileptr);
        ~CSV_RW();

        void lineBreak();
        string readValue();
        template <typename type>
        void writeValue(type v);

};
#endif
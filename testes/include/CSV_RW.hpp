#ifndef CSV_RW_
#define CSV_RW_

#include <iostream>
#include <fstream>
#include <stdexcept>

using std::string;
using std::fstream;

class CSV_RW{
    private:
        fstream *fileptr;
        void writeValue();
        void readValue();

        void setFileptr(fstream *fileptr);
        fstream* getFileptr();

    protected:
        string buffer;
        string filename;

        void setBuffer(string buffer);
        string getBuffer();
        void setFilename(string filename);
        string getFilename();

    public:
        CSV_RW(string filename);
        CSV_RW(fstream fileptr);
        ~CSV_RW();
};

#endif
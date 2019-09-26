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
};
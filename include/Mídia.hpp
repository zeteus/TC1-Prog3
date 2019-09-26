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
    Genero* genero;

public:
    Midia();
    ~Midia();
};
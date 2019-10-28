# TC1-Prog3
-------

Todos os arquivos de entradas precisa estar usando o caractere terminador de linha (newline) '\n' (LF/Line Feed), e não usar o caractere '\r' (CR/Carriage Return).
Todos os arquivos de entradas deve estar codificados usando o padrão UTF-8.
Usar arquivos de entrada que não seguem os parâmetros descritos acimas tem comportamento não definido.


 make

compila o programa usando as flags em CXX_FLAGS, por padrão "-std=c++17 -ggdb -g -Ofast -Wall -Wextra -Werror".

 make run

Compila e executa o programa usando as flags padrão.

 make val

Compila e executa o programa no valgrind.

 make valzao

compila e executa o programa no valgrind usando "--leak-check=full --show-leak-kinds=all".
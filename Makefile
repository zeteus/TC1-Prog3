CXX		  	:= g++
CXX_FLAGS 	:= -std=c++17 -ggdb -g -Wall -Wextra -Ofast #-Werror 

BIN			:= bin
SRC			:= src
INCLUDE		:= include
LIB			:= lib
EXECARGS	:= -g input/generos.csv -u input/usuarios.csv -f input/favoritos.csv -m input/midias_corrigidas.csv
EXECARGSPY  := -g input/entradas_python/generos_python.csv -u input/entradas_python/usuarios_python.csv -f input/entradas_python/favoritos_python.csv -m input/entradas_python/midias_python.csv

LIBRARIES	:=
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: all
	clear
	./$(BIN)/$(EXECUTABLE) $(EXECARGS)

py: all
	clear
	./$(BIN)/$(EXECUTABLE) $(EXECARGSPY)

valpy: all
	clear
	valgrind ./$(BIN)/$(EXECUTABLE) $(EXECARGSPY)

val: all
	clear
	valgrind ./$(BIN)/$(EXECUTABLE) $(EXECARGS)

valzao: all
	clear
	valgrind --leak-check=full --show-leak-kinds=all ./$(BIN)/$(EXECUTABLE) $(EXECARGS)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
	# make

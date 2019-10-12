CXX		  	:= g++
CXX_FLAGS 	:= -std=c++17 -ggdb -g #-Wall -Wextra 

BIN			:= bin
SRC			:= src
INCLUDE		:= include
LIB			:= lib
EXECARGS	:= -g input/generos.csv -u input/usuarios.csv -f input/favoritos.csv -m input/midias_corrigidas.csv

LIBRARIES	:=
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: all
	clear
	./$(BIN)/$(EXECUTABLE) $(EXECARGS)

val: clean all
	#clear
	valgrind ./$(BIN)/$(EXECUTABLE) $(EXECARGS)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
	make

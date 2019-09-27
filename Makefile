CXX		  	:= g++
CXX_FLAGS 	:= -std=c++17 -ggdb -g #-Wall -Wextra 

BIN			:= bin
SRC			:= src
INCLUDE		:= include
LIB			:= lib

LIBRARIES	:=
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	#clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
	make

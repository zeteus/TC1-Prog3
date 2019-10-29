CXX		  	:= g++
CXX_FLAGS 	:= -std=c++17 -ggdb -g -Wall -Wextra -Werror -Ofast

BIN			:= bin
SRC			:= src
INCLUDE		:= include
LIB			:= lib
INPUTFOLDER := input
EXECARGS	:= -g $(INPUTFOLDER)/generos.csv -u $(INPUTFOLDER)/usuarios.csv -f $(INPUTFOLDER)/favoritos.csv -m $(INPUTFOLDER)/midias_corrigidas.csv
EXECARGSPY  := -g $(INPUTFOLDER)/entradas_python/generos_python.csv -u $(INPUTFOLDER)/entradas_python/usuarios_python.csv -f $(INPUTFOLDER)/entradas_python/favoritos_python.csv -m $(INPUTFOLDER)/entradas_python/midias_python.csv

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

## Para point-case test, tratamento de exceções

# Erro 1
run_e11:
	./$(BIN)/$(EXECUTABLE) -u entradas/naoexiste.csv -f entradas/favoritos.csv -g entradas/generos.csv -m entradas/midias_corrigidas.csv

run_e12:
	./$(BIN)/$(EXECUTABLE) -u entradas/usuarios.csv -f entradas/naoexiste.csv -g entradas/generos.csv -m entradas/midias_corrigidas.csv

run_e13:
	./$(BIN)/$(EXECUTABLE) -u entradas/usuarios.csv -f entradas/favoritos.csv -g entradas/naoexiste.csv -m entradas/midias_corrigidas.csv

run_e14:
	./$(BIN)/$(EXECUTABLE) -u entradas/usuarios.csv -f entradas/favoritos.csv -g entradas/generos.csv -m entradas/naoexiste.csv

# Erro 2
run_e21:
	./$(BIN)/$(EXECUTABLE) -u $(INPUTFOLDER)/entradas_excecoes/testes_erro2/usuarios_e21.csv -f $(INPUTFOLDER)/entradas_excecoes/testes_erro2/favoritos_e2.csv -g $(INPUTFOLDER)/entradas_excecoes/testes_erro2/generos_e2.csv -m $(INPUTFOLDER)/entradas_excecoes/testes_erro2/midias_e21.csv

run_e22:
	./$(BIN)/$(EXECUTABLE) -u $(INPUTFOLDER)/entradas_excecoes/testes_erro2/usuarios_e2.csv -f $(INPUTFOLDER)/entradas_excecoes/testes_erro2/favoritos_e22.csv -g $(INPUTFOLDER)/entradas_excecoes/testes_erro2/generos_e2.csv -m $(INPUTFOLDER)/entradas_excecoes/testes_erro2/midias_e22.csv

run_e23:
	./$(BIN)/$(EXECUTABLE) -u $(INPUTFOLDER)/entradas_excecoes/testes_erro2/usuarios_e2.csv -f $(INPUTFOLDER)/entradas_excecoes/testes_erro2/favoritos_e23.csv -g $(INPUTFOLDER)/entradas_excecoes/testes_erro2/generos_e2.csv -m $(INPUTFOLDER)/entradas_excecoes/testes_erro2/midias_e23.csv

run_e24:
	./$(BIN)/$(EXECUTABLE) -u $(INPUTFOLDER)/entradas_excecoes/testes_erro2/usuarios_e2.csv -f $(INPUTFOLDER)/entradas_excecoes/testes_erro2/favoritos_e2.csv -g $(INPUTFOLDER)/entradas_excecoes/testes_erro2/generos_e2.csv -m $(INPUTFOLDER)/entradas_excecoes/testes_erro2/midias_e24.csv

run_e25:
	./$(BIN)/$(EXECUTABLE) -u $(INPUTFOLDER)/entradas_excecoes/testes_erro2/usuarios_e2.csv -f $(INPUTFOLDER)/entradas_excecoes/testes_erro2/favoritos_e2.csv -g $(INPUTFOLDER)/entradas_excecoes/testes_erro2/generos_e2.csv -m $(INPUTFOLDER)/entradas_excecoes/testes_erro2/midias_e25.csv

run_e26:
	./$(BIN)/$(EXECUTABLE) -u $(INPUTFOLDER)/entradas_excecoes/testes_erro2/usuarios_e2.csv -f $(INPUTFOLDER)/entradas_excecoes/testes_erro2/favoritos_e2.csv -g $(INPUTFOLDER)/entradas_excecoes/testes_erro2/generos_e2.csv -m $(INPUTFOLDER)/entradas_excecoes/testes_erro2/midias_e26.csv

run_e27:
	./$(BIN)/$(EXECUTABLE) -u $(INPUTFOLDER)/entradas_excecoes/testes_erro2/usuarios_e2.csv -f $(INPUTFOLDER)/entradas_excecoes/testes_erro2/favoritos_e2.csv -g $(INPUTFOLDER)/entradas_excecoes/testes_erro2/generos_e2.csv -m $(INPUTFOLDER)/entradas_excecoes/testes_erro2/midias_e27.csv

run_e28:
	./$(BIN)/$(EXECUTABLE) -u $(INPUTFOLDER)/entradas_excecoes/testes_erro2/usuarios_e2.csv -f $(INPUTFOLDER)/entradas_excecoes/testes_erro2/favoritos_e2.csv -g $(INPUTFOLDER)/entradas_excecoes/testes_erro2/generos_e2.csv -m $(INPUTFOLDER)/entradas_excecoes/testes_erro2/midias_e28.csv

run_e29:
	./$(BIN)/$(EXECUTABLE) -u $(INPUTFOLDER)/entradas_excecoes/testes_erro2/usuarios_e2.csv -f $(INPUTFOLDER)/entradas_excecoes/testes_erro2/favoritos_e2.csv -g $(INPUTFOLDER)/entradas_excecoes/testes_erro2/generos_e2.csv -m $(INPUTFOLDER)/entradas_excecoes/testes_erro2/midias_e29.csv


# Erro 3
# Tipo de usuário sem correspondente (Não é A ou P ou U)
run_e31:
	./$(BIN)/$(EXECUTABLE) -u $(INPUTFOLDER)/entradas_excecoes/testes_erro3/usuarios_e31.csv -f $(INPUTFOLDER)/entradas_excecoes/testes_erro3/favoritos_e31.csv -g $(INPUTFOLDER)/entradas_excecoes/testes_erro3/generos_e31.csv -m $(INPUTFOLDER)/entradas_excecoes/testes_erro3/midias_e31.csv
# Mídia sem sigla de gênero correspondente
run_e32:
	./$(BIN)/$(EXECUTABLE) -u $(INPUTFOLDER)/entradas_excecoes/testes_erro3/usuarios_e32.csv -f $(INPUTFOLDER)/entradas_excecoes/testes_erro3/favoritos_e32.csv -g $(INPUTFOLDER)/entradas_excecoes/testes_erro3/generos_e32.csv -m $(INPUTFOLDER)/entradas_excecoes/testes_erro3/midias_e32.csv

# Mídia sem tipo correspondente
run_e33:
	./$(BIN)/$(EXECUTABLE) -u $(INPUTFOLDER)/entradas_excecoes/testes_erro3/usuarios_e33.csv -f $(INPUTFOLDER)/entradas_excecoes/testes_erro3/favoritos_e33.csv -g $(INPUTFOLDER)/entradas_excecoes/testes_erro3/generos_e33.csv -m $(INPUTFOLDER)/entradas_excecoes/testes_erro3/midias_e33.csv

# Mídia sem código de produtor correspondente
run_e34:
	./$(BIN)/$(EXECUTABLE) -u $(INPUTFOLDER)/entradas_excecoes/testes_erro3/usuarios_e34.csv -f $(INPUTFOLDER)/entradas_excecoes/testes_erro3/favoritos_e34.csv -g $(INPUTFOLDER)/entradas_excecoes/testes_erro3/generos_e34.csv -m $(INPUTFOLDER)/entradas_excecoes/testes_erro3/midias_e34.csv

# Favorito sem mídia correspondente
run_e35:
	./$(BIN)/$(EXECUTABLE) -u $(INPUTFOLDER)/entradas_excecoes/testes_erro3/usuarios_e35.csv -f $(INPUTFOLDER)/entradas_excecoes/testes_erro3/favoritos_e35.csv -g $(INPUTFOLDER)/entradas_excecoes/testes_erro3/generos_e35.csv -m $(INPUTFOLDER)/entradas_excecoes/testes_erro3/midias_e35.csv
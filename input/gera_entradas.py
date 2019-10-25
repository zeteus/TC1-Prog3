#!/usr/bin/env python3

import random
import string
import pandas
from faker import Faker  # Escolher nomes aleatórios

fake = Faker('pt_BR')
fakezada = Faker('en_US')
path = "entradas_python/"


def gera_usuarios(nUsuarios):
    tipos = ['A', 'P', 'U']
    with open(f"{path}/usuarios_python.csv", "w+", encoding="utf8") as file:
        file.write("Código;Tipo;Nome\n")
        for i in range(1, nUsuarios + 1):
            file.write(f"{i};{random.choice(tipos)};{fake.name()}\n")
    pass


def gera_generos(nGeneros):
    with open(f"{path}/genres.txt", "r", encoding="utf8") as fG:
        genres = [line.strip().capitalize() for line in fG]

    texto = list()
    with open(f"{path}/generos_python.csv", "w+", encoding="utf8") as file:
        file.write("Sigla;Nome\n")
        while len(texto) != nGeneros:
            genero = random.choice(genres)
            genres.remove(genero)
            if len(genero.split()) > 1:
                sigla = f"{genero.split()[0][0]}{genero.split()[1][0]}".upper()
            else:
                sigla = f"{genero[0]}{genero[1]}".upper()
            if sigla not in list(map(lambda x: x[0], texto)):
                texto.append((sigla, genero))
        for i in range(nGeneros):
            file.write(f"{texto[i][0]};{texto[i][1]}\n")
    pass


def gera_midias(nMidias, arquivoGeneros, arquivoUsuarios):
    with open(f"{path}/midias_python.csv", "w+", encoding="utf8") as file:
        file.write("Código;Nome;Tipo;Produtores;Duração;Gênero;Temporada;Álbum;Código do Álbum;Publicação\n")

        generoCSV = pandas.read_csv(f"{arquivoGeneros}", sep=';')
        generoCSV = generoCSV["Sigla"].tolist()

        usuariosCSV = pandas.read_csv(f"{arquivoUsuarios}", sep=";")
        tipoUsuario = usuariosCSV["Tipo"].tolist()

        albuns = list()
        rangeMidias = range(1, nMidias + 1)
        for i in rangeMidias:
            file.write(f"{i};")
            nomeMidia = fake.sentence(nb_words=random.randint(1, 7), variable_nb_words=True, ext_word_list=None).translate(str.maketrans('', '', string.punctuation))
            publicacaoMidia = random.randint(1990, 2077)
            tipoMidia = random.choice(['M', 'P'])

            produtores = list()

            if tipoMidia is 'M':
                duracaoMidia = f"{random.randint(1, 10)},{random.randint(0,99)}"
                temporadaMidia = ''

                albumMidia = fakezada.sentence(nb_words=random.randint(1, 7), variable_nb_words=True, ext_word_list=None).translate(str.maketrans('', '', string.punctuation))
                albuns.append(albumMidia)
                nAlbuns = len(set(albuns))  # Para enumerar álbuns

                while len(produtores) < random.randint(1, 3):
                    randProd = random.randint(1, nUsuarios - 1)
                    if tipoUsuario[randProd] is "A" and randProd + 1 not in produtores:
                        produtores.append(randProd + 1)
            else:
                duracaoMidia = duracaoMidia = f"{random.randint(1, 120)},{random.randint(0,99)}"
                temporadaMidia = random.randint(1, 20)
                albumMidia = ''
                while len(produtores) < random.randint(1, 3):
                    randProd = random.randint(1, nUsuarios - 1)
                    if tipoUsuario[randProd] is "P" and randProd + 1 not in produtores:
                        produtores.append(randProd + 1)

            genero = random.choice(generoCSV)
            while str(genero) in 'nan':  # Pois o random.choice tá retornando nan às vezes
                genero = random.choice(generoCSV)

            file.write(f"{nomeMidia};{tipoMidia};")
            for produtor in produtores:
                if produtor is not produtores[-1]:
                    file.write(f"{produtor}, ")
                elif produtor is produtores[-1]:
                    file.write(f"{produtor};")
            if tipoMidia is 'M':
                file.write(f"{duracaoMidia};{genero};{temporadaMidia};{albumMidia};{nAlbuns};{publicacaoMidia}")
            else:
                file.write(f"{duracaoMidia};{genero};{temporadaMidia};{albumMidia};;{publicacaoMidia}")
            if i != rangeMidias[-1]:
                file.write("\n")
    pass


def gera_favoritos(arquivoUsuarios, nMidias):
    usuariosCSV = pandas.read_csv(f"{arquivoUsuarios}", sep=';')
    usuarios = usuariosCSV[(usuariosCSV['Tipo'] == 'U')]  # Só gera favoritos para usuários

    with open(f"{path}/favoritos_python.csv", "w+", encoding="utf8") as file:
        file.write("Código;Mídias Favoritas\n")
        for i in range(1, usuariosCSV["Código"].size + 1):
            file.write(f"{i};")

            if i in usuarios["Código"].tolist():
                rangeMidias = range(round(abs(random.gauss(15, 8))))
                for f in rangeMidias:
                    if f != rangeMidias[-1]:
                        file.write(f"{random.randrange(1, nMidias + 1)},")
                    else:
                        file.write(f"{random.randrange(1, nMidias + 1)}")
            file.write("\n")
    pass


# Editar valores aqui
nUsuarios = 500
nFavoritos = nUsuarios
nMidias = 3000
nGeneros = 200

gera_usuarios(nUsuarios)
gera_favoritos(f"{path}/usuarios_python.csv", nMidias)
gera_generos(nGeneros)
gera_midias(nMidias, f"{path}/generos_python.csv", f"{path}/usuarios_python.csv")

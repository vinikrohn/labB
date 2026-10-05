"""
EXERCÍCIO – Contagem de palavras em um arquivo texto

Enunciado:
    Escreva um programa que receba o nome de um arquivo texto e uma palavra,
    e mostre quantas vezes essa palavra ocorre no texto.

    Regras:
      - A contagem não deve diferenciar maiúsculas de minúsculas
        ("Casa", "casa" e "CASA" contam como a mesma palavra).
      - Só contam palavras inteiras: procurando "sol", a palavra
        "solidão" NÃO deve ser contada.
      - A pontuação não deve atrapalhar: "sol," e "sol." contam como "sol".
      - Se o arquivo não existir, o programa deve mostrar uma mensagem de erro.

Exemplo de execução:
    python exerOutubro4.py texto.txt sol
    A palavra "sol" ocorre 4 vez(es) no arquivo texto.txt.
"""

import re
import sys


def contar_ocorrencias(nome_arquivo, palavra):
    with open(nome_arquivo, encoding="utf-8") as arquivo:
        texto = arquivo.read().lower()
    # \w+ pega sequências de letras/números (inclui acentos), ignorando pontuação
    palavras = re.findall(r"\w+", texto)
    return palavras.count(palavra.lower())


def main():
    if len(sys.argv) == 3:
        nome_arquivo, palavra = sys.argv[1], sys.argv[2]
    else:
        nome_arquivo = input("Nome do arquivo: ")
        palavra = input("Palavra a procurar: ")

    try:
        total = contar_ocorrencias(nome_arquivo, palavra)
    except FileNotFoundError:
        print(f'Erro: o arquivo "{nome_arquivo}" não foi encontrado.')
        return

    print(f'A palavra "{palavra}" ocorre {total} vez(es) no arquivo {nome_arquivo}.')


if __name__ == "__main__":
    main()

/*
 * EXERCICIO exerOutubro5
 * Idem ao exercicio exerOutubro4 (receber um arquivo texto e uma palavra e verificar
 * quantas vezes a palavra ocorre no texto), porem a quantidade de vezes
 * que a palavra ocorre deve ser RETORNADA por uma funcao.
 *
 * Prototipo da funcao:
 *     int contaPalavra(char nomeArquivo[], char palavra[]);
 *
 * Retorno:
 *     a quantidade de ocorrencias da palavra no arquivo,
 *     ou -1 se o arquivo nao puder ser aberto.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 50  /* tamanho maximo de uma palavra */

/* Passa a palavra para maiusculo, para comparar "sol" com "SOL" */
void maiusculo(char palavra[]) {
    int i;
    for (i = 0; palavra[i] != '\0'; i++) {
        palavra[i] = toupper(palavra[i]);
    }
}

/* Tira a pontuacao do comeco e do fim da palavra: "sol," vira "sol" */
void tiraPontuacao(char palavra[]) {
    int inicio = 0;
    int fim = strlen(palavra) - 1;
    int i;

    while (palavra[inicio] != '\0' && ispunct(palavra[inicio])) {
        inicio++;
    }
    while (fim >= inicio && ispunct(palavra[fim])) {
        fim--;
    }
    for (i = 0; inicio <= fim; i++, inicio++) {
        palavra[i] = palavra[inicio];
    }
    palavra[i] = '\0';
}

/* Conta quantas vezes a palavra aparece no arquivo e RETORNA o total */
int contaPalavra(char nomeArquivo[], char palavra[]) {
    FILE *arq;
    char lida[TAM];
    char procurada[TAM];
    int cont = 0;

    arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        return -1;  /* erro ao abrir o arquivo */
    }

    strcpy(procurada, palavra);
    maiusculo(procurada);

    /* le o arquivo palavra por palavra */
    while (fscanf(arq, "%49s", lida) == 1) {
        tiraPontuacao(lida);
        maiusculo(lida);
        if (strcmp(lida, procurada) == 0) {
            cont++;
        }
    }

    fclose(arq);
    return cont;
}

int main() {
    char nomeArquivo[100];
    char palavra[TAM];
    int total;

    printf("Nome do arquivo: ");
    scanf("%99s", nomeArquivo);
    printf("Palavra a procurar: ");
    scanf("%49s", palavra);

    total = contaPalavra(nomeArquivo, palavra);

    if (total == -1) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
    } else {
        printf("A palavra \"%s\" ocorre %d vez(es) no arquivo.\n", palavra, total);
    }

    return 0;
}

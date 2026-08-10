#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10

int main() {
    int opcao;
    int vetor[TAMANHO];
    int qtd_elementos = 0;
    srand(time(NULL));

    do {
        system("cls");
        printf("MENU PRINCIPAL\n");
        printf("1 - Popular vetor com numeros aleatorios\n");
        printf("2 - Listar vetor populado\n");
        printf("3 - Ordenar vetor\n");
        printf("4 - Calcular media aritmetica\n");
        printf("5 - Calcular mediana\n");
        printf("6 - Localizar maior e menor valor\n");
        printf("7 - Sair do sistema\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Populando o vetor com numeros aleatorios\n");
                for (int i = 0; i < TAMANHO; i++) {
                    vetor[i] = rand() % 100;
                }
                qtd_elementos = TAMANHO;
                break;

            case 2:
                printf("Listando o vetor com numeros aleatorios\n");
                if (qtd_elementos > 0) {
                    for (int i = 0; i < TAMANHO; i++) {
                        printf("%d\t", vetor[i]);
                    }
                    printf("\n");
                } else {
                    printf("Vetor vazio. Nada a exibir\n");
                }
                break;

            case 3:
                printf("Ordenando o vetor com numeros aleatorios\n");
                if (qtd_elementos > 0) {
                    for (int i = 0; i < TAMANHO - 1; i++) {
                        for (int j = 0; j < TAMANHO - i - 1; j++) {
                            if (vetor[j] > vetor[j + 1]) {
                                int temp = vetor[j];
                                vetor[j] = vetor[j + 1];
                                vetor[j + 1] = temp;
                            }
                        }
                    }
                    printf("Vetor ordenado com sucesso\n");
                } else {
                    printf("Vetor vazio. Nada a ordenacao\n");
                }
                break;

            case 4:
                printf("Calculando a media aritmetica dos valores do vetor...\n");
                if (qtd_elementos > 0) {
                    int soma = 0;
                    float media;

                    for (int i = 0; i < TAMANHO; i++) {
                        soma += vetor[i];
                    }

                    media = (float)soma / qtd_elementos;
                    printf("A media aritmetica dos valores do vetor eh: %.2f\n", media);
                } else {
                    printf("Vetor vazio. Nada a calcular\n");
                }
                break;

            case 5:
                printf("Calculando a mediana dos valores do vetor...\n");
                if (qtd_elementos > 0) {

                    // ETAPA 1: Ordenacao do vetor via Bubble Sort (requisito para a mediana)
                    for (int i = 0; i < TAMANHO - 1; i++) {
                        for (int j = 0; j < TAMANHO - i - 1; j++) {
                            if (vetor[j] > vetor[j + 1]) {
                                int temp = vetor[j];
                                vetor[j] = vetor[j + 1];
                                vetor[j + 1] = temp;
                            }
                        }
                    }

                    // ETAPA 2: Como TAMANHO e 10 (par), pegamos os dois elementos do meio
                    int meio1 = vetor[(TAMANHO / 2) - 1];
                    int meio2 = vetor[TAMANHO / 2];

                    float mediana = (meio1 + meio2) / 2.0;

                    printf("Vetor ordenado para o calculo.\n");
                    printf("Elementos centrais: %d e %d\n", meio1, meio2);
                    printf("Mediana: %.2f\n", mediana);

                } else {
                    printf("Vetor vazio. Nada a calcular\n");
                }
                break;

            case 6:
                printf("Localizando o maior e o menor valor do vetor...\n");
                if (qtd_elementos > 0) {
                    int maior = vetor[0];
                    int menor = vetor[0];

                    for (int i = 1; i < TAMANHO; i++) {
                        if (vetor[i] > maior) {
                            maior = vetor[i];
                        }
                        if (vetor[i] < menor) {
                            menor = vetor[i];
                        }
                    }

                    printf("Maior valor: %d\n", maior);
                    printf("Menor valor: %d\n", menor);
                } else {
                    printf("Vetor vazio. Nada a localizar\n");
                }
                break;

            case 7:
                printf("Sistema encerrado\n");
                break;

            default:
                printf("Opcao invalida. Redigite\n");
                break;
        }
        system("pause");
    } while (opcao != 7);

    return 0;
}

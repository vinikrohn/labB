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
        printf("5 - Sair do sistema\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Populando o vetor com numeros aleatorios\n");
                for (int i = 0; i < TAMANHO; i++) {
                    vetor[i] = rand() % 100;
                    qtd_elementos++;
                }
                break;

            case 2:
                printf("Listando o vetor com numeros aleatorios\n");
                if (qtd_elementos > 0){
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
                if (qtd_elementos > 0){
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

                if (qtd_elementos > 0) { // 1. Verificar se o vetor possui dados
        
                int soma = 0; // 2. Declarar variáveis locais (ex: acumulador e/ou resultado)
                float media;

                for (int i = 0; i < TAMANHO; i++) { // 3. Estrutura de repetição (for) para percorrer o vetor do índice 0 até TAMANHO
                    soma += vetor[i];
                }

                media = (float)soma / qtd_elementos; // 4. Exibir o resultado final com printf
                printf("A media aritmetica dos valores do vetor eh: %.2f\n", media);

             } else {
        // Mensagem de aviso caso o vetor esteja vazio
        printf("Vetor vazio. Nada a calcular\n");
            }
             break;

                case 5: // Ajuste o número do case de acordo com o seu menu
    printf("Calculando a mediana dos valores do vetor...\n");
    if (qtd_elementos > 0) {

        // ETAPA 1: Ordenação do vetor via Bubble Sort (requisito para a mediana)
        for (int i = 0; i < TAMANHO - 1; i++) {
            for (int j = 0; j < TAMANHO - i - 1; j++) {
                if (vetor[j] > vetor[j + 1]) {
                    int temp = vetor[j];
                    vetor[j] = vetor[j + 1];
                    vetor[j + 1] = temp;
                }
            }
        }

        // ETAPA 2: Como TAMANHO é 10 (par), pegamos os dois elementos do meio
        // Índices 4 e 5: (TAMANHO / 2 - 1) e (TAMANHO / 2)
        int meio1 = vetor[(TAMANHO / 2) - 1]; 
        int meio2 = vetor[TAMANHO / 2];

        // Média dos dois valores centrais
        // Dividimos por 2.0 para manter as casas decimais
        float mediana = (meio1 + meio2) / 2.0;

        // ETAPA 3: Exibição do resultado
        printf("Vetor ordenado para o calculo.\n");
        printf("Elementos centrais: %d e %d\n", meio1, meio2);
        printf("Mediana: %.2f\n", mediana);

    } else {
        printf("Vetor vazio. Nada a calcular\n");
    }
    break;

            case 5:
                printf("Sistema encerrado\n");
                break;
            default:
                printf("Opcao invalida. Redigite\n");
                break;
        }
        system("pause");
    } while (opcao != 5);


//LISTA DE EXERCÍCIOS DE REVISÃO

// Dado os programas criados em laboratório, com uso de menu e vetor, crie as seguintes melhorias:

// a) crie uma opção no menu que calcule e exiba a média aritmética dos valores do vetor
// b) crie uma opção no menu que calcule e exiba a mediana dos valores do vetor
// c) crie uma opção do menu que localize e exiba o









    return 1;
}

#include <stdio.h>

#define MAX 100

typedef struct {
    int codigo;
    int ano;
    float preco;
} Carro;

int main() {
    Carro carros[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n--- CATALOGO DE CARROS ---\n");
        printf("1. Cadastrar carro\n");
        printf("2. Buscar por preco maximo\n");
        printf("3. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total >= MAX) {
                    printf("Limite atingido!\n");
                    break;
                }
                printf("Codigo: ");
                scanf("%d", &carros[total].codigo);
                printf("Ano: ");
                scanf("%d", &carros[total].ano);
                printf("Preco: ");
                scanf("%f", &carros[total].preco);
                total++;
                printf("Carro cadastrado!\n");
                break;

            case 2: {
                float precoMax;
                printf("Digite o preco maximo: ");
                scanf("%f", &precoMax);

                int encontrou = 0;
                for (int i = 0; i < total; i++) {
                    if (carros[i].preco < precoMax) {
                        printf("Codigo: %d | Ano: %d | Preco: R$ %.2f\n",
                               carros[i].codigo, carros[i].ano, carros[i].preco);
                        encontrou = 1;
                    }
                }
                if (!encontrou) {
                    printf("Nenhum carro encontrado abaixo desse valor.\n");
                }
                break;
            }

            case 3:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    return 0;
}

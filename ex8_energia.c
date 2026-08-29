#include <stdio.h>

#define MAX 100

typedef struct {
    int numeroCasa;
    float consumoKwh;
} Imovel;

int main() {
    Imovel imoveis[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n--- CONSUMO DE ENERGIA ---\n");
        printf("1. Cadastrar imovel\n");
        printf("2. Media de consumo da rua\n");
        printf("3. Listar imoveis acima da media\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total >= MAX) {
                    printf("Limite atingido!\n");
                    break;
                }
                printf("Numero da casa: ");
                scanf("%d", &imoveis[total].numeroCasa);
                printf("Consumo (kWh): ");
                scanf("%f", &imoveis[total].consumoKwh);
                total++;
                printf("Imovel cadastrado!\n");
                break;

            case 2: {
                if (total == 0) {
                    printf("Nenhum imovel cadastrado.\n");
                    break;
                }
                float soma = 0;
                for (int i = 0; i < total; i++) soma += imoveis[i].consumoKwh;
                printf("Media de consumo: %.2f kWh\n", soma / total);
                break;
            }

            case 3: {
                if (total == 0) {
                    printf("Nenhum imovel cadastrado.\n");
                    break;
                }
                // precisamos calcular a media de novo, pois cada "case" e independente
                float soma = 0;
                for (int i = 0; i < total; i++) soma += imoveis[i].consumoKwh;
                float media = soma / total;

                printf("Imoveis com consumo acima da media (%.2f kWh):\n", media);
                int encontrou = 0;
                for (int i = 0; i < total; i++) {
                    if (imoveis[i].consumoKwh > media) {
                        printf("Casa %d | Consumo: %.2f kWh\n", imoveis[i].numeroCasa, imoveis[i].consumoKwh);
                        encontrou = 1;
                    }
                }
                if (!encontrou) printf("Nenhum imovel acima da media.\n");
                break;
            }

            case 4:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}

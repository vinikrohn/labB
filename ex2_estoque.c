#include <stdio.h>

#define MAX 100

typedef struct {
    int codigo;
    int quantidade;
    float preco;
} Produto;

int main() {
    Produto produtos[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n--- MENU ESTOQUE ---\n");
        printf("1. Cadastrar produto\n");
        printf("2. Valor total investido no estoque\n");
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
                scanf("%d", &produtos[total].codigo);
                printf("Quantidade: ");
                scanf("%d", &produtos[total].quantidade);
                printf("Preco: ");
                scanf("%f", &produtos[total].preco);
                total++;
                printf("Produto cadastrado!\n");
                break;

            case 2: {
                // "soma" precisa ser float, senão o resultado seria truncado
                float soma = 0;
                for (int i = 0; i < total; i++) {
                    soma += produtos[i].quantidade * produtos[i].preco;
                }
                printf("Valor total investido: R$ %.2f\n", soma);
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

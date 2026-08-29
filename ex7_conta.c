#include <stdio.h>

#define MAX 100

typedef struct {
    int numeroConta;
    float saldo;
} Conta;

int main() {
    Conta contas[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n--- CONTA BANCARIA ---\n");
        printf("1. Cadastrar conta\n");
        printf("2. Depositar\n");
        printf("3. Mostrar todas as contas\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total >= MAX) {
                    printf("Limite atingido!\n");
                    break;
                }
                printf("Numero da conta: ");
                scanf("%d", &contas[total].numeroConta);
                printf("Saldo inicial: ");
                scanf("%f", &contas[total].saldo);
                total++;
                printf("Conta cadastrada!\n");
                break;

            case 2: {
                if (total == 0) {
                    printf("Nenhuma conta cadastrada.\n");
                    break;
                }
                int indice;
                float valor;
                printf("Digite o indice da conta (0 a %d): ", total - 1);
                scanf("%d", &indice);

                // sempre validar o indice antes de acessar o vetor!
                if (indice < 0 || indice >= total) {
                    printf("Indice invalido!\n");
                    break;
                }
                printf("Valor do deposito: ");
                scanf("%f", &valor);
                contas[indice].saldo += valor; // soma ao saldo existente
                printf("Deposito realizado! Novo saldo: R$ %.2f\n", contas[indice].saldo);
                break;
            }

            case 3:
                if (total == 0) {
                    printf("Nenhuma conta cadastrada.\n");
                    break;
                }
                for (int i = 0; i < total; i++) {
                    printf("[%d] Conta: %d | Saldo: R$ %.2f\n",
                           i, contas[i].numeroConta, contas[i].saldo);
                }
                break;

            case 4:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}

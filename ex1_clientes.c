#include <stdio.h>

#define MAX 100

// A struct agrupa vários dados relacionados em um único "pacote"
typedef struct {
    int codigo;
    int idade;
    char telefone[15];
} Cliente;

int main() {
    Cliente clientes[MAX];   // vetor de structs: até 100 clientes
    int total = 0;           // quantos clientes já foram cadastrados
    int opcao;

    do {
        printf("\n--- MENU CLIENTES ---\n");
        printf("1. Cadastrar cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total >= MAX) {
                    printf("Limite de clientes atingido!\n");
                    break;
                }
                printf("Codigo: ");
                scanf("%d", &clientes[total].codigo);
                printf("Idade: ");
                scanf("%d", &clientes[total].idade);
                printf("Telefone: ");
                scanf("%14s", clientes[total].telefone); // %14s evita estourar o buffer de 15
                total++;
                printf("Cliente cadastrado com sucesso!\n");
                break;

            case 2:
                if (total == 0) {
                    printf("Nenhum cliente cadastrado.\n");
                    break;
                }
                for (int i = 0; i < total; i++) {
                    printf("Codigo: %d | Idade: %d | Telefone: %s\n",
                           clientes[i].codigo, clientes[i].idade, clientes[i].telefone);
                }
                break;

            case 3:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    return 0;
}

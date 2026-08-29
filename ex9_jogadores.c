#include <stdio.h>

#define MAX 100

typedef struct {
    int id;
    int pontos;
} Jogador;

int main() {
    Jogador jogadores[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n--- CAMPEONATO ---\n");
        printf("1. Cadastrar jogador\n");
        printf("2. Buscar jogador por ID\n");
        printf("3. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total >= MAX) {
                    printf("Limite atingido!\n");
                    break;
                }
                printf("ID do jogador: ");
                scanf("%d", &jogadores[total].id);
                printf("Pontos: ");
                scanf("%d", &jogadores[total].pontos);
                total++;
                printf("Jogador cadastrado!\n");
                break;

            case 2: {
                int idBusca;
                printf("Digite o ID a buscar: ");
                scanf("%d", &idBusca);

                int encontrado = 0; // flag: 0 = ainda nao achou
                for (int i = 0; i < total; i++) {
                    if (jogadores[i].id == idBusca) {
                        printf("Jogador encontrado! ID: %d | Pontos: %d\n",
                               jogadores[i].id, jogadores[i].pontos);
                        encontrado = 1;
                        break; // achou, nao precisa continuar o loop
                    }
                }
                if (!encontrado) {
                    printf("Jogador com ID %d nao encontrado.\n", idBusca);
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

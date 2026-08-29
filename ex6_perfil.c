#include <stdio.h>

#define MAX 100

typedef struct {
    int codigo;
    float peso;
    float altura;
} Perfil;

int main() {
    Perfil alunos[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n--- RELATORIO ACADEMIA ---\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Exibir aluno mais alto\n");
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
                scanf("%d", &alunos[total].codigo);
                printf("Peso (kg): ");
                scanf("%f", &alunos[total].peso);
                printf("Altura (m): ");
                scanf("%f", &alunos[total].altura);
                total++;
                printf("Aluno cadastrado!\n");
                break;

            case 2: {
                if (total == 0) {
                    printf("Nenhum aluno cadastrado.\n");
                    break;
                }
                // "busca de maior valor": guarda o indice do maior encontrado até agora
                int indiceMaior = 0;
                for (int i = 1; i < total; i++) {
                    if (alunos[i].altura > alunos[indiceMaior].altura) {
                        indiceMaior = i;
                    }
                }
                printf("Aluno mais alto -> Codigo: %d | Altura: %.2fm | Peso: %.2fkg\n",
                       alunos[indiceMaior].codigo, alunos[indiceMaior].altura, alunos[indiceMaior].peso);
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

#include <stdio.h>

#define MAX 100

typedef struct {
    int matricula;
    float nota1;
    float nota2;
} Aluno;

int main() {
    Aluno alunos[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n--- DIARIO DE NOTAS ---\n");
        printf("1. Cadastrar aluno e notas\n");
        printf("2. Listar matricula e media\n");
        printf("3. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total >= MAX) {
                    printf("Limite atingido!\n");
                    break;
                }
                printf("Matricula: ");
                scanf("%d", &alunos[total].matricula);
                printf("Nota 1: ");
                scanf("%f", &alunos[total].nota1);
                printf("Nota 2: ");
                scanf("%f", &alunos[total].nota2);
                total++;
                printf("Aluno cadastrado!\n");
                break;

            case 2:
                if (total == 0) {
                    printf("Nenhum aluno cadastrado.\n");
                    break;
                }
                for (int i = 0; i < total; i++) {
                    float media = (alunos[i].nota1 + alunos[i].nota2) / 2.0f;
                    printf("Matricula: %d | Media: %.2f\n", alunos[i].matricula, media);
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

#include <stdio.h>

struct Aluno {
    int codigo;
    float n1;
    float n2;
    float media;
};

int main() {
    struct Aluno alunos[100];
    int n = 0;
    int op, i;

    do {
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar medias\n");
        printf("3 - Sair\n");
        scanf("%d", &op);

        if (op == 1) {
            printf("Codigo: ");
            scanf("%d", &alunos[n].codigo);
            printf("Nota 1: ");
            scanf("%f", &alunos[n].n1);
            printf("Nota 2: ");
            scanf("%f", &alunos[n].n2);
            alunos[n].media = (alunos[n].n1 + alunos[n].n2) / 2;
            n++;
        }

        if (op == 2) {
            for (i = 0; i < n; i++) {
                printf("Aluno %d - Media: %.2f", alunos[i].codigo, alunos[i].media);
                if (alunos[i].media >= 6)
                    printf(" - Aprovado\n");
                else
                    printf(" - Reprovado\n");
            }
        }

    } while (op != 3);

    return 0;
}

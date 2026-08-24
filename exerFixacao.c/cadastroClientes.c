#include <stdio.h>

struct Cliente {
    int codigo;
    int idade;
    char telefone[15];
};

int main() {
    struct Cliente clientes[100];
    int n = 0;
    int op, i;

    do {
        printf("1 - Cadastrar cliente\n");
        printf("2 - Listar clientes\n");
        printf("3 - Sair\n");
        scanf("%d", &op);

        if (op == 1) {
            printf("Codigo: ");
            scanf("%d", &clientes[n].codigo);
            printf("Idade: ");
            scanf("%d", &clientes[n].idade);
            printf("Telefone: ");
            scanf("%s", clientes[n].telefone);
            n++;
        }

        if (op == 2) {
            for (i = 0; i < n; i++) {
                printf("%d - Idade: %d - Tel: %s\n", clientes[i].codigo, clientes[i].idade, clientes[i].telefone);
            }
        }

    } while (op != 3);

    return 0;
}

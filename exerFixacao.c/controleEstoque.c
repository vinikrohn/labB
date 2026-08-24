#include <stdio.h>

struct Produto {
    int codigo;
    int qtd;
    float preco;
};

int main() {
    struct Produto produtos[100];
    int n = 0;
    int op, i;
    float total;

    do {
        printf("1 - Cadastrar produto\n");
        printf("2 - Valor total do estoque\n");
        printf("3 - Sair\n");
        scanf("%d", &op);

        if (op == 1) {
            printf("Codigo: ");
            scanf("%d", &produtos[n].codigo);
            printf("Quantidade: ");
            scanf("%d", &produtos[n].qtd);
            printf("Preco: ");
            scanf("%f", &produtos[n].preco);
            n++;
        }

        if (op == 2) {
            total = 0;
            for (i = 0; i < n; i++) {
                total = total + produtos[i].qtd * produtos[i].preco;
            }
            printf("Total: %.2f\n", total);
        }

    } while (op != 3);

    return 0;
}

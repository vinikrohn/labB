#include <stdio.h>

#define MAX 100

typedef struct {
    int codigo;
    int anoPublicacao;
    int qtdPaginas;
} Livro;

int main() {
    Livro livros[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n--- BIBLIOTECA ---\n");
        printf("1. Cadastrar livro\n");
        printf("2. Filtrar livros publicados apos 2020\n");
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
                scanf("%d", &livros[total].codigo);
                printf("Ano de publicacao: ");
                scanf("%d", &livros[total].anoPublicacao);
                printf("Quantidade de paginas: ");
                scanf("%d", &livros[total].qtdPaginas);
                total++;
                printf("Livro cadastrado!\n");
                break;

            case 2: {
                int encontrou = 0; // "flag" para saber se algum livro passou no filtro
                for (int i = 0; i < total; i++) {
                    if (livros[i].anoPublicacao > 2020) {
                        printf("Codigo: %d | Ano: %d | Paginas: %d\n",
                               livros[i].codigo, livros[i].anoPublicacao, livros[i].qtdPaginas);
                        encontrou = 1;
                    }
                }
                if (!encontrou) {
                    printf("Nenhum livro publicado apos 2020.\n");
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

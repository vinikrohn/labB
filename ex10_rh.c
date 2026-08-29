#include <stdio.h>

#define MAX 100

typedef struct {
    int codigo;
    int idade;
    float salario;
} Funcionario;

int main() {
    Funcionario funcionarios[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n--- SISTEMA DE RH ---\n");
        printf("1. Cadastrar funcionario\n");
        printf("2. Contar funcionarios (idade > 40 e salario > R$5000)\n");
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
                scanf("%d", &funcionarios[total].codigo);
                printf("Idade: ");
                scanf("%d", &funcionarios[total].idade);
                printf("Salario: ");
                scanf("%f", &funcionarios[total].salario);
                total++;
                printf("Funcionario cadastrado!\n");
                break;

            case 2: {
                int contador = 0;
                for (int i = 0; i < total; i++) {
                    // condicional duplo: as duas condicoes precisam ser verdadeiras (&&)
                    if (funcionarios[i].idade > 40 && funcionarios[i].salario > 5000.0f) {
                        contador++;
                    }
                }
                printf("Funcionarios com mais de 40 anos e salario acima de R$5000: %d\n", contador);
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

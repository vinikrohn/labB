# Exercícios de C — Structs, Vetores e Menus

Material de estudo com 10 exercícios resolvidos e comentados, todos seguindo o mesmo padrão: **struct** (registro de dados) + **vetor de structs** (armazenamento) + **menu em loop** (interação com o usuário).

## Índice
1. [Cadastro de Clientes](#1-cadastro-de-clientes)
2. [Controle de Estoque](#2-controle-de-estoque)
3. [Diário de Notas](#3-diário-de-notas)
4. [Gerenciador de Biblioteca](#4-gerenciador-de-biblioteca)
5. [Catálogo de Carros](#5-catálogo-de-carros)
6. [Relatório de Altura e Peso](#6-relatório-de-altura-e-peso)
7. [Conta Bancária](#7-conta-bancária)
8. [Consumo de Energia](#8-consumo-de-energia)
9. [Pontuação de Jogadores](#9-pontuação-de-jogadores)
10. [Sistema de RH](#10-sistema-de-rh)

Como compilar qualquer um deles:
```bash
gcc nome_do_arquivo.c -o programa
./programa
```

---

## 1. Cadastro de Clientes

```c
#include <stdio.h>

#define MAX 100

typedef struct {
    int codigo;
    int idade;
    char telefone[15];
} Cliente;

int main() {
    Cliente clientes[MAX];
    int total = 0;
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
                scanf("%14s", clientes[total].telefone);
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
```

### Explicação linha a linha

| Linha | O que faz |
|---|---|
| `#include <stdio.h>` | Importa a biblioteca de entrada/saída (`printf`, `scanf`). Sem ela, essas funções não existem. |
| `#define MAX 100` | Constante de compilação: todo `MAX` no código vira `100` antes mesmo de compilar. Não ocupa memória como variável. |
| `typedef struct {...} Cliente;` | Cria um novo tipo de dado chamado `Cliente`, agrupando `codigo`, `idade` e `telefone`. |
| `char telefone[15];` | Texto em C é vetor de caracteres. `[15]` reserva 15 posições (14 úteis + 1 para o `\0`, marcador de fim de string). |
| `int main() {` | Ponto de entrada do programa. Retorna `int` para o sistema operacional. |
| `Cliente clientes[MAX];` | Vetor de 100 "gavetas", cada uma capaz de guardar um `Cliente` completo. |
| `int total = 0;` | Contador de quantos clientes foram realmente cadastrados (controla até onde o vetor tem dado válido). |
| `do { ... } while (opcao != 3);` | Loop que executa **pelo menos uma vez** antes de checar a condição — ideal pra menu, porque precisa mostrar as opções antes de saber se o usuário quer sair. |
| `scanf("%d", &opcao);` | Lê um inteiro digitado. O `&` passa o *endereço de memória* de `opcao`, porque `scanf` precisa saber onde escrever o valor lido. |
| `switch (opcao) { case 1: ... break; }` | Testa o valor de `opcao` e desvia para o bloco correspondente. `break` impede que a execução "caia" para o próximo `case` sem querer. |
| `if (total >= MAX) { ...; break; }` | Proteção contra estourar o vetor: sem isso, cadastrar o 101º cliente escreveria fora da memória reservada (bug grave em C). |
| `scanf("%d", &clientes[total].codigo);` | `clientes[total]` é a gaveta livre atual; `.codigo` acessa o campo dentro dela; `&` porque o `scanf` precisa do endereço, mesmo com vetor+struct juntos. |
| `scanf("%14s", clientes[total].telefone);` | Sem `&` aqui — o nome de um vetor já *é* o endereço do seu primeiro elemento. `%14s` limita a leitura evitando estourar o buffer de 15. |
| `total++;` | Incrementa o contador (equivale a `total = total + 1`). |
| `for (int i = 0; i < total; i++)` | Percorre só até `total` (não `MAX`), pois só ali existe dado válido cadastrado. |
| `printf("...%d...%s...", a, b, c);` | Cada `%` no texto casa em ordem com um argumento depois da vírgula (`%d` = inteiro, `%s` = string). |
| `return 0;` | Informa ao sistema operacional que o programa terminou sem erros. |

---

## 2. Controle de Estoque

```c
#include <stdio.h>

#define MAX 100

typedef struct {
    int codigo;
    int quantidade;
    float preco;
} Produto;

int main() {
    Produto produtos[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n--- MENU ESTOQUE ---\n");
        printf("1. Cadastrar produto\n");
        printf("2. Valor total investido no estoque\n");
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
                scanf("%d", &produtos[total].codigo);
                printf("Quantidade: ");
                scanf("%d", &produtos[total].quantidade);
                printf("Preco: ");
                scanf("%f", &produtos[total].preco);
                total++;
                printf("Produto cadastrado!\n");
                break;

            case 2: {
                float soma = 0;
                for (int i = 0; i < total; i++) {
                    soma += produtos[i].quantidade * produtos[i].preco;
                }
                printf("Valor total investido: R$ %.2f\n", soma);
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
```

### O que muda em relação ao Exercício 1

| Linha | O que faz |
|---|---|
| `float preco;` | Campo decimal — dinheiro precisa de casas decimais, por isso `float` em vez de `int`. |
| `scanf("%f", &produtos[total].preco);` | `%f` é o especificador de leitura para `float`. |
| `case 2: { float soma = 0; ... }` | As chaves `{ }` extras dentro do `case` criam um "escopo local", permitindo declarar `soma` só ali dentro sem conflitar com outros `case`s. |
| `soma += produtos[i].quantidade * produtos[i].preco;` | A cada volta do `for`, multiplica quantidade × preço daquele produto e acumula em `soma`. `+=` é atalho para `soma = soma + (...)`. |
| `printf("... R$ %.2f\n", soma);` | `%.2f` formata o float com exatamente 2 casas decimais (padrão de valor monetário). |

---

## 3. Diário de Notas

```c
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
```

### O que muda

| Linha | O que faz |
|---|---|
| `float media = (alunos[i].nota1 + alunos[i].nota2) / 2.0f;` | Soma as duas notas e divide por `2.0f` (float). Usar `2.0f` em vez de `2` garante que a divisão seja decimal, não seja truncada. |
| Cálculo dentro do `for` | A média é recalculada a cada aluno, na própria iteração — não é armazenada na struct, só usada na hora de imprimir. |

---

## 4. Gerenciador de Biblioteca

```c
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
                int encontrou = 0;
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
```

### O que muda — o padrão de "filtro"

| Linha | O que faz |
|---|---|
| `int encontrou = 0;` | Variável "flag" (bandeira): começa em `0` (falso), assumindo que nada será encontrado. |
| `if (livros[i].anoPublicacao > 2020) { ...; encontrou = 1; }` | Só imprime o livro se a condição bater. Quando pelo menos um bate, marca `encontrou = 1` (verdadeiro). |
| `if (!encontrou) { printf(...); }` | `!encontrou` lê-se "não encontrou". Se nenhum livro passou no filtro, `encontrou` continua `0` e cai aqui, avisando o usuário. |

---

## 5. Catálogo de Carros

```c
#include <stdio.h>

#define MAX 100

typedef struct {
    int codigo;
    int ano;
    float preco;
} Carro;

int main() {
    Carro carros[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n--- CATALOGO DE CARROS ---\n");
        printf("1. Cadastrar carro\n");
        printf("2. Buscar por preco maximo\n");
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
                scanf("%d", &carros[total].codigo);
                printf("Ano: ");
                scanf("%d", &carros[total].ano);
                printf("Preco: ");
                scanf("%f", &carros[total].preco);
                total++;
                printf("Carro cadastrado!\n");
                break;

            case 2: {
                float precoMax;
                printf("Digite o preco maximo: ");
                scanf("%f", &precoMax);

                int encontrou = 0;
                for (int i = 0; i < total; i++) {
                    if (carros[i].preco < precoMax) {
                        printf("Codigo: %d | Ano: %d | Preco: R$ %.2f\n",
                               carros[i].codigo, carros[i].ano, carros[i].preco);
                        encontrou = 1;
                    }
                }
                if (!encontrou) {
                    printf("Nenhum carro encontrado abaixo desse valor.\n");
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
```

### O que muda em relação ao Exercício 4

| Linha | O que faz |
|---|---|
| `float precoMax; scanf("%f", &precoMax);` | Diferente do ex4 (limite fixo `2020`), aqui o limite do filtro **vem do teclado**, digitado pelo usuário a cada busca. |
| `if (carros[i].preco < precoMax)` | Mesma estrutura de filtro do ex4, mas comparando contra a variável digitada em vez de um número fixo no código. |

---

## 6. Relatório de Altura e Peso

```c
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
```

### O que muda — o padrão de "buscar o maior"

| Linha | O que faz |
|---|---|
| `int indiceMaior = 0;` | Assume, de início, que o primeiro cadastrado (índice 0) é o mais alto. |
| `for (int i = 1; i < total; i++)` | Repare que começa em `i = 1`, não `0` — porque o índice 0 já foi usado como ponto de partida acima. |
| `if (alunos[i].altura > alunos[indiceMaior].altura) { indiceMaior = i; }` | A cada volta, compara o aluno atual com o "campeão" guardado até agora. Se for mais alto, `indiceMaior` é atualizado para esse novo índice. |
| `alunos[indiceMaior]...` | No final do loop, `indiceMaior` aponta exatamente para a posição do aluno mais alto — usado para imprimir o resultado. |

---

## 7. Conta Bancária

```c
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

                if (indice < 0 || indice >= total) {
                    printf("Indice invalido!\n");
                    break;
                }
                printf("Valor do deposito: ");
                scanf("%f", &valor);
                contas[indice].saldo += valor;
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
```

### O que muda — o padrão de "alterar por índice" (o mais delicado dos 10)

| Linha | O que faz |
|---|---|
| `int indice; scanf("%d", &indice);` | O usuário escolhe manualmente qual posição do vetor quer alterar. |
| `if (indice < 0 \|\| indice >= total) { ...; break; }` | **Validação obrigatória.** `\|\|` é "ou lógico": se o índice for negativo OU maior/igual ao total cadastrado, é inválido. Sem essa checagem, acessar `contas[999]` quando só existem 3 contas seria acessar memória fora do vetor — um bug sério em C, que não é barrado automaticamente como em Python. |
| `contas[indice].saldo += valor;` | Soma o valor digitado ao saldo *já existente* naquela posição (não substitui, acumula). |
| `while (opcao != 4)` | Esse exercício tem 4 opções no menu (não 3), então a condição de saída muda de acordo. |

---

## 8. Consumo de Energia

```c
#include <stdio.h>

#define MAX 100

typedef struct {
    int numeroCasa;
    float consumoKwh;
} Imovel;

int main() {
    Imovel imoveis[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n--- CONSUMO DE ENERGIA ---\n");
        printf("1. Cadastrar imovel\n");
        printf("2. Media de consumo da rua\n");
        printf("3. Listar imoveis acima da media\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total >= MAX) {
                    printf("Limite atingido!\n");
                    break;
                }
                printf("Numero da casa: ");
                scanf("%d", &imoveis[total].numeroCasa);
                printf("Consumo (kWh): ");
                scanf("%f", &imoveis[total].consumoKwh);
                total++;
                printf("Imovel cadastrado!\n");
                break;

            case 2: {
                if (total == 0) {
                    printf("Nenhum imovel cadastrado.\n");
                    break;
                }
                float soma = 0;
                for (int i = 0; i < total; i++) soma += imoveis[i].consumoKwh;
                printf("Media de consumo: %.2f kWh\n", soma / total);
                break;
            }

            case 3: {
                if (total == 0) {
                    printf("Nenhum imovel cadastrado.\n");
                    break;
                }
                float soma = 0;
                for (int i = 0; i < total; i++) soma += imoveis[i].consumoKwh;
                float media = soma / total;

                printf("Imoveis com consumo acima da media (%.2f kWh):\n", media);
                int encontrou = 0;
                for (int i = 0; i < total; i++) {
                    if (imoveis[i].consumoKwh > media) {
                        printf("Casa %d | Consumo: %.2f kWh\n", imoveis[i].numeroCasa, imoveis[i].consumoKwh);
                        encontrou = 1;
                    }
                }
                if (!encontrou) printf("Nenhum imovel acima da media.\n");
                break;
            }

            case 4:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}
```

### O que muda

| Linha | O que faz |
|---|---|
| `case 2` calcula `soma / total` | Mesmo padrão de agregação do ex2 (estoque), aplicado a uma média em vez de uma multiplicação. |
| `case 3` recalcula `soma` e `media` | A média é calculada **de novo** dentro do `case 3`, porque cada `case` roda de forma isolada — uma variável criada no `case 2` não existe mais quando o usuário escolhe a opção `3` numa próxima passada pelo menu. |
| Dois `for` dentro do mesmo `case 3` | O primeiro `for` calcula a média; o segundo `for`, já com a média pronta, filtra e imprime quem está acima dela. |

---

## 9. Pontuação de Jogadores

```c
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

                int encontrado = 0;
                for (int i = 0; i < total; i++) {
                    if (jogadores[i].id == idBusca) {
                        printf("Jogador encontrado! ID: %d | Pontos: %d\n",
                               jogadores[i].id, jogadores[i].pontos);
                        encontrado = 1;
                        break;
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
```

### O que muda — busca com saída antecipada

| Linha | O que faz |
|---|---|
| `if (jogadores[i].id == idBusca)` | Compara o ID de cada jogador com o valor buscado. `==` compara igualdade (não confundir com `=`, que atribui valor). |
| `break;` **dentro do `for`** | Diferente dos `break` que vimos até agora (que saem do `switch`), este sai do **laço `for`** assim que encontra o jogador — não faz sentido continuar varrendo o resto do vetor depois de já ter achado quem procurava. |
| `encontrado = 1;` antes do `break` | Marca que achou, para o `if (!encontrado)` de fora do `for` saber se deve avisar "não encontrado" ou não. |

---

## 10. Sistema de RH

```c
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
```

### O que muda — condição dupla com `&&`

| Linha | O que faz |
|---|---|
| `if (funcionarios[i].idade > 40 && funcionarios[i].salario > 5000.0f)` | `&&` é "e lógico": **as duas** condições precisam ser verdadeiras ao mesmo tempo para entrar no `if`. Se fosse `\|\|` (ou lógico), bastaria uma das duas ser verdadeira — o resultado do programa mudaria completamente. |
| `contador++;` | Simples contador que soma 1 a cada funcionário que passa nas duas condições. |

---

## Resumo dos padrões (para revisão rápida)

| Padrão | Exercícios | Ideia central |
|---|---|---|
| Listar tudo | 1, 7 | `for` simples, imprime cada posição do vetor |
| Filtrar (limite fixo ou digitado) | 4, 5, 8 | `for` + `if` dentro, usa uma "flag" (`encontrou`) para avisar se nada bateu |
| Buscar por chave (ID) | 9 | `for` + `if (campo == valor)` + `break` para parar assim que encontra |
| Buscar maior/menor | 6 | Guarda o *índice* do "campeão" e compara a cada volta do `for` |
| Agregação (soma, média, contagem) | 2, 3, 8, 10 | Variável acumuladora que cresce dentro do `for` (`soma +=`, `contador++`) |
| Alterar por índice | 7 | **Sempre valida** `indice < 0 \|\| indice >= total` antes de acessar o vetor |
| Condição composta | 10 | `&&` (E — as duas precisam ser verdade) vs `\|\|` (OU — uma basta) |

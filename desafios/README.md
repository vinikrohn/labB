# Desafios de C++ — nomes, vetores e arquivos

Seis programas seguindo o mesmo modelo dos originais, com identificadores e nomes de arquivo trocados.

| Arquivo | O que faz | Entrada | Saída |
|---|---|---|---|
| `desafio1.cpp` | lê n nomes completos e exibe | teclado | tela |
| `desafio2.cpp` | lê n nomes, separa o sobrenome (`struct Cadastro`) | teclado | tela |
| `desafio3.cpp` | lê n nomes em um vetor e mostra a quantidade de caracteres | teclado | tela |
| `desafio4.cpp` | exibe os nomes lidos de um arquivo | `nomes_origem.txt` | tela |
| `desafio5.cpp` | lê do arquivo, separa o sobrenome e grava | `nomes_origem.txt` | `sobrenomes_destino.txt` |
| `desafio6.cpp` | lê do arquivo, exibe e grava nome + tamanho | `nomes_origem.txt` | `nomes_tamanho_destino.txt` |

`nomes_origem.txt` acompanha o pacote com 5 nomes de exemplo (um por linha).

## Como compilar e executar

```bash
g++ -std=c++17 -Wall -o desafio1 desafio1.cpp
./desafio1
```

Os desafios 4, 5 e 6 precisam que `nomes_origem.txt` esteja na mesma pasta do executável.

## Principais trocas em relação aos originais

| Original | Nova versão |
|---|---|
| `n` | `totalPessoas` |
| `i` | `indice` |
| `nome` / `linha` | `nomeCompleto` / `linhaLida` |
| `struct Pessoa { nomeCompleto; sobreNome; }` | `struct Cadastro { nomeCompleto; ultimoSobrenome; }` |
| `extrairSobrenome()` | `separarSobrenome()` |
| `exibirNomesComTamanhos()` | `exibirNomesComQuantidadeCaracteres()` |
| `lerNomesDoArquivo()` | `carregarNomesDoArquivo()` |
| `gravarNomesComTamanho()` | `gravarNomesComQuantidadeCaracteres()` |
| `pos` | `posicaoEspaco` |
| `arquivo` | `arquivoOrigem` / `arquivoDestino` |
| `nomes.txt` / `nomes_destino.txt` | `nomes_origem.txt` / `sobrenomes_destino.txt` / `nomes_tamanho_destino.txt` |

## Dois ajustes além da renomeação

1. **`desafio1`** — o enunciado pede "com módulo/método", mas o original fazia tudo dentro do `main`. A leitura e a exibição passaram para a função `lerEExibirNomes()`.
2. **`desafio4`** — o original recebia o parâmetro `nomeArquivo` mas abria `"nomes.txt"` fixo no código, ignorando o parâmetro. Agora a função usa o `caminhoOrigem` recebido.

Todos foram compilados com `g++ -std=c++17 -Wall` (sem warnings) e executados com dados de teste.

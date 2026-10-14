#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

// Passagem por REFERENCIA (&): as alteracoes feitas no vetor
// dentro do metodo ficam valendo no main.
void popularVetor(vector<int> &v, int qtd, int inicio, int fim) {
    int numero;
    for (int i = 0; i < qtd; i++) {
        numero = (rand() % (fim - inicio + 1)) + inicio;
        v.push_back(numero);
    }
}

// Passagem por VALOR: o metodo recebe uma copia, so le os dados.
void exibirVetor(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
}

// Metodo COM RETORNO: devolve true se o valor existe no vetor.
bool contem(vector<int> v, int valor) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == valor) {
            return true;
        }
    }
    return false;
}

// EXERCICIO 1 - metodo SEM RETORNO (void), parametros por VALOR.
// Exibe os numeros que aparecem nos dois vetores.
void exercicio1(vector<int> vetorA, vector<int> vetorB) {
    vector<int> jaExibidos; // evita mostrar o mesmo numero duas vezes

    cout << "Numeros que aparecem nos dois vetores: ";
    for (int i = 0; i < vetorA.size(); i++) {
        if (contem(vetorB, vetorA[i]) && !contem(jaExibidos, vetorA[i])) {
            cout << vetorA[i] << "\t";
            jaExibidos.push_back(vetorA[i]);
        }
    }
    cout << endl;
}

// EXERCICIO 2 - metodo COM RETORNO.
// vetorA e vetorB por VALOR; vetorResultado por REFERENCIA.
// Armazena em vetorResultado os numeros comuns e retorna esses dados.
vector<int> exercicio2(vector<int> vetorA, vector<int> vetorB, vector<int> &vetorResultado) {
    for (int i = 0; i < vetorA.size(); i++) {
        if (contem(vetorB, vetorA[i]) && !contem(vetorResultado, vetorA[i])) {
            vetorResultado.push_back(vetorA[i]);
        }
    }
    return vetorResultado;
}

int main() {
    srand(time(NULL)); // chamado UMA vez so, aqui no main

    vector<int> vetorA;
    vector<int> vetorB;
    vector<int> vetorResultado;
    int n = 10;

    popularVetor(vetorA, n, 1, 20);
    popularVetor(vetorB, n, 1, 20);

    cout << "Vetor A: ";
    exibirVetor(vetorA);
    cout << "Vetor B: ";
    exibirVetor(vetorB);

    cout << endl << "--- Exercicio 1 ---" << endl;
    exercicio1(vetorA, vetorB);

    cout << endl << "--- Exercicio 2 ---" << endl;
    vector<int> retorno = exercicio2(vetorA, vetorB, vetorResultado);
    cout << "Vetor resultado: ";
    exibirVetor(retorno);

    return 0;
}

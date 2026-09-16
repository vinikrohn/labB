/* 1) Construa um programa (com modulo/metodo) que leia n nomes completos de
      pessoas e os exiba na tela. */

#include <iostream>
#include <string>

using namespace std;

void lerEExibirNomes(int totalPessoas) {
    for (int indice = 0; indice < totalPessoas; ++indice) {
        string nomeCompleto;
        cout << "Digite o nome completo da pessoa " << (indice + 1) << ": ";
        getline(cin, nomeCompleto);
        cout << "Nome Completo: " << nomeCompleto << endl;
    }
}

int main() {
    int totalPessoas;

    cout << "Digite a quantidade de pessoas: ";
    cin >> totalPessoas;
    cin.ignore(); // limpa o buffer do teclado

    lerEExibirNomes(totalPessoas);

    return 0;
}

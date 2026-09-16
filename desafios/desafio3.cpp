/* 3) Construa um programa (com modulo/metodo) que leia n nomes de pessoas,
      armazene em um vetor e exiba cada nome com a sua quantidade de caracteres. */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void exibirNomesComQuantidadeCaracteres(const vector<string>& listaNomes) {
    for (const auto& nomeCompleto : listaNomes) {
        cout << "Nome: " << nomeCompleto
             << ", Tamanho: " << nomeCompleto.length() << " caracteres" << endl;
    }
}

int main() {
    int totalPessoas;

    cout << "Digite a quantidade de pessoas: ";
    cin >> totalPessoas;
    cin.ignore(); // limpa o buffer do teclado

    vector<string> listaNomes(totalPessoas);

    for (int indice = 0; indice < totalPessoas; ++indice) {
        cout << "Digite o nome da pessoa " << (indice + 1) << ": ";
        getline(cin, listaNomes[indice]);
    }

    exibirNomesComQuantidadeCaracteres(listaNomes);

    return 0;
}

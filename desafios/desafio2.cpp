/* 2) Construa um programa (com modulo/metodo) que leia n nomes completos de
      pessoas, separe o sobrenome de cada uma e exiba nome completo e sobrenome. */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Cadastro {
    string nomeCompleto;
    string ultimoSobrenome;
};

string separarSobrenome(const string& nomeCompleto) {
    size_t posicaoEspaco = nomeCompleto.find_last_of(' ');
    if (posicaoEspaco != string::npos) {
        return nomeCompleto.substr(posicaoEspaco + 1);
    }
    return ""; // devolve string vazia quando nao ha sobrenome
}

int main() {
    int totalPessoas;

    cout << "Digite a quantidade de pessoas: ";
    cin >> totalPessoas;
    cin.ignore(); // limpa o buffer do teclado

    vector<Cadastro> listaCadastros(totalPessoas);

    for (int indice = 0; indice < totalPessoas; ++indice) {
        cout << "Digite o nome completo da pessoa " << (indice + 1) << ": ";
        getline(cin, listaCadastros[indice].nomeCompleto);
        listaCadastros[indice].ultimoSobrenome =
            separarSobrenome(listaCadastros[indice].nomeCompleto);
    }

    cout << "\nNomes completos e sobrenomes:\n";
    for (const auto& cadastro : listaCadastros) {
        cout << "Nome Completo: " << cadastro.nomeCompleto
             << ", Sobrenome: " << cadastro.ultimoSobrenome << endl;
    }

    return 0;
}

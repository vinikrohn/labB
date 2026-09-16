/* 4) Construa um programa (com modulo/metodo) que leia n nomes de pessoas
      DE UM ARQUIVO DE ORIGEM e os exiba na tela. */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void exibirNomesDoArquivo(const string& caminhoOrigem) {
    ifstream arquivoOrigem(caminhoOrigem);
    if (!arquivoOrigem.is_open()) {
        cerr << "Erro ao abrir o arquivo de origem!" << endl;
        return;
    }

    string linhaLida;
    while (getline(arquivoOrigem, linhaLida)) {
        cout << "Nome Completo: " << linhaLida << endl;
    }

    arquivoOrigem.close();
}

int main() {
    exibirNomesDoArquivo("nomes_origem.txt");
    return 0;
}

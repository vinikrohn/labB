/* 6) Construa um programa (com modulo/metodo) que leia n nomes de pessoas
      DE UM ARQUIVO DE ORIGEM, armazena em um vetor de nomes e os exiba na tela.
      Porem, e necessario GRAVAR ESSES NOMES JUNTAMENTE COM A QUANTIDADE DE
      CARACTERES EM UM ARQUIVO DESTINO. */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void carregarNomesDoArquivo(const string& caminhoOrigem, vector<string>& listaNomes) {
    ifstream arquivoOrigem(caminhoOrigem);
    if (!arquivoOrigem.is_open()) {
        cerr << "Erro ao abrir o arquivo de origem!" << endl;
        return;
    }

    string linhaLida;
    while (getline(arquivoOrigem, linhaLida)) {
        listaNomes.push_back(linhaLida);
    }

    arquivoOrigem.close();
}

void exibirNomes(const vector<string>& listaNomes) {
    for (const auto& nomeCompleto : listaNomes) {
        cout << "Nome: " << nomeCompleto
             << " | Tamanho: " << nomeCompleto.size() << " caracteres" << endl;
    }
}

void gravarNomesComQuantidadeCaracteres(const string& caminhoDestino,
                                        const vector<string>& listaNomes) {
    ofstream arquivoDestino(caminhoDestino);
    if (!arquivoDestino.is_open()) {
        cerr << "Erro ao abrir o arquivo de destino!" << endl;
        return;
    }

    for (const auto& nomeCompleto : listaNomes) {
        arquivoDestino << nomeCompleto << "; " << nomeCompleto.size() << endl;
    }

    arquivoDestino.close();
}

int main() {
    vector<string> listaNomes;

    carregarNomesDoArquivo("nomes_origem.txt", listaNomes);
    exibirNomes(listaNomes);
    gravarNomesComQuantidadeCaracteres("nomes_tamanho_destino.txt", listaNomes);

    cout << "Dados salvos com sucesso no arquivo de destino!" << endl;

    return 0;
}

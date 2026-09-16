/* 5) Construa um programa (com modulo/metodo) que leia n nomes completos
      DE UM ARQUIVO DE ORIGEM, separe o sobrenome de cada pessoa e GRAVE o nome
      completo junto com o sobrenome em um ARQUIVO DESTINO. */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Cadastro {
    string nomeCompleto;
    string ultimoSobrenome;
};

void separarSobrenome(const string& nomeCompleto, string& ultimoSobrenome) {
    size_t posicaoEspaco = nomeCompleto.find_last_of(' ');
    if (posicaoEspaco != string::npos) {
        ultimoSobrenome = nomeCompleto.substr(posicaoEspaco + 1);
    } else {
        ultimoSobrenome = ""; // devolve string vazia quando nao ha sobrenome
    }
}

int main() {
    vector<Cadastro> listaCadastros;

    // abre o arquivo para leitura
    ifstream arquivoOrigem("nomes_origem.txt");
    if (!arquivoOrigem.is_open()) {
        cerr << "Erro ao abrir o arquivo de origem!" << endl;
        return 1;
    }

    string linhaLida;
    while (getline(arquivoOrigem, linhaLida)) {
        Cadastro cadastro;
        cadastro.nomeCompleto = linhaLida;
        separarSobrenome(cadastro.nomeCompleto, cadastro.ultimoSobrenome);
        listaCadastros.push_back(cadastro);
    }

    arquivoOrigem.close();

    // abre o arquivo para escrita
    ofstream arquivoDestino("sobrenomes_destino.txt");
    if (!arquivoDestino.is_open()) {
        cerr << "Erro ao abrir o arquivo de destino!" << endl;
        return 1;
    }

    for (const auto& cadastro : listaCadastros) {
        arquivoDestino << cadastro.nomeCompleto << "; "
                       << cadastro.ultimoSobrenome << endl;
    }

    arquivoDestino.close();

    cout << "Dados salvos com sucesso no arquivo de destino!" << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "util.h"

int main() {
    //rotina que carrega os stop words do arquivo para listaStopWords
    ifstream arquivoStopWords;
    vector<string> listaStopWords;
    arquivoStopWords.open("stopWords.txt");
    if (!arquivoStopWords) {
        cout << "Arquivo de stop words nao localizado. Programa encerrado." << endl;
        exit(0);
    } 

    //le o arquivo capturando as frases
	string linha;
	while (!arquivoStopWords.eof()) {
		getline(arquivoStopWords,linha); //lendo a linha inteira
        //colocar a linha para maiusculo
        linha = paraMaiusculoStringComRetorno(linha);

        listaStopWords.push_back(linha);
		
	}
	arquivoStopWords.close();
    //fim rotina que carrega os stop words do arquivo para listaStopWords


    //rotina que exiba os stop words inseridos na listaStopWords
    for (int i = 0; i < listaStopWords.size(); i++) {
        cout << listaStopWords[i] << ", ";
    }
    cout << "\n\n\n";
    //fim rotina que exiba os stop words inseridos na listaStopWords
    

    //rotina que abre e le arquivo original palavra por palavra
    ifstream arquivoTextoOriginal;
    string nomeArquivo;
    cout << "Digite caminho e nome do arquivo: ";
    cin >> nomeArquivo;
    arquivoTextoOriginal.open(nomeArquivo);

    if (!arquivoTextoOriginal) {
        cout << "Arquivo original para tratamento de stop words nao localizado. Programa encerrado." << endl;
        exit(0);
    } 

    ofstream arquivoTextoSemStopWords;
    arquivoTextoSemStopWords.open("arquivoTextoSemStopWords.txt");
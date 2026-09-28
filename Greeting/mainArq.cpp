#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


string maiusculo(string palavra) {
    for (int i = 0; i < palavra.size(); i++) {
        palavra[i] = toupper(palavra[i]);
    }
    return palavra;
}


bool ehStopWord(string palavra, vector<string> stopWords) {
    for (int i = 0; i < stopWords.size(); i++) {
        if (maiusculo(palavra) == stopWords[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<string> stopWords;
    string palavra;

    
    ifstream arqStop("stopWords.txt");
    if (!arqStop.is_open()) {
        cout << "erro" << endl;
        return 1;
    }
    while (arqStop >> palavra) {
        stopWords.push_back(maiusculo(palavra));
    }
    arqStop.close();

    
    ifstream arqTexto("texto.txt");
    if (!arqTexto.is_open()) {
        cout << "erro" << endl;
        return 1;
    }


    ofstream arqSaida("arquivoSemStopWords.txt");
    if (!arqSaida.is_open()) {
        cout << "erro" << endl;
        return 1;
    }

    
    while (arqTexto >> palavra) {
        
        if (!ehStopWord(palavra, stopWords)) {
            arqSaida << palavra << " ";
        }
    }

    arqTexto.close();
    arqSaida.close();

    cout << "veja o arquivo arquivoSemStopWords.txt" << endl;
    return 0;
}

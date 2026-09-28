#include <iostream>

#define TAM 100

using namespace std;

bool estaOrdenado(int vetor[], int tamanho) {
   for (int i = 0; i < tamanho - 1; i++) {
      if (vetor[i] > vetor[i + 1]) {
         return false;
      }
   }

   return true;
}

int main() {
   int vetor[TAM];
   int quantidade;

   cout << "Quantos numeros tem o vetor? ";
   cin >> quantidade;

   for (int i = 0; i < quantidade; i++) {
      cout << "Informe o numero " << (i + 1) << ": ";
      cin >> vetor[i];
   }

   if (estaOrdenado(vetor, quantidade)) {
      cout << "O vetor esta ordenado" << endl;
   } else {
      cout << "O vetor esta desordenado" << endl;
   }

   return 0;
}

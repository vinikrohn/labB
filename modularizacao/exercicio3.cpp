#include <iostream>
#include <string>

using namespace std;

int contarVogais(string frase) {
   int totalVogais = 0;

   for (int i = 0; i < frase.size(); i++) {
      if (frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u' ||
          frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U') {
         totalVogais++;
      }
   }

   return totalVogais;
}

int main() {
   string frase;

   cout << "Digite uma frase: ";
   getline(cin, frase);

   cout << "Quantidade de vogais na frase: " << contarVogais(frase) << endl;

   return 0;
}

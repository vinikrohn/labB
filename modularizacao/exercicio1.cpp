#include <iostream>
#include <string>

using namespace std;

void contarLetra(string palavra, char letra) {
   int total = 0;

   for (int i = 0; i < palavra.size(); i++) {
      if (palavra[i] == letra) {
         total++;
      }
   }

   cout << "A letra " << letra << " aparece " << total << " vez(es) na palavra." << endl;
}

int main() {
   string palavra;
   char letra;

   cout << "Informe uma palavra: ";
   cin >> palavra;

   cout << "Informe uma letra: ";
   cin >> letra;

   contarLetra(palavra, letra);

   return 0;
}

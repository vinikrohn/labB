#include <iostream>
#include <string>

using namespace std;

string converterMaiuscula(string frase) {
   for (int i = 0; i < frase.size(); i++) {
      if (frase[i] >= 'a' && frase[i] <= 'z') {
         frase[i] = frase[i] - 32;
      }
   }

   return frase;
}

int main() {
   string frase;

   cout << "Digite uma frase: ";
   getline(cin, frase);

   cout << "Frase em maiuscula: " << converterMaiuscula(frase) << endl;

   return 0;
}

#include <iostream>
#include <string>

using namespace std;

string primeiroNome(string nomeCompleto) {
   string primeiro = "";

   for (int i = 0; i < nomeCompleto.size(); i++) {
      if (nomeCompleto[i] == ' ') {
         break;
      }
      primeiro = primeiro + nomeCompleto[i];
   }

   return primeiro;
}

int main() {
   string nomeCompleto;

   cout << "Digite seu nome completo: ";
   getline(cin, nomeCompleto);

   cout << "Primeiro nome: " << primeiroNome(nomeCompleto) << endl;

   return 0;
}

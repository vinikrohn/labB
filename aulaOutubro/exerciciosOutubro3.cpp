#include <iostream>
#include <string>

using namespace std;

string gerarEmail(string nomeCompleto) {
   string primeiro = "";
   string ultimo = "";

   for (int i = 0; i < nomeCompleto.size(); i++) {
      if (nomeCompleto[i] == ' ') {
         break;
      }
      primeiro = primeiro + nomeCompleto[i];
   }

   for (int i = nomeCompleto.size() - 1; i >= 0; i--) {
      if (nomeCompleto[i] == ' ') {
         break;
      }
      ultimo = nomeCompleto[i] + ultimo;
   }

   string email = primeiro + "." + ultimo + "@ufn.edu.br";

   for (int i = 0; i < email.size(); i++) {
      if (email[i] >= 'A' && email[i] <= 'Z') {
         email[i] = email[i] + 32;
      }
   }

   return email;
}

int main() {
   string nomeCompleto;

   cout << "Digite o nome completo: ";
   getline(cin, nomeCompleto);

   cout << "Email: " << gerarEmail(nomeCompleto) << endl;

   return 0;
}

#include <iostream>
#include <string>

using namespace std;

bool cpfValido(string cpf) {
   if (cpf.size() != 11) {
      return false;
   }

   for (int i = 0; i < cpf.size(); i++) {
      if (cpf[i] < '0' || cpf[i] > '9') {
         return false;
      }
   }

   return true;
}

int main() {
   string cpf;

   cout << "Informe o CPF (sem pontuacao): ";
   cin >> cpf;

   if (cpfValido(cpf)) {
      cout << "CPF VALIDO" << endl;
   } else {
      cout << "CPF INVALIDO" << endl;
   }

   return 0;
}

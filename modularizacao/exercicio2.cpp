#include <iostream>
#include <string>

using namespace std;

void escreverSeValida(string dia, string mes, string ano) {
   int d = stoi(dia);
   int m = stoi(mes);
   int a = stoi(ano);

   if (d < 1 || d > 31) {
      cout << "DATA INVALIDA" << endl;
   } else if (m < 1 || m > 12) {
      cout << "DATA INVALIDA" << endl;
   } else if (d == 31 && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11)) {
      cout << "DATA INVALIDA" << endl;
   } else if (d == 30 && m == 2) {
      cout << "DATA INVALIDA" << endl;
   } else if (d == 29 && m == 2 && (a % 4 != 0)) {
      cout << "DATA INVALIDA" << endl;
   } else {
      cout << "DATA VALIDA" << endl;
   }
}

int main() {
   string dia, mes, ano;

   cout << "Informe o dia: ";
   cin >> dia;

   cout << "Informe o mes: ";
   cin >> mes;

   cout << "Informe o ano: ";
   cin >> ano;

   escreverSeValida(dia, mes, ano);

   return 0;
}

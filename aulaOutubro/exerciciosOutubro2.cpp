#include <iostream>
#include <string>

using namespace std;

bool dataValida(string data) {
   if (data.size() != 10) {
      return false;
   }

   for (int i = 0; i < data.size(); i++) {
      if (i == 2 || i == 5) {
         if (data[i] != '/') {
            return false;
         }
      } else if (data[i] < '0' || data[i] > '9') {
         return false;
      }
   }

   return true;
}

int main() {
   string data;

   cout << "Informe a data (dd/mm/aaaa): ";
   cin >> data;

   if (dataValida(data)) {
      cout << "DATA VALIDA" << endl;
   } else {
      cout << "DATA INVALIDA" << endl;
   }

   return 0;
}

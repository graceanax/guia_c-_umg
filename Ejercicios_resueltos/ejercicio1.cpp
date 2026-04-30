/*
1. Validación y clasificación de datos
Se solicita un programa que lea **N números (definido por el usuario)**
y determine:
* cantidad de positivos, negativos y ceros
* promedio de los positivos
* el número de mayor valor
*/

#include <iostream>
#include <vector>

using namespace std;

int main () {
  short int cantidad;
  vector<int> numeros;

  cout << "** Numeros **\n";

  cout << "Determine la antidad de numeros a ingresar: ";
  cin >> cantidad;

  for (short int i=0; i<cantidad; i++) {
    short int numero;
    cout << "Ingrese el numero: ";
    cin >> numero;
    numeros.push_back(numero);
  }

  for (short int i=0; i<numeros.size(); i++ ) {
    cout << numeros[i] << endl;
  }

  return 0;
}

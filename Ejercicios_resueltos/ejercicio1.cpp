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
  short int cantidad {0};
  short int nPositivos {0};
  double promPositivos {0};
  short int nCeros {0};
  short int nNegativos {0};
  short int mayor {0};

  cout << "** Numeros **\n";

  cout << "Determine la antidad de numeros a ingresar: ";
  cin >> cantidad;

  for (short int i=0; i<cantidad; i++) {
    short int numero;
    cout << "Ingrese el numero: ";
    cin >> numero;
    if (numero > 0) {
      nPositivos += 1;
      promPositivos += numero;
    } else if (numero < 0) {
      nNegativos += 1;
    } else { 
      nCeros += 1;
    }
    if (numero > mayor) {
      mayor = numero;
    }
  }

  cout << "Cantidad positivos: " << nPositivos << "\n";
  cout << "Promedio positivos: " << (promPositivos / nPositivos) << "\n";
  cout << "Cantidad negativos: " << nNegativos << "\n";
  cout << "Cantidad ceros: " << nCeros << "\n";

  return 0;
}
/*
0
245
-1
*/
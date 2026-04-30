/*
# 5. Simulación de menú con operaciones

Crear un menú que permita:

1. Registrar números
2. Mostrar números
3. Calcular promedio
4. Buscar un número
5. Ordenar los números (ascendente)
6. Salir

El programa debe mantener los datos mientras el usuario no salga.

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void buscar_numero (vector<int> numeros) {
  int num = 0;
  bool encontrado = false;
  int posicion;

  cout << "Ingrese el numero a buscar: ";
  cin >> num;
  for (int i=0; i<numeros.size(); i++) {
    if (num == numeros[i]) {
      encontrado = true;
      posicion = i;
      break;
    }
  }
  if (encontrado) {
    cout << "Se encontró " << num << " en la posición " << posicion << "\n";
  } else {
    cout << "No se encontró en numero " << num << "\n";
  }
}

int main () {
  vector<int> numeros;
  int opc=0;
  int suma=0;

  do {
    cout << "Menu de opciones para numeros \n";
    cout << "______________________________\n";
    cout << "[1] Registrar numero \n[2] Mostrar numeros\n[3] Calcular promedio\n";
    cout << "[4] Buscar numero\n[5] ordenar numeros\n[6] Salir\n";
    cout << "Ingrese una opción: ";

    cin >> opc;

    cout << "Eligio la opcion " << opc;

    switch(opc) {
      case 1:
        short int numero;
        cout << "\n** REGISTRAR NUMERO **\n";
        cout << "\nIngresar numero: ";
        cin >> numero;
        suma += numero;

        numeros.push_back(numero);
        break;
      case 2:
        cout << "\n** MOSTRAR NUMEROS **\n";
        if (numeros.size() == 0) {
          cout << "Debe ingresar numeros primero \n";
          break;
        }
        for (int i = 0; i < numeros.size(); i++) {
          cout << numeros[i] << " ";
        }
        break;
      case 3:
        cout << "\n** CALCULAR PROMEDIO **\n";
        if (numeros.size() == 0) {
          cout << "Debe ingresar numeros primero \n";
          break;
        }
        cout << "El promedio es: " << (suma/numeros.size()) << "\n";
        break;
      case 4:
        cout << "\n** BUSCAR NUMERO **\n";
        if (numeros.size() == 0) {
          cout << "Debe ingresar numeros primero \n";
          break;
        }
        buscar_numero(numeros);
        break;
      case 5:
        cout << "\n** ORDENAR NUMERO **\n";
        if (numeros.size() == 0){
          cout << "Debe ingresar numeros primero \n";
          break;
        } else if (numeros.size() == 1) {
          cout << numeros[0];
        } else {
          sort(numeros.begin(), numeros.end());
          cout << "\nNumeros ordenados correctamente.\n";
        }
        break;
      default:
        cout << "\nOpcion incorrecta\n";
    }
  } while (opc != 6);

}
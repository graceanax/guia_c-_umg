/*
# 2. Análisis de cadena

Dada una cadena ingresada por el usuario:

* contar cuántas vocales tiene
* contar cuántos espacios
* invertir la cadena
* determinar si es palíndromo
*/
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

string aMinusculas (string &cadena) {
    for(char &c : cadena) {
        c = tolower(c);
    }
    return cadena;
}


string invertirCadena (string cadena, string &cadena_invertida) {
    for (int i=cadena.size()-1; i>=0; i-- ) {
        cadena_invertida+=cadena[i];
    }

    return cadena_invertida;
}

int main () {
    string cadena{};
    string cadena_invertida{};
    short int vocales{0};
    short int espacios{0};

    cout << "Ingrese un texto: ";
    getline(cin, cadena);

    aMinusculas(cadena);
    invertirCadena(cadena, cadena_invertida);

    for (char c : cadena) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vocales += 1;
        } else if (c == ' ') {
            espacios += 1;
        }
    }

    cout << "Cadena original: " << cadena << "\n";
    cout << "Cadena invertida: " << cadena_invertida << "\n";
    cout << "Cantidad de vocales: " << vocales << "\n";
    cout << "Cantidad de espacios: " << espacios << "\n";
    
    cadena.erase(remove(cadena.begin(), cadena.end(), ' '), cadena.end());
    cadena_invertida.erase(std::remove(cadena_invertida.begin(), cadena_invertida.end(), ' '), cadena_invertida.end());

    cout << ((cadena == cadena_invertida)? "Palindromo" : "No es palindromo");

    return 0;
}
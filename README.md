# Sintaxis básica
## Bibliotecas básicas
### Entrada / salida

```cpp
#include <iostream>
```

Sirve para:
* `cin` → entrada de datos
* `cout` → salida de datos

### Archivos

```cpp
#include <fstream>
```
Sirve para trabajar con archivos.
Incluye:

* `ifstream` → leer archivos
* `ofstream` → escribir archivos
* `fstream` → leer y escribir

Ejemplo:

```cpp
ifstream archivo("datos.txt");
ofstream archivo("salida.txt");
```
### Cadenas tipo string

```cpp
#include <string>
```

### Vectores

```cpp
#include <vector>
```
Sirve para usar arreglos dinámicos.
Ejemplo:

```cpp
vector<int> numeros;
numeros.push_back(10);
```
### Números aleatorios

```cpp
#include <cstdlib>
#include <ctime>
```
Sirve para generar números random.
Funciones:

* `rand()`
* `srand()`
* `time(0)`

### Manejo de caracteres tipo C

```cpp
#include <cstring>
```
Sirve para trabajar con `char[]`.
Funciones importantes:
* `strcpy()` → copiar texto
* `strncpy()` → copiar con límite
* `strlen()` → longitud
Ejemplo:
```cpp
char nombre[20];
// strncpy(destino, origen, tamaño_max);, Copia hasta 20 caracteres como máximo en el arreglo nombre
strncpy(nombre, "Ana", 20);
```
### Matemática

```cpp
#include <cmath>
```
Sirve para operaciones matemáticas.
Funciones comunes:
* `sqrt(x)` → raíz cuadrada
* `pow(a, b)` → potencia
* `abs(x)` → valor absoluto

## Manipulación de entrada/salida

```cpp
#include <iomanip>
```
Sirve para formatear salida.
Ejemplo:

```cpp
cout << fixed << setprecision(2);
```
muestra decimales controlados

### Manejo de memoria

```cpp
#include <new>
```
Sirve para memoria dinámica (aunque normalmente no se usa directamente).
Se usa con:
```cpp
new
delete
```
### Flujos avanzados (streams)

```cpp
#include <ostream>
#include <istream>
```
Sirve para trabajar con funciones como:

```cpp
void imprimir(ostream &salida);
```

## Básicos

``` c++
cin >> variable;
cout << variable;
getline(cin, texto);

ifstream archivo("entrada.txt");
ofstream archivo("salida.txt");

```

## Switch
Sirve para elegir entre varias opciones exactas.

``` c++
switch (opcion) {
    case valor1:
        // código
        break;

    case valor2:
        // código
        break;

    default:
        // código si no coincide
}
```
**Ejemplo:**
``` c++
int opcion;

cout << "1. Sumar\n";
cout << "2. Restar\n";
cout << "Ingrese opcion: ";
cin >> opcion;

switch (opcion) {
    case 1:
        cout << "Eligio sumar";
        break;

    case 2:
        cout << "Eligio restar";
        break;

    default:
        cout << "Opcion invalida";
}
```
## Números random
``` c++
#include <cstdlib>
#include <ctime>

// se usa para que los números aleatorios cambien cada vez que ejecutas el programa
srand(time(0));

// rand() % cantidad + inicio;
int numero = rand() % 10 + 1;

```
**Ejemplo:**
``` c++
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int numero = rand() % 100 + 1;

    cout << "Numero aleatorio: " << numero;

    return 0;
}
```
## Arreglos
Guarda varios valores del mismo tipo en una sola variable.

`tipo nombre[tamaño];`

**Ejemplo:**
``` c++
int notas[5];

for (int i = 0; i < 5; i++) {
    cout << "Ingrese nota: ";
    cin >> notas[i];
}

for (int i = 0; i < 5; i++) {
    cout << notas[i] << endl;
}
```
### Arreglo de dos dimensiones / matriz

`tipo nombre[filas][columnas];``

**Ejemplo:**
``` c++
int matriz[2][3];

for (int fila = 0; fila < 2; fila++) {
    for (int columna = 0; columna < 3; columna++) {
        cout << "Ingrese valor: ";
        cin >> matriz[fila][columna];
    }
}
```
## Vector
Es parecido a un arreglo, pero puede crecer dinámicamente.

``` c++
#include <vector>

vector<int> numeros;
```
**Ejemplo:**
``` c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros;

    numeros.push_back(10);
    numeros.push_back(20);
    numeros.push_back(30);

    for (int i = 0; i < numeros.size(); i++) {
        cout << numeros[i] << endl;
    }

    return 0;
}
```
**Métodos comunes:**
``` c++
push_back(valor);   // agrega un dato
size();             // devuelve el tamaño
pop_back();         // elimina el último
clear();            // limpia el vector
```
## Struct
Una estructura permite agrupar varios datos relacionados.

``` c++
struct Nombre {
    tipo dato1;
    tipo dato2;
};
```

**Ejemplo:**
``` c++
#include <iostream>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    float promedio;
};

int main() {
    Estudiante e1;

    cout << "Nombre: ";
    cin >> e1.nombre;

    cout << "Edad: ";
    cin >> e1.edad;

    cout << "Promedio: ";
    cin >> e1.promedio;

    cout << e1.nombre << " tiene promedio " << e1.promedio;

    return 0;
}
```
### Arreglo de struct
Permite guardar varios registros del mismo tipo.
**Ejemplo:**
``` c++
struct Estudiante {
    string nombre;
    int nota;
};

int main() {
    Estudiante estudiantes[3];

    for (int i = 0; i < 3; i++) {
        cout << "Nombre: ";
        cin >> estudiantes[i].nombre;

        cout << "Nota: ";
        cin >> estudiantes[i].nota;
    }

    for (int i = 0; i < 3; i++) {
        cout << estudiantes[i].nombre << " - " << estudiantes[i].nota << endl;
    }

    return 0;
}
```
## Funciones
Una función es un bloque de código reutilizable.
``` c++
tipoRetorno nombreFuncion(parametros) {
    // código
    return valor;
}
```
**Básicos:**
``` c++
// por valor (copia) no cambia la variable original
void cambiar(int x) {
    x = 100;
}

// por referencia, si cambia la variable original
void cambiar(int &x) {
    x = 100;
}

// función con vector 
void mostrar(vector<int> v);

// función con vector por referencia 
void mostrar(vector<int> &v);

// función con struct Estudiante
void mostrar(Estudiante e);

// por ferencia
void mostrar(Estudiante &e);

// retorna un struct
Estudiante crear() {
    Estudiante e;

    cin >> e.nombre;
    cin >> e.nota;

    return e;
}
Estudiante nuevo = crear();

// Función con punteros
void cambiar(int *p) {
    *p = 50;
}

int x = 10;

cambiar(&x);

int, float → valor o referencia
arreglos → siempre referencia
vector → usar &
struct → usar &
matriz → indicar columnas
```

**Ejemplo:**
``` c++
int sumar(int a, int b) {
    return a + b;
}

int resultado = sumar(5, 3);
cout << resultado;
```
## Archivos
### Leer
Permite abrir un archivo externo y leer su contenido.

**Biblioteca**
`#include <fstream>`

**Básicos**
* `ofstream` → para escribir en archivos
* `ios::in` → leer
* `ios::out` → escribir
* `ios::binary` → modo binario (NO texto)

* `ifstream` → leer
* `ofstream` → escribir
* `fstream`  → leer y escribir

* `archivo.seekp(0);` → mueve puntero de escritura dentro de un archivo, en este caso al inicio
* `archivo.seekp(5 * sizeof(DatosCliente));` → Se mueve al registro 5
* `reinterpret_cast<char*>(&cliente)` → Convierte el struct en una dirección de memoria tipo char* (esto es obligatorio para trabajar con binarios)
* `strncpy(apellidoPaterno, valorApellidoPaterno, longitud);` → Copia texto de un string a un arreglo de caracteres,se usa por Porque en archivos binarios muchas veces se usan char y no strings  
* `nombre[19] = '\0';` → Es el fin de cadena en C/C++. Las cadenas tipo char[] funcionan así: `'A' 'n' 'a' '\0'` el siguiente ejemplo `char nombre[20] = "Ana";`en memoria guarda: `[A][n][a][\0][?][?][?]...[?]` ayuda a que no imprima basura. Si tengo `char nombre[20];`la última posición es `nombre[19]` y debo `nombre[19] = '\0';`

**Por qué char y no string?**
Se usa char[] porque permite manejar directamente la memoria, lo cual es necesario en:

* archivos binarios
* estructuras (struct)
* funciones

`string nombre = "Ana";`es una clase, maneja la memoria automáticamente.

`char nombre[20] = "Ana";` es un arreglo de caracteres, maneja memoria manualmente. Entonces en los archivos binarios se usa porque se guardan los bytes exactos en memoria.

String no guarda el texto directamente, guarda punteros, tamaño y cpaacidad.

Con char también sabemos que si colocamos que ocupa 20 bytes eso es lo que ocupará, esto permite acceder con `seekp`calcular posiciones, leer y escribir correctamente.

Usar **String** si trabajo en consola, no se usan archivos binarios y más facilidad. y *char* cuando uso archivos binarios, uso write y read, necesito tamaño fijo y uso struct para guardar datos.

**Ejemplo:**
``` c++
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream archivo("datos.txt");
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo";
    }

    return 0;
}
```
### Escribir
Permite crear o escribir información en un archivo.

**Ejemplo:**
``` c++
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream archivo("salida.txt");

    archivo << "Hola, este texto se guardo en un archivo.";

    archivo.close();

    return 0;
}
```

### Solicitar ruta
**Ejemplo:**
``` c++
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string ruta;
    string linea;

    cout << "Ingrese la ruta del archivo: ";
    getline(cin, ruta);

    ifstream archivo(ruta);

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }

        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo";
    }

    return 0;
}
```
## Acceso a memoria: punteros
Un puntero guarda la dirección de memoria de una variable.

**Símbolos importantes:**
``` c++
&   obtiene la dirección de memoria
*   accede al valor guardado en esa dirección
```
**Ejemplo:**
``` c++
#include <iostream>
using namespace std;

int main() {
    int numero = 10;
    int *puntero;

    puntero = &numero;

    cout << "Valor: " << numero << endl;
    cout << "Direccion: " << &numero << endl;
    cout << "Valor usando puntero: " << *puntero << endl;

    return 0;
}
```
## Referencias
Una referencia es otro nombre para una variable existente.
**Ejemplo:**
``` c++
int numero = 10;
int &ref = numero;

ref = 20;

cout << numero;

// > Resultado: 20
```
## Memoria dinámica 
Permite crear variables o arreglos durante la ejecución del programa.

**Ejemplo con una variable:**
``` c++
int *numero = new int;

*numero = 50;

cout << *numero;

delete numero;
```
**Ejemplo con arreglo dinámico:**
``` c++
int n;

cout << "Cantidad: ";
cin >> n;

int *numeros = new int[n];

for (int i = 0; i < n; i++) {
    cin >> numeros[i];
}

delete[] numeros;
```
## POO
Permite crear clases, que son moldes para objetos.
**Clase**
Una clase define atributos y métodos.
``` c++
class NombreClase {
private:
    // atributos

public:
    // métodos
};
```
**Ejemplo:**
``` c++
#include <iostream>
using namespace std;

class Estudiante {
private:
    string nombre;
    int edad;

public:
    void setNombre(string n) {
        nombre = n;
    }

    void setEdad(int e) {
        edad = e;
    }

    void mostrarDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
};

int main() {
    Estudiante e1;

    e1.setNombre("Ana");
    e1.setEdad(25);

    e1.mostrarDatos();

    return 0;
}
```


**Constructor:**
Es un método especial que se ejecuta automáticamente al crear un objeto.
``` c++
class Persona {
private:
    string nombre;

public:
    Persona(string n) {
        nombre = n;
    }

    void mostrar() {
        cout << nombre;
    }
};

// uso
Persona p1("Ana");
p1.mostrar();
```


**Ejemplo:**
``` c++

```

**Ejemplo:**
``` c++

```
# Memoria Dinámica

## Memoria RAM

La **RAM** es la memoria principal donde se guardan temporalmente los datos de los programas que están en ejecución.

### Ideas clave

* Es rápida.
* Es temporal.
* Al apagar o cerrar el programa, los datos normalmente se pierden.
* Guarda variables, datos temporales, objetos y estructuras mientras el programa corre.

### Ejemplo
```cpp
int edad = 50;
string nombre = "Ana";
```
Estas variables existen en RAM mientras el programa se ejecuta.

## Memoria dinámica
La **memoria dinámica** permite pedir memoria mientras el programa está funcionando.
Se usa cuando no sabemos desde el inicio cuántos datos vamos a necesitar.

### Sirve para crear
* Listas
* Pilas
* Colas
* Árboles
* Arreglos dinámicos
* Nodos

### Ejemplo
```cpp
int* numero = new int;

*numero = 25;

cout << *numero;

delete numero;
numero = nullptr;
```

### Idea clave
Todo lo que se crea con `new` debe liberarse con `delete`.

## Valor vs dirección de memoria
Una variable tiene:

| Elemento  | Significado                             |
| --------- | --------------------------------------- |
| Valor     | El dato que guarda                      |
| Dirección | El lugar en memoria donde está guardada |

### Ejemplo
```cpp
int x = 10;

cout << x;   // Muestra el valor
cout << &x;  // Muestra la dirección
```

## Punteros
Un **puntero** es una variable que guarda una dirección de memoria.

### Ejemplo
```cpp
int x = 10;
int* ptr = &x;
```
Aquí `ptr` guarda la dirección de `x`.

```text
x = 10
ptr ─────► x
```
El puntero no guarda directamente el valor, guarda la dirección donde está el valor.

## Operador `&`
Obtiene la dirección de memoria de una variable.

### Ejemplo
```cpp
int y = 5;
int* yPtr = &y;
```
Esto significa que `yPtr` apunta a `y`.

## Operador `*`
Tiene dos usos principales.

### Al declarar un puntero
```cpp
int* ptr;
```
Significa que `ptr` es un puntero a entero.

### 6.2. Al usar un puntero
```cpp
*ptr = 20;
```
Significa que se entra a la dirección a la que apunta `ptr` y se modifica el valor.

### Ejemplo
```cpp
int x = 10;
int* ptr = &x;
*ptr = 20;
cout << x;
```
Salida:
```text
20
```
Porque `ptr` apunta a `x`.

## `nullptr`

Es recomendable inicializar punteros con `nullptr`.

### Ejemplo
```cpp
int* ptr = nullptr;
```
Esto significa que el puntero no apunta a ninguna dirección válida todavía y evita que el puntero tenga una dirección basura.

## `new`
`new` sirve para pedir memoria dinámica.

### Ejemplo
```cpp
int* ptr = new int;
```
Esto reserva memoria para guardar un entero. Luego se puede asignar un valor:
```cpp
*ptr = 100;
```

## `delete`
`delete` libera memoria que fue creada con `new`.

### Ejemplo
```cpp
int* ptr = new int;

*ptr = 50;

delete ptr;
ptr = nullptr;
```

### Regla importante
| Si se crea con | Se libera con |
| -------------- | ------------- |
| `new int`      | `delete`      |
| `new int[5]`   | `delete[]`    |

## Error común con `delete`

No se debe usar `delete` si la memoria no fue creada con `new`.

### Ejemplo

```cpp
int variable;
int* ptr = &variable;

delete ptr;
```
Está mal porque `variable` es una variable normal.

### Correcto
```cpp
int* ptr = new int;

delete ptr;
ptr = nullptr;
```

## Punteros y arreglos
El nombre de un arreglo representa la dirección del primer elemento.

### Ejemplo
```cpp
int X[5] = {10, 20, 30, 40, 50};

int* ptrX = X;
```

Esto es equivalente a:

```cpp
int* ptrX = &X[0];
```

### Ejemplo de acceso

```cpp
cout << *ptrX;
```

Salida:

```text
10
```

## Aritmética de punteros
La aritmética de punteros permite moverse entre elementos de un arreglo.
### Ejemplo

```cpp
int X[5] = {10, 20, 30, 40, 50};
int* ptr = X;

cout << *ptr;       // 10
cout << *(ptr + 1); // 20
cout << *(ptr + 2); // 30
```
### Importante

```cpp
ptr + 1
```

no significa sumar 1 byte.

Significa avanzar una posición del tipo de dato al que apunta.

## Paréntesis en punteros

No es lo mismo:
```cpp
*(ptr + 1)
```
que:
```cpp
*ptr + 1
```

### Diferencia

| Expresión    | Significado                                  |
| ------------ | -------------------------------------------- |
| `*(ptr + 1)` | Avanza al siguiente elemento y toma su valor |
| `*ptr + 1`   | Toma el valor actual y le suma 1             |

### Ejemplo
```cpp
int X[3] = {10, 20, 30};
int* ptr = X;

cout << *(ptr + 1); // 20
cout << *ptr + 1;   // 11
```

## Referencias
Una referencia es otro nombre para una misma variable.

### Ejemplo
```cpp
int i = 17;
int& r = i;
```

Aquí `r` e `i` representan la misma variable.

### Ejemplo

```cpp
int i = 17;
int& r = i;

r = 25;

cout << i;
```

Salida:

```text
25
```
## `sizeof`

`sizeof` permite saber cuántos bytes ocupa algo en memoria.

### Ejemplo

```cpp
cout << sizeof(int);
cout << sizeof(double);
cout << sizeof(char);
```

Una salida común puede ser:

```text
4
8
1
```

Esto puede variar según el sistema.

## `sizeof` con arreglos

### Ejemplo

```cpp
int a[10];

cout << sizeof(a);
```

Si cada `int` ocupa 4 bytes:

```text
10 * 4 = 40 bytes
```

### Para saber cuántos elementos tiene

```cpp
int cantidad = sizeof(a) / sizeof(a[0]);
```

# Partes de la memoria de un programa

Cuando un programa se ejecuta, su memoria se divide en partes.

```text
Direcciones altas
┌─────────────────────────────┐
│ STACK                       │
│ Variables locales           │
│ Parámetros                  │
│ Llamadas a funciones        │
└──────────────↓──────────────┘

              Espacio libre

┌──────────────↑──────────────┐
│ HEAP                        │
│ Memoria dinámica            │
│ new / delete                │
└─────────────────────────────┘

┌─────────────────────────────┐
│ .bss                        │
│ Globales no inicializadas   │
└─────────────────────────────┘

┌─────────────────────────────┐
│ .data                       │
│ Globales inicializadas      │
└─────────────────────────────┘

┌─────────────────────────────┐
│ .text                       │
│ Código del programa         │
└─────────────────────────────┘
Direcciones bajas
```

---

## Segmento `.text`

Guarda el código del programa.

### Ejemplo

```cpp
int main() {
    cout << "Hola";
    return 0;
}
```

Las instrucciones compiladas se guardan en `.text`.

### Características

* Tamaño fijo.
* Solo lectura.
* Contiene el código máquina del programa.

---

## Segmento `.data`

Guarda variables globales inicializadas.

### Ejemplo

```cpp
int contador = 10;

int main() {
    cout << contador;
}
```

La variable `contador` está en `.data` porque es global y tiene valor inicial.

## Segmento `.bss`

Guarda variables globales no inicializadas.

### Ejemplo

```cpp
int contador;

int main() {
    cout << contador;
}
```

La variable `contador` está en `.bss` porque es global y no tiene valor inicial explícito.

Normalmente queda inicializada en `0`.

---

## Stack

El **stack** guarda variables locales, parámetros y llamadas a funciones.

### Ejemplo

```cpp
void saludar() {
    int edad = 20;
    cout << edad;
}
```

La variable `edad` vive en el stack porque es local.

Cuando termina la función, desaparece automáticamente.

## Heap

El **heap** guarda memoria dinámica creada con `new`.

### Ejemplo

```cpp
int* ptr = new int;

*ptr = 25;

delete ptr;
ptr = nullptr;
```

Aquí:

```cpp
int* ptr
```

vive en el stack.

Pero:

```cpp
new int
```

crea el dato en el heap.

### Visualmente

```text
STACK
┌─────────────┐
│ ptr         │ ─────► apunta al dato dinámico
└─────────────┘

HEAP
┌─────────────┐
│ 25          │
└─────────────┘
```

---

## 24. Stack vs Heap

| Stack                            | Heap                   |
| -------------------------------- | ---------------------- |
| Automático                       | Manual                 |
| Variables locales                | Memoria dinámica       |
| Se libera al salir de la función | Se libera con `delete` |
| Más rápido                       | Más flexible           |
| Tamaño más limitado              | Puede usar más memoria |

---

## Ejemplo completo con partes de memoria

```cpp
#include <iostream>
using namespace std;

int globalInicializada = 10; // .data
int globalNoInicializada;    // .bss

void ejemplo(int parametro) {
    int local = 5;            // stack

    int* dinamico = new int;  // puntero en stack, dato en heap
    *dinamico = 100;

    cout << *dinamico;

    delete dinamico;
    dinamico = nullptr;
}

int main() {
    ejemplo(20);
    return 0;
}
```

### Ubicación de cada elemento

| Elemento                     | Parte de memoria |
| ---------------------------- | ---------------- |
| Código del programa          | `.text`          |
| `globalInicializada`         | `.data`          |
| `globalNoInicializada`       | `.bss`           |
| `parametro`                  | Stack            |
| `local`                      | Stack            |
| `dinamico` como puntero      | Stack            |
| Memoria creada con `new int` | Heap             |

---

## Paso por referencia con punteros

Permite modificar una variable original desde una función.

### Ejemplo

```cpp
void sumoElDoble(int* ptrX) {
    *ptrX = *ptrX + (*ptrX * 2);
}

int main() {
    int X = 15;

    sumoElDoble(&X);

    cout << X;

    return 0;
}
```

Salida:

```text
45
```

Porque se envía la dirección de `X`.

---

## Paso por referencia con referencias

También permite modificar la variable original.

### Ejemplo

```cpp
void sumoElDoble(int& X) {
    X = X + (X * 2);
}

int main() {
    int X = 15;

    sumoElDoble(X);

    cout << X;

    return 0;
}
```

Salida:

```text
45
```

---

## Estructuras autoreferenciadas

Una estructura autoreferenciada tiene un puntero a otra estructura del mismo tipo.

### Ejemplo

```cpp
struct Nodo {
    int dato;
    Nodo* siguiente;
};
```

Aquí:

```cpp
Nodo* siguiente;
```

permite conectar un nodo con otro.

### Visualmente

```text
[10 | siguiente] ───► [20 | siguiente] ───► [30 | nullptr]
```

Se usan para:

* Listas
* Pilas
* Colas
* Árboles

---

## Operador punto `.`

Se usa cuando tengo el objeto directamente.

### Ejemplo

```cpp
Nodo n;

n.dato = 10;
```

Aquí se usa punto porque `n` es un objeto normal.

---

## Operador flecha `->`

Se usa cuando tengo un puntero a un objeto o estructura.

### Ejemplo

```cpp
Nodo* ptr = new Nodo;

ptr->dato = 10;

delete ptr;
ptr = nullptr;
```

Esto:

```cpp
ptr->dato
```

es equivalente a:

```cpp
(*ptr).dato
```

---

## Diferencia entre `.` y `->`

| Situación        | Operador | Ejemplo     |
| ---------------- | -------- | ----------- |
| Tengo el objeto  | `.`      | `n.dato`    |
| Tengo un puntero | `->`     | `ptr->dato` |

---

## 32. Puntero `this`

El puntero `this` apunta al objeto actual dentro de una clase.

### Ejemplo

```cpp
class MyClass {
    int x;

public:
    void setX(int x) {
        this->x = x;
    }
};
```

Aquí:

```cpp
this->x
```

se refiere al atributo `x` del objeto.

Y:

```cpp
x
```

se refiere al parámetro recibido.

---

## ¿Para qué sirve `this`?

Sirve para:

* Diferenciar atributos y parámetros con el mismo nombre.
* Referirse al objeto actual.
* Retornar el objeto actual.
* Encadenar métodos.

---

## 34. Relación con pila dinámica

En una pila dinámica se usan nodos enlazados.

### Ejemplo

```cpp
struct Texto {
    string linea;
    Texto* siguienteL;
};
```

Cada nodo tiene:

| Miembro      | Función                      |
| ------------ | ---------------------------- |
| `linea`      | Guarda una línea del archivo |
| `siguienteL` | Apunta al siguiente nodo     |

---

## 35. `push` en pila dinámica

```cpp
void push(Texto*& top, string linea) {
    Texto* nuevo = new Texto;

    nuevo->linea = linea;
    nuevo->siguienteL = top;

    top = nuevo;
}
```

### Explicación rápida

| Línea                       | Qué hace                                  |
| --------------------------- | ----------------------------------------- |
| `Texto* nuevo = new Texto;` | Crea un nodo en el heap                   |
| `nuevo->linea = linea;`     | Guarda la línea                           |
| `nuevo->siguienteL = top;`  | Enlaza el nuevo nodo con la pila anterior |
| `top = nuevo;`              | El nuevo nodo pasa a ser la cima          |

---

## `pop` en pila dinámica

```cpp
string pop(Texto*& top) {
    if (top == nullptr) {
        return "";
    }

    string info;
    Texto* temp;

    temp = top;
    info = temp->linea;
    top = temp->siguienteL;

    delete temp;

    return info;
}
```

### Explicación rápida

| Línea                     | Qué hace                              |
| ------------------------- | ------------------------------------- |
| `if (top == nullptr)`     | Verifica si la pila está vacía        |
| `temp = top;`             | Guarda el nodo que saldrá             |
| `info = temp->linea;`     | Guarda la información antes de borrar |
| `top = temp->siguienteL;` | Mueve la cima al siguiente nodo       |
| `delete temp;`            | Libera memoria                        |
| `return info;`            | Devuelve la línea extraída            |

---

## ¿Por qué la pila invierte el orden?

La pila funciona con el principio:

```text
LIFO = Last In, First Out
```

Significa:

```text
El último en entrar es el primero en salir.
```

Si el archivo tiene:

```text
Línea 1
Línea 2
Línea 3
```

La pila queda:

```text
top -> Línea 3 -> Línea 2 -> Línea 1 -> nullptr
```

Al hacer `pop`, sale:

```text
Línea 3
Línea 2
Línea 1
```

Por eso sirve para revertir un archivo
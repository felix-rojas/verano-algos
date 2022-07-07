# Apuntadores

- [Apuntadores](#apuntadores)
  - [Declaración en cpp](#declaración-en-cpp)
  - [Operaciones](#operaciones)
    - [Indirección](#indirección)
    - [Dirección](#dirección)
  - [Aplicaciones](#aplicaciones)
    - [Modularidad](#modularidad)
    - [Manejo de memoria dinámica](#manejo-de-memoria-dinámica)
      - [Memoria estática](#memoria-estática)
      - [Memoria dinámica](#memoria-dinámica)
        - [Operador new](#operador-new)
        - [Operador delete](#operador-delete)

Recuerda que todos los apuntadores son localidaddes en memoria.
Puedes apuntar a cualquier tipo, incluso objetos personalizados.
Nunca olvides que los apuntadores siempre se regresan en hexadecimal.

## Declaración en cpp

`tipo *nombre_apuntador`

```cpp
int *p;
char c, *s;
```

## Operaciones

### Indirección

`*variable_apuntador`

Hace referencia al contenido que apunta el operador

### Dirección

`&variable_apuntador`

Genera la dirección de la variable.

```cpp
void intercambia(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
```

## Aplicaciones

### Modularidad

Al intercambiar valores nos garantiza la integridad de los datos, pues no los pasa por valor. Al pasar por valor, generamos una copia del dato y no alteramos el dato original.

Es también conveniente pues no necesitas generar múltiples variables y disminuye el tamaño utilizado en RAM.

### Manejo de memoria dinámica

#### Memoria estática

Cuando declaramos variables como apuntadores con métodos como new o apuntadores necesitamos estar al pendiente de las variables declaradas.

Recuerda que la memoria estática se define de manera explícia

#### Memoria dinámica

Se crea y se destruye cuando se indica por el programador en todo momento

Las variables y objetos creados de manera dinámica se almacenan en un heap, administrado por el OS. Esto hace que el programa utilice mucho menos la memoria de ejecución.

Utilizaremos los operadores:

- `new`
- `delete`

##### Operador new

```cpp
apuntador = new tipo_de_dato
```

Regresa la dirección del espacio de memoria que se acaba de crear. Si no hubiera espacio, regresará el valor NULL.

Lo que hace: Asigna memoria, le asigna la localidad de memoria al apuntador.

##### Operador delete

```cpp
delete apuntador;
apuntador = nullptr;
```

Libera el espacio en memoria, pero debemos asignar al apuntador con nullptr para mostrar que no apunta a nada, pues de otra manera arroja un valor diferente al de memoria.

```cpp
// declaramos un entero y un apuntador a entero
int a = 1, *p;

// se genera una nueva localidad y se le da la direccion de ese espacio
p = new int;

// el contenido en el apuntador p ahora es igual al contenido de a
*p = a;

// le asignamos el valor de p + 2 a a, en este caso 3
a = *p + 2;

// imprime 1 3
cout << a << " " << *p;

// liberamos ese espacio de memoria
delete p;
```

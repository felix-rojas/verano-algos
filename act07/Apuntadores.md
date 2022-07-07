# Apuntadores

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

*variable_apuntador

Hace referencia al contenido que apunta el operador

### Dirección

&variable_apuntador

Genera la dirección de la variable.

```cpp
void intercambia(int &a, int&) {
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
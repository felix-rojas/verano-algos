# Actividad 1.3

> Félix Javier Rojas Gallardo
> A01201946

## Algoritmos utilizados

### Mergesort

- Complejidad espacial de O(n)
- Complejidad temporal O(n log n)

Utilizamos mergesort pues era más rápido para todos los casos, a menos que utilizáramos una versión optimizada de quicksort.

Dado que es una operación que se realiza *una sola vez* el problema de haber utilizado mergesort es el espacio que ocupa. El problema es que se tienen que estar alocando en memoria y desalocando, lo que hace que pueda correr más lento, especialmente con set de datos más grandes.

Quicksort tendría un mejor rendimiento para bitácoras de mayor tamaño, especialmente por la complejidad espacial que es sólo de O(1).

### Búsqueda binaria

- Complejidad espacial de O(1)
  - Cuando es iterativo
- Complejidad temporal O( log n)

La búsqueda binaria es perfecta para este caso, dado que los datos a buscar ya están organizados y sólo se necesita encontrar un rango de datos.

En el código utilizamos una versión diferente que imprime el resultado de los registros desde la variable ``inicio``, comparando hasta que sea menor o igual a la variable `fin`

Entonces en complejidad temporal cambia de O( log n) a O (n log n) pues el pero caso sería que el rango establecido abarcara **todos** los registros.

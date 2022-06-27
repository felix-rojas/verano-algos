# Actividad 1 vectores

1. Crear una estructura de datos de una lista de enteros con el uso de vectores.
2. Crear una estructura de datos de una lista de enteros con el uso de vectores y templates (plantillas).

## Crea una clase llamada "Lista" que contenga lo siguiente

### Atributos

1.Un vector llamado data de tamaño MAX (MAX es una constante de valor 100) elementos de tipo entero.
2.Un entero llamado size que contenga la cantidad de datos utilizados y almacenados en el vector.

### Operaciones

- **insert** - Recibe el valor del número que se desea insertar; si hay espacio disponible, se coloca al final del vector y se incrementa en 1 size.
- **erase** - En caso de que el vector no esté vacío, despliega el último elemento del vector (el que está en la posición size-1) y disminuye en 1 el tamaño de size. En caso de que el vector esté vacío, despliega el mensaje: “NO HAY ELEMENTOS”.
- **getData** – Recibe la posición de donde se desea obtener la información, y regresa el contenido del vector en esa posición. La precondición es que la posición sea un valor existente dentro de los datos (0 <= pos < size).
- **getSize** – Regresa el valor del atributo size.
- **print** - Imprime la lista de datos, uno por línea con el siguiente formato:

´<pos> - <dato>´

Ejemplo:
[0] – 154
[1] – 587
[2] – 874

Ahora actualiza por tu cuenta la clase del punto anterior (iguales atributos y operaciones) para que utilice templates (plantillas) y sea capaz de manejar otros tipos de datos distintos a los enteros, nombrala *ListaTemplate*

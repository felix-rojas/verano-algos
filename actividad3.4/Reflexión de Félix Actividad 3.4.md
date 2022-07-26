# Reflexión de Félix Actividad 3.4

> Félix Javier Rojas Gallardo </br>
> A01201946

## Transformando IP's a numéricos

Utilizando este criterio decidimos procesar las IP's de manera numérica, procesamos la IP por cada parte de la string y lo multiplicamos por su base y potencia respectiva por octeto. Este ciclo corre 4 veces y realiza operaciones de asignación por lo que es O(4).

## maxHeap

El maxHeap es una implementación de estructura de datos ideal para la situación solicitada:
> "Despliega los dato en forma descendente por cantidad de accesos."

Si queremos conocer las IP's más sospechosas, debemos entonces obtener las que más se repiten frecuentemente. Utilizando un maxHeap podemos observar las IP's que se llaman un número anómalo de veces y se ponen al tope de nuestro Heap.

## HeapSort

Para poder realizar el heapSort, debemos primero llamar al vector a ordenar, convertirlo en un maxHeap. Al final el elemento con mayor repeticiones queda hasta arriba.

Entonces se llama heapify() n-1 veces, por lo que ordenar con el Heapsort tenemos una complejidad O(n log n) que es muy rápida y para las consultas de los elementos más grandes es todavía mejor.

Mucho mejor aún es que la complejidad espacial es O(1) pues es *in-place*. Esto hace que no necesitemos alocar más memoria mientras ordenamos los datos.
# Instrucciones 4.3

> Felix Javier Rojas Gallardo</br>
> A01201946

1. Abre el archivo de entrada `("bitacoraGrafos.txt Descargar bitacoraGrafos.txt ")` léelo y almacena los datos en en una lista de adyacencias organizada por la dirección IP de origen.
2. Determina el grado de salida de cada nodo del grafo (número de IPs adyacentes a cada IP de origen) y almacena en un archivo llamado `"grados_ips.txt"` una lista con los pares (IP, grado de salida).
3. Determina las 5 IPs con mayor grado de salida y almacena una lista con los pares (IP, grado de salida) en un archivo llamado `"mayores_grados_ips.txt"`, ordenados de forma descendente.
4. Utiliza la clase Heap que implementaste anteriormente para encontrar cuáles fueron las 5 IPs con más IPs adyacentes (nodos con mayor grado de salida).
5. ¿En qué dirección IP presumiblemente se encuentra el boot master? Imprima en pantalla su respuesta.
6. Encuentre el camino más corto entre la IP que identificó como el boot master y el resto de los nodos (IPs) del grafo. Almacene en un archivo llamado "distancia_bootmaster.txt" una lista con los pares (IP, distancia), donde distancia representa la distancia total del camino más corto entre el boot master y cada IP.
7. ¿Cuál es la dirección IP que presumiblemente requiere más esfuerzo para que el boot master la ataque? Imprima en pantalla su respuesta.

# Actividad 1.1

>Alexia Castillo Diaz

>Félix Javier Rojas Gallardo

>Santiago Vargas Ochoa

## Encabezado y compilación

Estas son librerías necesarias para que corra el programa.

```c++
#include <iostream>
#include <stdio.h>
#include <vector>
```

Si lo desean ejecutar localmente o en replit, en el shell escriben esas dos lineas. Es compilación estándar sin optimizaciones.

```bash
g++ main.cpp -o a
./a
```

### Compilación local

Si desean compilarlo localmente, les recomiendo que instalen las librerías de C++ desde MinGW (pequeño y eficiente) o usando WSL e instalando los compiladores necesarios ahí.

También pueden descargar los paquetes de Visual Studio 2019 en adelante que traen compiladores nativos para Windows.

## Sobre las pruebas
El programa ejecuta por sí mismo las pruebas requeridas en las instrucciones para cada proceso.
Básicamente definimos las 4 funciones antes del main y al llamar en main hacemos una ineficiente llamada de fibonacci recursivo. 

## Posibles mejoras
El método para los procesos iterativos podría mejorarse, aunque la diferencia sería en ahorro de memoria, pues las otras ejecuciones son en tiempo constante.
Una declaración con structs podría hacer a los métodos recursivos utilizar menos memoria utilizando programación dinámica pero no estoy seguro si es del alcance del semestre.

# Double linked list

Las listas doblemente ligadas son muy similares a las simples ligadas

Cada nodo posee dos apuntadores:

- El nodo cabeza apunta a nulo en su *prev* y al siguiente nodo en su *next*
- El nodo cola apunta a nulo en su *next* y al nodo previo en su *prev*

## Inserción

1. Crea nodo vtx y asignamos valor
2. El *next* de vtx apunta a head
3. Si el head no es nullptr, su previo ahora apunta a al nuevo nodo vtx
4. Asignamos el valor de vtx a head


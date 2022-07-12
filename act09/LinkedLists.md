# Estucturas de datos

## Listas encadenadas

Las listas encadenadas consisten en múltiples nodos conectados.

Todos los apuntadores almacenan un dato y la localidad de memoria del siguiente nodo.

El primer nodo es el "head", no tiene datos

El último nodo es el "tail" y tampoco tiene datos

### Clase Nodo

La clase nodo para esta linked list posee un almacén de datos y un almacén de localidad en memoria

### Clase LinkedList


```cpp
class LinkedList{
    Node *head, *tail; // declares it as protected
    private int size;
    public: 
        LinkedList() {
            head, tail = NULL;
            size = 0;
    }
        
        addFirst(auto a){
        
    }
        addLast(auto a){
    }
}
```

Este código genera una lista encadenada vacía con su única variable "head".

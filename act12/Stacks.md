# Stacks (Pilas)

Estructura de datos lineal

Sigue el principio Last Input First Output **LIFO**

El útlimo en entrar es el primero en salir; de modo que entre más pongas en el tope de la pila, será utilizado más pronto.

Tenemos 2 operaciones básicas al meter y sacar.

## Nivel lógico 

### Elementos

El tipo de elemento depende de la aplicación

### Estructura

De tipo Linear

### Dominio

## Operaciones básicas del stack

- push
- pop
- top
- isFull
- isEmpty

## Implementaciones

- Arreglos
- Listas ligadas

### Arreglos

class Stack{
    private:
        int datos [MAX];
        int tope;
    public:
        Stack();
        void push (int Valor);
        int top();
        void pop();
        bool isEmpty;
        bool isFull;
}

Top consulta el índice del último elemento

// tope se preinizializa como -1
public Stack() {tope = -1};

// esta lleno
public boolean isFull() {return (tope == MAX-1)}

// esta vacio
public boolean isFull() {return (tope == -1)}

public void push (int valor){
    tope++;
    datos[tope] = valor;
}

public void pop (){
    int v = datos[tope];
    tope--;
}

public void top (){
    return datos[tope];
}

Las casillas se sobreescriben conforme se usan.

#### Complejidad temporal

Todas sus operaciones son *constantes* O(1)

### Listas ligadas

Sólo nos interesa el head de nuestra lista ligada 

Utilizando el addFirst de la lista ligada nos permite meter a la pila en la lista ligada. Esto ahora sería el push mencionado antes


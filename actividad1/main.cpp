#include <stdio.h>

// Calcule la sumatoria de 1 hasta n con un método iterativo
unsigned int sumaIterativa(uint &n)
{
    unsigned int accum = 0;
    while (n != 0)
    {
        accum += n;
        n--;
    }
    return accum;
}

// Calcule la sumatoria de 1 hasta n con un método recursivo
unsigned int sumaRecursiva(uint n)
{
    if (n = 1){
        return 1;
    }
    return n + sumaRecursiva(n-1);
}

// Calcule el n-ésimo numero fibonacci con un método iterativo
unsigned int fibonacciIterativo(uint n)
{
}

// Calcule el n-ésimo numero fibonacci con un método recursivo
unsigned int fibonacciRecursivo(uint n)
{
}

int main
{
    std::cout<<sumaIterativa(10)<<std::endl;
    std::cout<<sumaIterativa(20)<<std::endl;
    return 0;
}
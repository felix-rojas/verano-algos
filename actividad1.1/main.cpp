#include <iostream>
#include <stdio.h>
#include <vector>

/*
Integrantes equipo 10:
>Alexia Castillo Diaz
>Félix Javier Rojas Gallardo
>Santiago Vargas Ochoa

    Compilation:
        g++ main.cpp -o a
    Run:
        ./a
*/

// Calcule la sumatoria de 1 hasta n con un método iterativo
// O(n) lineal pues es un único ciclo que depende de la variable
// control n que disminuye constantemente
int sumaIterativa(int n)
{
    int accum = 0;
    while (n != 0)
    {
        accum += n;
        n--;
    }
    return accum;
}

// Calcule la sumatoria de 1 hasta n con un método recursivo
// el caso big O es en el caso que el if no se cumple
// la funcion recursiva se llama n veces
// esto nos indica tiempo linear O(n)
int sumaRecursiva(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sumaRecursiva(n - 1);
}

// Enliste hasta el n-ésimo numero fibonacci con un método iterativo
// O(n) dada que nuestra variable control ejecuta 2 operaciones
// que se consideran constantes
// la mayor complejidad está en el ciclo while y podemos asumir
// O(n) donde n es el tamaño del input
std::vector<int> fibonacciIterativo(int n)
{
    std::vector<int> fibo;
    int a = 1;
    int b = 1;
    fibo.push_back(a);
    fibo.push_back(b);
    while (n > fibo.size())
    {
        fibo.push_back(a += b);
        fibo.push_back(b += a);
    }
    if (n % 2 != 0)
    {
        fibo.pop_back();
    }
    return fibo;
}

// Enliste hasta el n-ésimo numero fibonacci con un método recursivo
// El recursivo genera un árbol binario en cada iteración
// entonces la complejidad Big O será 2^n
int fibonacciRecursivo(int n)
{
    if (n <= 1)
    // base case is 1 to avoid more looping
    // also we assume n <= 1 because both f(1) and f(2) are one
    // we skip f(0) altogether to avoid infinite recursion 
    { 
        return 1;
    }
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
    // This code is contributed
    // by Akanksha Rai
    // in https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
}

int main()
{
    // Suma Iterativa
    std::cout << "sumaIterativa()" << std::endl;
    std::cout << "1. " << sumaIterativa(20) << std::endl;
    std::cout << "2. " << sumaIterativa(50) << std::endl;
    std::cout << "3. " << sumaIterativa(100) << std::endl;
    std::cout << "4. " << sumaIterativa(1000) << std::endl;
    std::cout << std::endl;

    // Suma Recursiva
    std::cout << "sumaRecursiva()" << std::endl;
    std::cout << "1. " << sumaRecursiva(20) << std::endl;
    std::cout << "2. " << sumaRecursiva(50) << std::endl;
    std::cout << "3. " << sumaRecursiva(100) << std::endl;
    std::cout << "4. " << sumaRecursiva(1000) << std::endl;
    std::cout << std::endl;

    // Fibonacci Iterativo
    std::cout << "fibonacciIterativo()" << std::endl;
    std::vector<int> f1, f2, f3, f4;
    f1 = fibonacciIterativo(5);
    f2 = fibonacciIterativo(10);
    f3 = fibonacciIterativo(15);
    f4 = fibonacciIterativo(30);

    for (int i = 0; i < f1.size(); ++i)
        std::cout << f1[i] << ' ';
    std::cout << std::endl;

    for (int i = 0; i < f2.size(); ++i)
        std::cout << f2[i] << ' ';
    std::cout << std::endl;

    for (int i = 0; i < f3.size(); ++i)
        std::cout << f3[i] << ' ';
    std::cout << std::endl;

    for (int i = 0; i < f4.size(); ++i)
        std::cout << f4[i] << ' ';
    std::cout << std::endl;
    std::cout << std::endl;

    // Fibonacci Recursivo
    std::cout << "fibonacciRecursivo()" << std::endl;
    int n = 1;
    while (n <= 5)
    {
        std::cout << fibonacciRecursivo(n - 1) << ' ';
        n++;
    }
    std::cout << std::endl;

    int n1 = 1;
    while (n1 <= 10)
    {
        std::cout << fibonacciRecursivo(n1 - 1) << ' ';
        n1++;
    }
    std::cout << std::endl;

    int n2 = 1;
    while (n2 <= 15)
    {
        std::cout << fibonacciRecursivo(n2 - 1) << ' ';
        n2++;
    }
    std::cout << std::endl;

    int n3 = 1;
    while (n3 <= 30)
    {
        std::cout << fibonacciRecursivo(n3 - 1) << ' ';
        n3++;
    }
    std::cout << std::endl;

    return 0;
}
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>

/*
    compilation:
        g++ main.cpp -o a
    run:
        ./a
*/

// Calcule la sumatoria de 1 hasta n con un método iterativo
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
int sumaRecursiva(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sumaRecursiva(n - 1);
}

// TODO
// Calcule el n-ésimo numero fibonacci con un método iterativo
std::vector<int> fibonacciIterativo(int n)
{
    std::vector<int> fibo;
    long a = 1;
    long b = 1;
    fibo.push_back(a);
    fibo.push_back(b);
    while (n > fibo.size())
    {
        fibo.push_back(a+=b);
        fibo.push_back(b+=a);
    }
    if (n%2!=0){
        fibo.pop_back();
    }
    return fibo;
}

// TODO
// Calcule el n-ésimo numero fibonacci con un método recursivo
int fibonacciRecursivo(long int n)
{
    return n;
}

int main()
{
    // Suma Iterativa
    std::cout << "sumaIterativa()" << std::endl;
    std::cout << "1. " << sumaIterativa(20) << std::endl;
    std::cout << "2. " << sumaIterativa(50) << std::endl;
    std::cout << "3. " << sumaIterativa(100) << std::endl;
    std::cout << "4. " << sumaIterativa(1000) << std::endl;
    std::cout <<  std::endl;

    // Suma Recursiva
    std::cout << "sumaRecursiva()" << std::endl;
    std::cout << "1. " << sumaRecursiva(20) << std::endl;
    std::cout << "2. " << sumaRecursiva(50) << std::endl;
    std::cout << "3. " << sumaRecursiva(100) << std::endl;
    std::cout << "4. " << sumaRecursiva(1000) << std::endl;
    std::cout <<  std::endl;

    // Fibonacci Iterativo
    std::vector<int> f1,f2,f3,f4,f5; 
    f1 = fibonacciIterativo(5);
    f2 = fibonacciIterativo(10);
    f3 = fibonacciIterativo(15);
    f4 = fibonacciIterativo(20);
    
    for (int i=0; i<f1.size(); ++i)
    std::cout << f1[i] << ' ';
    std::cout << std::endl;
    
    for (int i=0; i<f2.size(); ++i)
    std::cout << f2[i] << ' ';
    std::cout << std::endl;
    
    for (int i=0; i<f3.size(); ++i)
    std::cout << f3[i] << ' ';
    std::cout << std::endl;
    
    for (int i=0; i<f4.size(); ++i)
    std::cout << f4[i] << ' ';
    std::cout << std::endl;

    // Fibonacci Recursivo
    return 0;
}
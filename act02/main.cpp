# include <stdio.h>
# include <iostream>
# include <vector>

unsigned int factorialRecursivo(unsigned int n){
    if(n <= 1){
        return 1;
    }
    return n * factorialRecursivo(n-1);
}
unsigned int factorialIterativo(unsigned int n){
    int count = n;
    for (int i = 2; i < count; i++)
    {
        n*=i;
    }
    return n;
}
size_t potencialRecursivo(size_t n, unsigned int m){
    if (m == 1){
        return n;
    }
    return n*potencialRecursivo(n,m-1);
}

size_t potencialIterativo(unsigned int n, unsigned int m){
    size_t num = n;
    for (int i = 1; i < m; i++){
        num = num * n;
    }
    return num;
}

int main()
{
    std::cout << potencialIterativo(12,15) << std::endl;
    std::cout << potencialRecursivo(12,15) << std::endl;
    std::cout << factorialIterativo(8) << std::endl;
    std::cout << factorialRecursivo(8) << std::endl;

    return 0;
}

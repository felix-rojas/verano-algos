/*
 * Compilacion para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 * Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./main
 *
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
*/

# include "openHash.h"
int main()
{
    // array that contains keys to be mapped
        int a[] = {15, 11, 27, 8, 12, 23, 26, 17, 8, 12, 23, 26, 178, 12, 23, 26, 17};
    int n = sizeof(a) / sizeof(a[0]);

    // insert the keys into the hash table
    Hash<int, int> h(31); // 31 is a prime that determines number of buckets

    for (int i = 0; i < n; i++)
        h.add(a[i]);
    
    std::cout << std::endl;
    std::cout << "After adding elements: " << std::endl;
    std::cout << std::endl;// 
    h.print();

    std::cout << std::endl;
    std::cout << "delete {12} 2 times from hash table: " << std::endl;
    std::cout << std::endl;// 
    h.remove(12);
    h.remove(12);
    h.print();
    // find 12 from hash table
    int test = h.find(12);
    std::cout << std::endl;
    std::cout << "Element found at: "<< test << std::endl;
    std::cout << std::endl;

    
    // find 178 from hash table
    int test3 = h.find(178);
    std::cout << std::endl;
    std::cout << "Element found at: "<< test3 << std::endl;
    std::cout << std::endl;

    // find value that doesnt exist in hash table
    std::cout << std::endl;
    int test2 = h.find(12345);
    std::cout << "Element found at: "<< test2 << std::endl;
    std::cout << std::endl;
    // display the Hash table
    h.print();

    return 0;
}
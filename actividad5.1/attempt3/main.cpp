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
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a) / sizeof(a[0]);

    // insert the keys into the hash table
    Hash<int, int> h(7); // 7 is count of buckets in
               // hash table
    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);

    // delete 12 from hash table
    h.remove(12);

    // display the Hash table
    h.print();

    return 0;
}
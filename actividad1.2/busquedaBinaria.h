/*busquedaBinaria.h*/
#ifndef busquedaBinaria_H
#define busquedaBinaria_H

using std::vector;

// busquedaBinaria
int busquedaBinaria(vector<int> vectorSorted, int key, int &compara)
{
    int low = 0;
    int high = vectorSorted.size() - 1;
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        compara++;
        if (key == vectorSorted[mid])
            return mid;
        else if (key < vectorSorted[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}


#endif // busquedaBinaria_H
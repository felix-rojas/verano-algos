#ifndef quickSort_H
#define quickSort_H

#include <iostream>
#include <vector>

using std::vector;

int partition(vector<int> &vector, int low, int high, int &compares){
    int pivot = vector[high];
    int i = low-1;
    int temp = 0;

    for (int j = low; j < high; j++)
    {
        if (vector[j] < pivot) {
            i+=1;
            temp = vector[i];
            vector[i] = vector[j];
            vector[j] = temp;
        }
    }
    
    temp = vector[i+1];
    vector[i+1] = vector[high];
    vector[high] = temp;
    return i+1;
}

void quickSort(vector<int> &vector, int low, int high, int &compares)
{
    if (low < high)
    {
        int pi = partition(vector<int> &vector, int low, int high, int &compares);
        quickSort(vector, low, mid, compares);
        quickSort(vector, mid + 1, high, compares);

    }
}

#endif /* quickSort_H */
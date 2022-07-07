#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <vector>

using std::vector;

/* PSEUDO CODE
if l < r then
*/
void merge(vector<int> &vector, int low, int mid, int high, int &compares)
{

    int i, j, k = 0;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++){L[i] = vector[low + i];}
    for (int i = 0; i < n2; i++){R[i] = vector[mid + 1 + i];}

    i, j = 0;
    k = low;

    while (i < n1 && j < n2)
    {
        compares++;
        if (L[i] < R[j])
        {
            vector[k] = L[i];
            i++;
        }
        else
        {
            vector[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        vector[k] = L[i];
        i++;
        k++;
    }
    while (i < n2)
    {
        vector[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &vector, int low, int high, int &compares)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(vector, low, mid, compares);
        mergeSort(vector, mid + 1, high, compares);

        merge(vector, low, mid, high, compares);
    }
}

#endif /* MERGESORT_H */
// ordenaMerge
#ifndef ordenaMerge_H
#define ordenaMerge_H

using std::vector;

// Merge Sort
// Complejidad temporal O(n log n)

void merge(vector<int> &vector, int low, int m, int high, int &compara)
{
    int i, j, k;
    int n1 = m - low + 1;
    int n2 = high - m;
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (i = 0; i < n1; i++)
        L[i] = vector[low + i];
    for (j = 0; j < n2; j++)
        R[j] = vector[m + 1 + j];
    i = j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        compara++;
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
    while (j < n2)
    {
        vector[k] = R[j];
        j++;
        k++;
    }
}

void ordenaMerge(vector<int> &vector, int low, int high, int &compara)
{

    if (low < high)
    {
        int m = (low + high) / 2;
        // Ordena recursivamente las dos mitades
        ordenaMerge(vector, low, m, compara);
        ordenaMerge(vector, m + 1, high, compara);
        // fusiona las dos mitades
        merge(vector, low, m, high, compara);
    }
}

#endif // ordenaMerge_H
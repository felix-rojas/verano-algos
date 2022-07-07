// ordenaQuick
#ifndef ordenaQuick_H
#define ordenaQuick_H

// O(n^2)

using std::vector;

// Agarra el elemento del final como pivote y lo mueve
int partir(vector<int> &vector, int low, int high, int &comparaciones, int &nSwaps)
{
    int pivot = vector[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        if (vector[j] < pivot)
        {
            i++;
            std::swap(vector[i], vector[j]);
            nSwaps++;
        }
        comparaciones++;
    }
    std::swap(vector[i + 1], vector[high]);
    nSwaps++;
    return (i + 1);
}

// Quicksort
void ordenaQuick(vector<int> &vector, int low, int high, int &comparaciones, int &nSwaps)
{
    if (low < high)
    {
        int p = partir(vector, low, high, comparaciones, nSwaps);
        ordenaQuick(vector, low, p - 1, comparaciones, nSwaps);
        ordenaQuick(vector, p + 1, high, comparaciones, nSwaps);
    }
}
#endif // ordenaQuick_H
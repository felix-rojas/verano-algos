// ordenaMerge
#ifndef ordenaMerge_H
#define ordenaMerge_H

using std::vector;

void merge(vector<int> &vector, int low, int mid, int high);
void ordenaMerge(vector<int> &vector, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - 1) / 2;
        ordenaMerge(vector, low, mid);
        ordenaMerge(vector, mid + 1, high);
        merge(vector, low, mid, high);
    }
}

void merge(vector<int> &vector, int low, int mid, int high)
{
    int k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = L[low + i];

    for (int j = 0; j < n2; j++)
        R[j] = R[mid + 1 + j];

    int i = 0;
    int j = 0;
    k = low;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
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

    // Copia elementos de L y luego de R
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

#endif // ordenaMerge_H
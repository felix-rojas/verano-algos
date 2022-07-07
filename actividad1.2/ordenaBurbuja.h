// ordenaBurbuja
#ifndef ordenaBurbuja_H
#define ordenaBurbuja_H

using std::vector;

// Bubble Sort
// Complejidad temporal O(n^2) 

void ordenaBurbuja(vector<int> &vector, int &compara, int &nSwaps)
{
  compara = nSwaps = 0;
  int size = vector.size();
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      compara++;
      if (vector[j] > vector[j + 1])
      {
        std::swap(vector[j], vector[j + 1]);
        nSwaps++;
      }
    }
  }
}
#endif //ordenaBurbuja_H
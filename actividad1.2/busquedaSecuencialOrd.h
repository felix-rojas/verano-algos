// busquedaSecuencialOrd.h
#ifndef busquedaSecuencialOrd_H
#define busquedaSecuencialOrd_H

using std::vector;

int busquedaSecuencialOrd(vector<int> vectorSorted, int key, int &compara)
{
    for (int i = 0; i < vectorSorted.size(); i++)
    {
        compara++;
        if (key <= vectorSorted[i])
        {
            if (vectorSorted[i] == key)
                return i;
            else
                return -1;
        }
    }
    return -1;
}

#endif // busquedaSecuencialOrd_H
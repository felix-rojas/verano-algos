#ifndef _LISTA_TEMPLATE_H_
#define _LISTA_TEMPLATE_H_

#include <iostream>
#include <vector>

const int MAX = 100;

template <class T>
class ListaTemplate
{
private:
    std::vector<T> data;
    int currentSize;

public:
    ListaTemplate();
    bool insert(T value);
    void erase();
    T getData(int indice);
    int getSize();
    void print();
};

template <class T>
ListaTemplate<T>::ListaTemplate()
{
    currentSize = 0;
}

template <class T>
bool ListaTemplate<T>::insert(T value)
{
    if (currentSize < MAX)
    {
        data.push_back(value);
        currentSize++;
        return true;
    }
    else
        return false;
}

template <class T>
void ListaTemplate<T>::erase()
{
    if (currentSize > 0)
    {
        std::cout << getData(currentSize - 1) << std::endl;
        data.pop_back();
        currentSize--;
    }
    else
        std::cout << "NO HAY ELEMENTOS" << std::endl;
}

#endif _LISTA_TEMPLATE_H_
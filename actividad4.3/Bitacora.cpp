#include "Bitacora.h"
#include <algorithm>
#include <iostream>

Bitacora::Bitacora() { listaRegistros.resize(0); }

Bitacora::~Bitacora() { listaRegistros.clear(); }

void Bitacora::lecturaDatos(std::string fileName)
{
    std::string month, day, hour, minute, second, ipAdd, port, message;
    std::ifstream inputFile(fileName);
    if (!inputFile.good())
    {
        inputFile.close();
        throw std::invalid_argument("File not found");
    }
    else
    {
        while (!inputFile.eof())
        {
            // to-do validar que la longitud de month sea mayor a cero
            std::getline(inputFile, month, ' ');
            std::getline(inputFile, day, ' ');
            std::getline(inputFile, hour, ':');
            std::getline(inputFile, minute, ':');
            std::getline(inputFile, second, ' ');
            std::getline(inputFile, ipAdd, ':');
            std::getline(inputFile, port, ' ');
            std::getline(inputFile, message);
            // crear un objeto de la clase Registro
            Registro tmpReg(month, day, hour, minute, second, ipAdd, port, message);
            // agregar el objeto al vector
            listaRegistros.push_back(tmpReg);
        }
        inputFile.close();
    }
}

void Bitacora::print()
{
    for (int i = 0; i < (int)listaRegistros.size(); i++)
    {
        std::cout << listaRegistros[i].getAll() << std::endl;
    }
}

void Bitacora::merge(std::vector<Registro> &listaRegistros, int low, int m, int high)
{
    int i, j, k;
    int n1 = m - low + 1;
    int n2 = high - m;
    std::vector<Registro> L(n1);
    std::vector<Registro> R(n2);

    for (i = 0; i < n1; i++)
        L[i] = listaRegistros[low + i];
    for (j = 0; j < n2; j++)
        R[j] = listaRegistros[m + 1 + j];
    i = j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            listaRegistros[k] = L[i];
            i++;
        }
        else
        {
            listaRegistros[k] = R[j];
            j++;
        }
        k++;
    }
    // Se encargan de los elementos sobrantes
    while (i < n1)
    {
        listaRegistros[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        listaRegistros[k] = R[j];
        j++;
        k++;
    }
}

void Bitacora::mergeSort(std::vector<Registro> &listaRegistros, int low, int high)
{
    if (low < high)
    {
        int m = (low + high) / 2;
        // Ordena recursivamente las dos mitades
        mergeSort(listaRegistros, low, m);
        mergeSort(listaRegistros, m + 1, high);
        // fusiona las dos mitades
        merge(listaRegistros, low, m, high);
    }
}

// binarySearch iterativa
std::vector<Registro> Bitacora::busquedaBinaria(std::vector<Registro> sortedVec, time_t inicio, time_t fin)
{
    std::vector<Registro> resultados;
    int low = 0;
    int high = sortedVec.size() - 1;
    int mid = 0;
    int found = 0;

    // find inicio
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (inicio == sortedVec[mid].getdate()){
            while (sortedVec[mid].getdate() <= fin)
            {
                mid++;
                resultados.push_back(sortedVec[mid]);
            }
            return resultados;
            break;
        }

        else if (inicio < sortedVec[mid].getdate())
            high = mid - 1;
        else
            low = mid + 1;
    }
    std::cout << "Not Found " << found << std::endl;
    return resultados;
}
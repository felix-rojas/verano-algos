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

// ! This is actually linear search using the std cpp library sorting algorithm
// * It does work though
std::vector<Registro> Bitacora::busqueda(time_t inicio, time_t fin)
{
    std::vector<Registro> resultados;
    for (int i = 0; i < (int)listaRegistros.size(); i++)
    { // filtra resultados
        if (listaRegistros[i].getdate() >= inicio && listaRegistros[i].getdate() <= fin)
        { // almacena resultados
            resultados.push_back(listaRegistros[i]);
        }
        // O(N·log(N)), where N = std::distance(first, last) comparisons on average.
        // se puede usar el sort pues es un vector con iterador
        std::sort(resultados.begin(), resultados.end());
    }
    return resultados;
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

time_t Bitacora::convertToTime(std::string fecha)
{
    std::vector<std::string> fechacom;
    std::string elemento;
    char separador = ' ';
    for_each(begin(fecha), end(fecha), [&](char const ch)
             {
        if (ch != separador) {
            elemento += ch;
        } else {
            if (elemento.length() > 0) {
                fechacom.push_back(elemento);
                elemento.clear();
            }
        } });
    if (elemento.length() > 0)
    {
        fechacom.push_back(elemento);
    }
    std::string temporal = "";
    std::string hora = fechacom[2];
    for (int i = 0; i < (int)hora.size(); i++)
    {
        if (hora[i] != ':')
        {
            temporal += hora[i];
            fechacom.push_back(temporal);
        }
        else
        {
            temporal = "";
        }
    }
    // tranforma fecha completa a segundos desde 1970
    // Almacenar los campos de la fecha-hora en el struct tm
    dateStruct.tm_sec = std::stoi(fechacom[8]);
    dateStruct.tm_min = std::stoi(fechacom[6]);
    dateStruct.tm_hour = std::stoi(fechacom[4]);
    dateStruct.tm_mday = std::stoi(fechacom[1]);

    // Agregado para resolver problema de compatibilidad en Windows
    dateStruct.tm_isdst = 0;
    for (size_t i = 0; i < meses.size(); i++)
    {
        if (meses[i] == fechacom[0])
            dateStruct.tm_mon = i;
    }
    dateStruct.tm_year = 2022 - 1900; // Asumimos el año 2022
    // Obtener el Unix timestamp a partir del struct tm anterior
    date = mktime(&dateStruct);
    return date;
}
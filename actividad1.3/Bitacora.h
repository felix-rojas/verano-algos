#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Registro.h"

class Bitacora {
  private:
    // vector de objetos Registro (cada celda es un renglon de bitacora.txt)
    std::vector<Registro> listaRegistros;

  public:
    Bitacora();
    ~Bitacora();
    void lecturaDatos(std::string fileName);
    void print();
    std::vector<Registro> busqueda(time_t inicio, time_t  fin);
    // ordenamiento y búsqueda
    time_t convertToTime(std::string fecha);
     // usado para transformar fecha completa a segundos desde 1970
    std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    // Struct que contiene todos los datos de la fecha-hora
    struct tm dateStruct;
    // Unix timestamp (segundos transcurridos desde 00:00 hrs, Jan 1, 1970 UTC)
    time_t date;
  
};

#endif // _BITACORA_H_
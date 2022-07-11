#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Registro.h"

class Bitacora
{
private:
  // vector de objetos Registro (cada celda es un renglon de bitacora.txt)
  std::vector<Registro> listaRegistros;

public:
  /* Attributes */
  // month vector
  std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  // Struct que contiene todos los datos de la fecha-hora
  struct tm dateStruct;
  // Unix timestamp (segundos transcurridos desde 00:00 hrs, Jan 1, 1970 UTC)
  time_t date;

  /* Methods */ 
  // constructor & destructor
  Bitacora();
  ~Bitacora();
  // file reading
  void lecturaDatos(std::string fileName);
  // std::cout for class, displays in terminal
  void print();
  // linear search
  std::vector<Registro> busqueda(time_t inicio, time_t fin); 
  // converts string to Unix time
  time_t convertToTime(std::string fecha);
  // sorting algorithm that reads the file
  void Bitacora::organiza(Bitacora& miBitacora);
  // binary search
  std::vector<Registro> Bitacora::busquedaBinaria(time_t inicio, time_t fin);

#endif // _BITACORA_H_
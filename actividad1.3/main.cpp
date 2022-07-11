/*
 * compilar:
 *   g++ -std=c++17 -Wall -o main *.cpp
 *
 * ejecutar:
 *   ./main
 *
 */

#include "Bitacora.h"
#include <iostream>
#include <fstream>>
int main() {

  Bitacora myBitacora;
  myBitacora.lecturaDatos("bitacora.txt");
  std::string inicio;
  std::cout << "Fecha 1 :" << std::endl;
  std::getline(std::cin,inicio);
  std::string fin;
  std::cout << "Fecha 2 :" << std::endl;
  std::getline(std::cin,fin);
  myBitacora.busqueda(myBitacora.convertToTime(inicio),myBitacora.convertToTime(fin));
 std::vector<Registro>resultado=myBitacora.busqueda(myBitacora.convertToTime(inicio),myBitacora.convertToTime(fin));
  
  std::ofstream fw("bitacora_ordenada.txt",std::ofstream::out);
  if (fw.is_open()){
    fw<<"Fecha 1 :" << "\n";
    fw<<inicio<< "\n";
    fw<< "Fecha 2 :" <<"\n";
    fw<<fin<< "\n";
    fw<<"Resultado:" <<resultado.size()<< "\n";
    for (int i = 0; i < (int)resultado.size(); i++) {
    std::cout << resultado[i].getAll() << std::endl;
    fw<< resultado[i].getAll() <<"\n";
  }
    fw.close();
   }
  else
    std::cout << "No se pudo crear el archivo :(" << std::endl;
  return 0;
}
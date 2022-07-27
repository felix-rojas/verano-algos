/*
 * compilar:
 *   g++ -std=c++17 -Wall -o main *.cpp
 * 
 * debug for all tests:
 *   valgrind --leak-check=full ./main < test01.txt | valgrind --leak-check=full ./main < test02.txt | valgrind --leak-check=full ./main < test03.txt 
 * 
 * ejecutar:
 *   ./main 
 *
 * casos de prueba
 *   ./main < test01.txt > res1.txt | ./main < test02.txt > res2.txt | ./main < test03.txt > res3.txt
 */

#include "Bitacora.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
  Bitacora myBitacora;
  
  // Usa "small.txt" para pruebas
  // myBitacora.lecturaDatos("bitacora.txt");
  // Only use it if you are using shortTest
  // myBitacora.print();  

  std::string sub;
  std::string sub1;
  int NoDirecciones;
  int NoIncidencias;
  int delimiter;
  
  std::getline(std::cin, sub, ' '); //first arg
  std::getline(std::cin, sub1);     //second arg

  NoDirecciones = std::stoi(sub); // number of IP's to process
  NoIncidencias = std::stoi(sub1);// number of incidents in the log

for (size_t i = 0; i < NoDirecciones; i++)
{
  std::getline()
}


  std::vector<Registro> datos = myBitacora.getLista();
  // hace mergesort de las IP, ignora fechas
  myBitacora.mergeSort(datos, 0, myBitacora.getSize()-1);

// file-writing
  std::ofstream fw("bitacora_ordenada.txt", std::ofstream::out);
  if (fw.is_open())
  {
   fw << "No. de Direcciones IP: " << NoDirecciones << "\n";
    fw << "No. de Incidencias: " << NoIncidencias << "\n";
    fw << "Se encontraron: " << resultado.size() << " registros"<< "\n";
    for (int i = 0; i < (int)resultado.size(); i++)
    {
      fw << resultado[i].getAll() << "\n";
    }
    
    fw << "---  ALL SORTED DATA ---" << "\n"; 
    fw << "Total registries: "<< datos.size() << "\n";
    fw << "Month Day HH:MM:SS IP:PORT Message Unixtime" << "\n";
    for (int i = 0; i < (int)datos.size(); i++)
    {
      //std::cout << datos[i].getAll() << std::endl;
      fw << datos[i].getAll() << "\n";
    }
    fw.close();
  }
  else
    std::cout << "No se pudo crear el archivo" << std::endl;
  
  return 0;
}
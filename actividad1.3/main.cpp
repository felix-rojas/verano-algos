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

int main()
{
  Bitacora myBitacora;
  
  // Usa "small.txt" para pruebas
  myBitacora.lecturaDatos("bitacora.txt");
  // Only use it if you are using shortTest
  // myBitacora.print();

  std::string inicio;
  std::getline(std::cin, inicio);
  std::string fin;
  std::getline(std::cin, fin);
  std::vector<Registro> datos = myBitacora.getLista();
  myBitacora.mergeSort(datos, 0, myBitacora.getSize()-1);

  std::vector<Registro> resultado = myBitacora.busquedaBinaria(datos, myBitacora.convertToTime(inicio), myBitacora.convertToTime(fin));

// file-writing
  // std::ofstream fw("busqueda.txt", std::ofstream::out);
  // if (fw.is_open())
  // {
  //   fw << "Fecha 1: ";
  //   fw << inicio << "\n";
  //   fw << "Fecha 2: ";
  //   fw << fin << "\n";
  //   fw << "Resultado: " << resultado.size() << "\n";
  //   for (int i = 0; i < (int)resultado.size(); i++)
  //   {
  //     std::cout << resultado[i].getAll() << std::endl;
  //     fw << resultado[i].getAll() << "\n";
  //   }
  //   fw.close();
  // }
  // else
  //   std::cout << "No se pudo crear el archivo :(" << std::endl;

  std::ofstream fw("bitacora_ordenada.txt", std::ofstream::out);
  if (fw.is_open())
  {
    
    fw << "Data search results: " << "\n";
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
    std::cout << "No se pudo crear el archivo :(" << std::endl;
  
  return 0;
}
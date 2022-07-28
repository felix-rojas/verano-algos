/*
 * compilar:
 *   g++ -std=c++17 -Wall -o main *.cpp
 *
 * debug for all tests:
 *   valgrind --leak-check=full ./main
 * ejecutar:
 *   ./main
 *
 * casos de prueba
 */

#include "Bitacora.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

// assumes a valid IPv4 address
// referenced from https://stackoverflow.com/a/5328190
double ip2int(std::string ipStr)
{
  std::stringstream s(ipStr);
  int a, b, c, d; // to store the 4 ints
  char ch;        // to temporarily store the '.'
  s >> a >> ch >> b >> ch >> c >> ch >> d;
  double res = a*std::pow(256,3) + b*std::pow(256,2) + c*256 + d;
  return res;
}

int main()
{
  {
    Bitacora A;
    std::string AddressesNo, IncidentsNo;
    std::string IPstring;
    std::string IPchunk;
    // unsigned long IPnum = 0;

    std::ifstream inputFile("bitacoraGrafos.txt");
    std::getline(inputFile, AddressesNo, ' ');
    std::getline(inputFile, IncidentsNo);
    // vector of tuples containing the ip and its int number
    std::vector<unsigned long> vecNums;
    std::vector<std::string> vecIpList;

    int addresses = stoi(AddressesNo);
    int count = 0;
    while (count < addresses)
    {
      std::getline(inputFile, IPstring);
      vecIpList.push_back(IPstring);
      count++;
    }
    inputFile.close();

    for (unsigned int i = 0; i < vecIpList.size(); i++)
    {
      vecNums.push_back(ip2int(vecIpList[i]));
    }
    for (unsigned int i = 0; i < vecIpList.size(); i++)
    {
      std::cout << i << ". " << vecIpList[i] << "number of IP: " << vecNums[i] << "\n";
    }
  }
  return 0;
}

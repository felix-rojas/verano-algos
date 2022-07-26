#include "Registro.h"

Registro::Registro()
{
  mes = "";
  dia = "";
  hora = "";
  min = "";
  seg = "";
  ip = "";
  puerto = "";
  msg = "";
}

Registro::Registro(std::string mes, std::string dia,
                   std::string hora, std::string min,
                   std::string seg, std::string ip,
                   std::string puerto, std::string msg)
{
  this->mes = mes;
  this->dia = dia;
  this->hora = hora;
  this->min = min;
  this->seg = seg;
  this->ip = ip;
  this->puerto = puerto;
  this->msg = msg;
  // tranforma fecha completa a segundos desde 1970
  // Almacenar los campos de la fecha-hora en el struct tm
  dateStruct.tm_sec = std::stoi(seg);
  dateStruct.tm_min = std::stoi(min);
  dateStruct.tm_hour = std::stoi(hora);
  dateStruct.tm_mday = std::stoi(dia);
  // Agregado para resolver problema de compatibilidad en Windows
  dateStruct.tm_isdst = 0;
  for (size_t i = 0; i < meses.size(); i++)
  {
    if (meses[i] == mes)
      dateStruct.tm_mon = i;
  }
  dateStruct.tm_year = 2022 - 1900; // Asumimos el año 2022
  // Obtener el Unix timestamp a partir del struct tm anterior
  date = mktime(&dateStruct);
  ipNumber = ip2int(ip);
}

// converts ip to decimal
unsigned int Registro::ip2int(std::string ipSequence)
{
    std::string delim = ".";
    auto start = 0;
    auto end = ipSequence.find(delim);
    unsigned int temp;
    unsigned int res = 0;
    int count = 3;
    while (end != std::string::npos)
    {
        temp = stoi(ipSequence.substr(start, end - start));
        res += temp * pow(256, count);
        start = end + delim.length();
        end = ipSequence.find(delim, start);
        count--;
    }
    temp = stoi(ipSequence.substr(start, end));
    res += temp;
    return res;
}

std::string Registro::getAll()
{
  return mes + " " + dia + " " +
         hora + ":" + min + ":" +
         seg + " " + ip + ":" +
         puerto + " " + msg + " " + std::to_string(date);
}

time_t Registro::getdate()
{
  return date;
}

std::string Registro::getIP()
{
  return ip;
}

// bool Registro::operator==(const Registro &other) const
// {
//   return this->date == other.date;
// }

// bool Registro::operator!=(const Registro &other) const
// {
//   return this->date != other.date;
// }

// bool Registro::operator>(const Registro &other) const
// {
//   return this->date > other.date;
// }

// bool Registro::operator<(const Registro &other) const
// {
//   return this->date < other.date;
// }

// bool Registro::operator<=(const Registro &other) const
// {
//   return this->date <= other.date;
// }

// bool Registro::operator>=(const Registro &other) const
// {
//   return this->date >= other.date;
// }


bool Registro::operator==(const Registro &other) const
{
  return this->ipNumber == other.ipNumber;
}

bool Registro::operator!=(const Registro &other) const
{
  return this->ipNumber != other.ipNumber;
}

bool Registro::operator>(const Registro &other) const
{
  return this->ipNumber > other.ipNumber;
}

bool Registro::operator<(const Registro &other) const
{
  return this->ipNumber < other.ipNumber;
}

bool Registro::operator<=(const Registro &other) const
{
  return this->ipNumber <= other.ipNumber;
}

bool Registro::operator>=(const Registro &other) const
{
  return this->ipNumber >= other.ipNumber;
}

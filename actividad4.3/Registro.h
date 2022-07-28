#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <iostream>

class Registro
{
private:
    std::string mes;
    std::string dia;
    std::string hora;
    std::string min;
    std::string seg;
    std::string InIpAdd;
    std::string InPort;
    std::string OutIpAdd;
    std::string OutPort;
    std::string msg;
    // usado para transformar fecha completa a segundos desde 1970
    std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    // Struct que contiene todos los datos de la fecha-hora
    struct tm dateStruct;
    // Unix timestamp (segundos transcurridos desde 00:00 hrs, Jan 1, 1970 UTC)
    time_t date;

public:
    Registro();
    Registro(std::string mes, std::string dia, std::string hora, std::string min, std::string seg,
             std::string InIpAdd,
             std::string InPort,
             std::string OutIpAdd,
             std::string OutPort, std::string msg);

    std::string getAll();
    time_t getdate();
    std::string getIPin() { return InIpAdd; }
    std::string getIPOut() { return OutIpAdd; }
    unsigned int ip2int(std::string IPV4address);
    // sobrecarga operadores
    bool operator==(const Registro &) const;
    bool operator!=(const Registro &) const;
    bool operator>(const Registro &) const;
    bool operator<(const Registro &) const;
    bool operator>=(const Registro &) const;
    bool operator<=(const Registro &) const;
};

#endif //_REGISTRO_H_
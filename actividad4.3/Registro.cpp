#include "Registro.h"

Registro::Registro()
{
    mes = "";
    dia = "";
    hora = "";
    min = "";
    seg = "";
    InIpAdd = "";
    InPort = "";
    OutIpAdd = "";
    OutPort = "";
    msg = "";
}

Registro::Registro(std::string mes, std::string dia, std::string hora, std::string min, std::string seg, 
                   std::string InIpAdd, std::string InPort, std::string OutIpAdd, std::string OutPort, 
                   std::string msg)
{
    this->mes = mes;
    this->dia = dia;
    this->hora = hora;
    this->min = min;
    this->seg = seg;
    this->InIpAdd = InIpAdd;
    this->InPort = InPort;
    this->OutIpAdd = OutIpAdd;
    this->OutPort = OutPort;
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
}

std::string Registro::getAll()
{
    return mes + " " + dia + " " +
           hora + ":" + min + ":" +
           seg + " " + InIpAdd + ":" +
           InPort + " " + OutIpAdd + ":" +
           OutPort + " "+ msg;
}

time_t Registro::getdate()
{
    return date;
}

// using unsigned integer because pow(2, 32) is the amount of IPv4 that exist


// bool Registro::operator==(const Registro &other) const
// {
//     return this->date == other.date;
// }

// bool Registro::operator!=(const Registro &other) const
// {
//     return this->date != other.date;
// }

// bool Registro::operator>(const Registro &other) const
// {
//     return this->date > other.date;
// }

// bool Registro::operator<(const Registro &other) const
// {
//     return this->date < other.date;
// }

// bool Registro::operator<=(const Registro &other) const
// {
//     return this->date <= other.date;
// }

// bool Registro::operator>=(const Registro &other) const
// {
//     return this->date >= other.date;
// }

bool Registro::operator==(const Registro &rightIP) const
{
    return this->InIpAdd == rightIP.InIpAdd;
}

bool Registro::operator!=(const Registro &rightIP) const
{
    return this->InIpAdd != rightIP.InIpAdd;
}

bool Registro::operator>(const Registro &rightIP) const
{
    return this->InIpAdd > rightIP.InIpAdd;
}

bool Registro::operator<(const Registro &rightIP) const
{
    return this->InIpAdd < rightIP.InIpAdd;
}

bool Registro::operator<=(const Registro &rightIP) const
{
    return this->InIpAdd <= rightIP.InIpAdd;
}

bool Registro::operator>=(const Registro &rightIP) const
{
    return this->InIpAdd >= rightIP.InIpAdd;
}

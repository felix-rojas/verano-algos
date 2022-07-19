#ifndef REGISTRO_H
#define REGISTRO_H
#include <string>
#include "DateTime.h"

class Registro {
private:
    DateTime date;
    std::string mes;
    std::string dia;
    std::string hora;
    std::string minuto;
    std::string segundo;
    std::string ip;
    std::string error;


public:
    Registro();
    Registro(std::string _mes, std::string _dia, std::string _horas, std::string _minutos, std::string _segundos, std::string _ip, std::string _error, DateTime _date);
    std::string getTexto();
    DateTime getDate();
    bool operator ==(const Registro&);
    bool operator !=(const Registro&);
    bool operator >(const Registro&);
    bool operator <(const Registro&);
    bool operator >=(const Registro&);
    bool operator <=(const Registro&);
};

Registro::Registro(){
    mes = "";
    dia = "";
    hora = "";
    minuto = "";
    segundo = "";
    ip = "";
    error = "";
}

Registro::Registro(std::string _mes, std::string _dia, std::string _horas, std::string _minutos, std::string _segundos, std::string _ip, std::string _error, DateTime _date){
    mes = _mes;
    dia = _dia;
    hora = _horas;
    minuto = _minutos;
    segundo = _segundos;
    ip = _ip;
    error = _error;
    date = _date;
}

DateTime Registro::getDate() {
    return date;
}

std::string Registro::getTexto() {
    return mes + " " + dia + " " + hora + ":" + minuto + ":" + segundo + " " + ip + " " + error;
}

bool Registro::operator==(const Registro &other) {
    return this->date == other.date;
}

bool Registro::operator!=(const Registro &other) {
    return this->date != other.date;
}

bool Registro::operator>(const Registro &other) {
    return this->date > other.date;
}

bool Registro::operator<(const Registro &other) {
    return this->date < other.date;
}

bool Registro::operator<=(const Registro &other) {
    return this->date < other.date;
}

bool Registro::operator>=(const Registro &other) {
    return this->date < other.date;
}


#endif

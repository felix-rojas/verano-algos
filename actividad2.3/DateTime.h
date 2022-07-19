#ifndef DateTime_H
#define DateTime_H


#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>

class DateTime {

public:
    DateTime();
    DateTime(std::string mes, int dia, int horas, int minutos, int segundos);
    time_t getDate();
    bool operator ==(const DateTime&);
    bool operator !=(const DateTime&);
    bool operator >(const DateTime&);
    bool operator <(const DateTime&);
    bool operator >=(const DateTime&);
    bool operator <=(const DateTime&);

private:
    std::vector<std::string> meses = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    // Struct que contiene todos los datos de la fecha-hora
    struct tm dateStruct;
    // Unix timestamp (segundos transcurridos desde 00:00 hrs, Jan 1, 1970 UTC)
    time_t date;
};

DateTime::DateTime() {

}

DateTime::DateTime(std::string mes, int dia, int horas, int minutos, int segundos) {
    dateStruct.tm_sec = segundos;
    dateStruct.tm_min = minutos;
    dateStruct.tm_hour = horas;
    dateStruct.tm_mday = dia;
    dateStruct.tm_isdst = 0;
    for (int i=0; i < meses.size(); i++) {
        if (meses[i]==mes)
            dateStruct.tm_mon = i;
    }
    dateStruct.tm_year = 2022 - 1900; 
    date = mktime(&dateStruct);
}

time_t DateTime::getDate() {
    std::cout<<date;
    return date;
}

bool DateTime::operator==(const DateTime &other) {
    return this->date == other.date;
}

bool DateTime::operator!=(const DateTime &other) {
    return this->date != other.date;
}

bool DateTime::operator>(const DateTime &other) {
    return this->date > other.date;
}

bool DateTime::operator<(const DateTime &other) {
    return this->date < other.date;
}

bool DateTime::operator<=(const DateTime &other) {
    return this->date < other.date;
}

bool DateTime::operator>=(const DateTime &other) {
    return this->date < other.date;
}
#endif

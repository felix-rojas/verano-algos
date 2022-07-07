#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <string>

class Registro {
  private:
    std::string mes;
    std::string dia;
    std::string hora;
    std::string min;
    std::string seg;
    std::string ip;
    std::string puerto;
    std::string msg;
  
  public:
    Registro();
    Registro(std::string mes, std::string dia, std::string hora, std::string min, std::string seg, std::string ip, std::string puerto, std::string msg);
};

#endif //_REGISTRO_H_
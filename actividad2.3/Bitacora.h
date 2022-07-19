#ifndef BITACORA_H
#define BITACORA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Registro.h"
#include "DLinkedList.h"

class Bitacora {
private:
    DLinkedList <Registro> listaRegistros;
    std::string linea, campo, horaCompleta;

public:
    Bitacora();
    void leerArchivo(std::string Archivo_a_leer);

   
    int getSize();
    void print();

   
    void busquedaFechas();
    int busquedaBinaria(int size, Registro fecha_completa);
    void buscarRegistros(int inicial, int final);

    void nuevoArchivo();
};

Bitacora::Bitacora(){

}

void Bitacora::leerArchivo(std::string Archivo_a_leer){
   
    std::ifstream archivo(Archivo_a_leer);
    while (getline(archivo, linea)) {
       
        int diaInt,horasInt,minutosInt,segundosInt;
        std::string datos[10],horaCom[3];
        std::string mes_,dia_,horas_,minutos_,segundos_,ip_,error_="";
        std::istringstream ss(linea);
        for (int i = 0; i < 10; i++){
            getline(ss,campo,' ');
            datos[i]=campo;
            std::istringstream st(datos[i]);
            if (i==0){
                mes_=datos[i];
            }
            else if (i==1){
                dia_=datos[i];
                st>>diaInt;
            }
            else if (i==2){
                for (int k = 0; k < 3; k++){
                    getline(st,horaCompleta,':');
                    std::istringstream iss(horaCompleta);
                    horaCom[k]=horaCompleta;
                    if (k==0){
                        horas_=horaCom[k];
                        iss>>horasInt;
                    }
                    if (k==1){
                        minutos_=horaCom[k];
                        iss>>minutosInt;
                    }
                    if (k==2){
                        segundos_=horaCom[k];
                        iss>>segundosInt;
                    }
                }
            }
            else if (i==3){
                ip_=datos[i];
            }
            else if (i>3){
                if (datos[i]!=datos[i-1]){
                    error_+=datos[i]+" ";
                }
            }
        }
        error_.pop_back();
        DateTime date(mes_,diaInt,horasInt,minutosInt,segundosInt);
        Registro tmpRegistro(mes_, dia_, horas_, minutos_, segundos_, ip_, error_, date);
        listaRegistros.addLast(tmpRegistro);

    }
   
    listaRegistros.Iterative_quickSort();
}

int Bitacora::getSize(){
    return listaRegistros.getNumElements();
}

void Bitacora::print() {
    for (int i=0; i < listaRegistros.getNumElements(); i++) {
        std::cout << listaRegistros.getData(i).getTexto()<< std::endl;
    }
}

void Bitacora::busquedaFechas(){
    std::string fechaInicial,fechaFinal;
    std::cout<<"Ingrese fecha de inicio: "<<std::endl;
    getline(std::cin,fechaInicial);

    std::string mes = fechaInicial.substr(0, 3);
    int dia = stoi(fechaInicial.substr(4, 2));
    int horas = stoi(fechaInicial.substr(7, 2));
    int minutos = stoi(fechaInicial.substr(10, 2));
    int segundos = stoi(fechaInicial.substr(13, 2));
    DateTime fInicial(mes,dia,horas,minutos,segundos);
    Registro fechaI(mes,fechaInicial.substr(4, 2),fechaInicial.substr(7, 2),fechaInicial.substr(10, 2),fechaInicial.substr(13, 2),"","",fInicial);

    std::cout<<"Ingresa fecha final"<<std::endl;
    getline(std::cin,fechaFinal);
    mes = fechaFinal.substr(0, 3);
    dia = stoi(fechaFinal.substr(4, 2));
    horas = stoi(fechaFinal.substr(7, 2));
    minutos = stoi(fechaFinal.substr(10, 2));
    segundos = stoi(fechaFinal.substr(13, 2));
    DateTime fFinal(mes,dia,horas,minutos,segundos);
    Registro fechaF(mes,fechaFinal.substr(4, 2),fechaFinal.substr(7, 2),fechaFinal.substr(10, 2),fechaFinal.substr(13, 2),"","",fFinal);


    int pos_Inicial=busquedaBinaria(getSize(),fechaI);
    int pos_Final=busquedaBinaria(getSize(),fechaF);
    buscarRegistros(pos_Inicial,pos_Final);
}

int Bitacora::busquedaBinaria(int size, Registro fecha_completa){
    int low = 0;
    int high = size-1;
    while(low <= high){
        int h = low + (high - low)/2;
        if (fecha_completa == listaRegistros.getData(h)){
            return h;//posición
        }
        else if (fecha_completa < listaRegistros.getData(h)){
            high = h -1;
        }
        else{
            low = h +1;
        }
    }
    return -1;
}

void Bitacora::buscarRegistros(int inicial, int final){
    if (inicial==-1 || inicial > getSize()){
        std::cout<<"Opción de fecha inicial inválida"<<std::endl;
    }
    else if (final==-1 || final > getSize()){
        std::cout<<"Opción de fecha final inválida"<<std::endl;
    }
    else{
        std::cout<<"\nResultado: "<<final-inicial+1<<" Registros."<<std::endl;
        std::ofstream file;
        file.open("resultado_busqueda.txt");
        for (int i = inicial; i < final+1; i++){
            file<<this->listaRegistros.getData(i).getTexto()<<"\n";
        }
    }

}

void Bitacora::nuevoArchivo(){
    std::ofstream file;
    file.open("bitacora_ordenada.txt");
    for (int i = 0; i < getSize(); i++)
    {
        file << listaRegistros.getData(i).getTexto()<<"\n";
    }
    file.close();
}



#endif 

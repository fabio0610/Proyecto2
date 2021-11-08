//Equipo .h

//definicion de equipo
#ifndef EQUIPO
#define EQUIPO
//inclusion de librerias
#include <iostream>
#include <string>
using namespace::std;
//Clase Equipo
class Equipo{ //inicio de la clase
public:
    // CREACION DE CONSTRUCTORES 
    Equipo() {
        this->Name= "";
        this->id= 0;
        this->puntaje=0;
    }

    Equipo(int id, const string &name, int puntaje) : id(id), Name(name), puntaje(puntaje) {}

    ~Equipo(){};
    // PROPIEDADES DE LA CLASE 
    int id;
    string Name;
    int puntaje;
};

#endif




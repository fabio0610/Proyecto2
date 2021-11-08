#ifndef EQUIPO
#define EQUIPO
#include <iostream>
#include <string>
using namespace::std;
class Equipo{
public:
    // CONSTRUCTORES
    Equipo() {
        this->Name= "";
        this->id= 0;
        this->puntaje=0;
    }

    Equipo(int id, const string &name, int puntaje) : id(id), Name(name), puntaje(puntaje) {}

    ~Equipo(){};
    // PROPIEDADES
    int id;
    string Name;
    int puntaje;
    // METODOS
};

#endif




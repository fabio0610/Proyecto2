/* TODO
    - INCLUIR LAS PROPIEDADES DE LOS EQUIPOS.
    - ALLOCNODO CREA EL ARBOL BINARIO HASTA EL NIVEL DE LOS EQUIPOS.
    - NAMEEQUIPO SIRVE PARA NOMBRAR LOS EQUIPOS PERO TAMBIEN SE PUEDE
        UTILIZAR PARA RELLENAR LAS PROPIEDADES.

    LO COMPILE EN WINDOWS ASI (REQUIERE C++17):
        cl main.cpp /std:c++17
*/

#include <iostream>
#include <string>
#include <cmath>
#include "node.h"
using namespace::std;

#ifndef EQUIPO
#define EQUIPO
class Equipo{
    public:
    // CONSTRUCTORES
    Equipo() {
        this->Name= " ";
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

#ifndef ARBOLBINARIO
#define ARBOLBINARIO
class ArbolBinarioInverso{
    public:
    // CONSTRUCTORES
    ArbolBinarioInverso(){};
    ArbolBinarioInverso(int i){
        this->size=i;
        this->level = log2(i);
        this->arbol = new Nodo<Equipo>[i];
        for(int n = 0; n<i;n++){
            this->arbol[n].content = new Equipo();
        }
        while (i != 1 ){
            int j = 0;
            for (int k = 0 ; k<i/2 ;k++){
                Nodo<Equipo>* Parent = new Nodo<Equipo>();
                this->arbol[j].parent = Parent;
                this->arbol[j].content->id = 0;
                this->arbol[j].content->Name = "a";
                this->arbol[j].content->puntaje = 0;
                this->arbol[j+1].parent = Parent;
                this->arbol[j+1].content->id = 0;
                this->arbol[j+1].content->Name = "a";
                this->arbol[j+1].content->puntaje = 0;
                j=j+2;
            }
            i=i/2;
        }
    };
    ~ArbolBinarioInverso(){};
    // PROPIEDADES
    int level;
    int size;
    Nodo<Equipo>* arbol;
    // METODOS
    void print(){
        int i =this->size;
        while (i != 1 ){
            int j = 0;
            for (int k = 0 ; k<i/2 ;k++){
                cout << this->arbol[j].content->id << ":" << this->arbol[j+1].content->id;
                cout << "\t";
                j=j+2;
            }
            cout << endl;
            i=i/2;
        }
        cout << "ganador";
    }
};
#endif

int main(int argc, char const *argv[])
{
    // AQUI SOLICITAR AL USUARIO EL NUMERO DE EQUIPO, EN ESTE CASO 8
    ArbolBinarioInverso* miArbol = new ArbolBinarioInverso(8);
    miArbol->print();
    return 0;
}

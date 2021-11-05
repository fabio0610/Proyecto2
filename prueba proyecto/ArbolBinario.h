#include "Equipo.h"
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "node.h"
using namespace::std;
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
            this->arbol[j+1].parent = Parent;
            j=j+2;
        }
            i=i/2;
        }
    };
    ~ArbolBinarioInverso(){};
    // PROPIEDADES
    int level;
    int size;
    int id;
    int puntaje;
    string nombre;

    Nodo<Equipo>* arbol;
    // METODOS
    bool checkrep(int n, int num[])
    {
        for(int i=0; i<this->size; i++)
            if(n == num[i])
                return true;
        return false;
    }


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

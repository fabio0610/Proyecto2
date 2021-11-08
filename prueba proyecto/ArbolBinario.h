//Arbol .h

//inclusion de librerias
#include "Equipo.h"
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "node.h"
using namespace::std;
//definicion de arbol binario
#ifndef ARBOLBINARIO
#define ARBOLBINARIO

//Clase arbol binario inverso
class ArbolBinarioInverso{ //inicio de la clase
public:
    // CREACION DE LOS CONSTRUCTORES
    ArbolBinarioInverso(){}; 
    ArbolBinarioInverso(int i){ //recibe como parametro la cantidad de hijos (equipos totales)
        this->size=i; //asignacion de variable tamaño el numero recibido como parametro
        this->level = log2(i); //asignacion de la potencia de 2 para la cantidad de niveles del arbol
        this->arbol = new Nodo<Equipo>[i]; //creacion del nodo arbol 
        for(int n = 0; n<i;n++){ //for para inicializar los nodos
            this->arbol[n].content = new Equipo();
        }
        while (i != 1 ){ //ciclo que recorre todos los niveles del arbol desde n hasta 0
        int j = 0;
        for (int k = 0 ; k<i/2 ;k++){ //for para recorrer el arbol de 2 en 2
            Nodo<Equipo>* Parent = new Nodo<Equipo>(); //inicializacion de los padres de los equipos (nodos inferiores)
            this->arbol[j].parent = Parent; //asignacion a arbol en posicion j el mismo padre
            this->arbol[j+1].parent = Parent; //asignacion a arbol en posicion j+1 el mismo padre 
            j=j+2; //aumento de j en dos posiciones
        }
            i=i/2; //disminucion del nivel
        }
    };
    ~ArbolBinarioInverso(){};
    // PROPIEDADES DE LA CLASE
    int level;
    int size;
    int id;
    int puntaje;
    string nombre;

    Nodo<Equipo>* arbol;

};
#endif

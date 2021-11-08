//Node .h
//Definicion de Nodo
#ifndef NODO
#define NODO
//creacion de plantilla para utilizacion de nodo
template <typename T>
//clase Nodo
class Nodo{ //inicio de la clase
    public:
    // CREACION DE CONSTRUCTOREs
    Nodo(){
        this->content = new T();
        this->parent = nullptr;
    };
    ~Nodo(){};
    // PROPIEDADES DE LA CLASE 
    T* content;
    Nodo* parent;
};
#endif
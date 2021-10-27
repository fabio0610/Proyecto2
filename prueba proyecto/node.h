#ifndef NODO
#define NODO
template <typename T>
class Nodo{
    public:
    // CONSTRUCTORES
    Nodo(){
        this->content = new T();
        this->parent = nullptr;
    };
    ~Nodo(){};
    // PROPIEDADES
    T* content;
    Nodo* parent;
    // METODOS
};
#endif
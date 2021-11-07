//Bibliotecas a usar en el menu
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <bits/stdc++.h>
#include "ArbolBinario.h"
using namespace std;

vector<Equipo*> Equipos;

bool verificador(ArbolBinarioInverso* arbol,int i){
    bool ver=false;
    if(i>0&&i<=arbol->size){
        ver= true;
    }else{
        ver=false;
    }
    return ver;
}

bool checkrep(int n, int num[], ArbolBinarioInverso* arbol)
{
    for(int i=0; i<arbol->size; i++)
        if(n == num[i])
            return true;
    return false;
}

void admin_contendientes(ArbolBinarioInverso* arbol){
    srand(time(NULL));
    int vec[arbol->size];
    int puntaje=0;
    int id=0;
    string nombre=" ";
    int j=0;
    for (int k = 0 ; k<(arbol->size)/2 ;k++) {
        cout << "Ingrese el nombre del equipo" << endl;
        cin >> nombre;
        cout << "Ingrese el puntaje del equipo" << endl;
        cin >> puntaje;
        do
            id = 1 + rand() % arbol->size;
        while (checkrep(id, vec, arbol));
        vec[j] = id;
        arbol->arbol[j].content->id = id;
        arbol->arbol[j].content->Name = nombre;
        arbol->arbol[j].content->puntaje = puntaje;
        Equipos.push_back(arbol->arbol[j].content);
        cout << "Ingrese el nombre del equipo" << endl;
        cin >> nombre;
        cout << "Ingrese el puntaje del equipo" << endl;
        cin >> puntaje;
        do
            id = 1 + rand() % arbol->size;
        while (checkrep(id, vec, arbol));
        vec[j + 1] = id;
        arbol->arbol[j + 1].content->id = id;
        arbol->arbol[j + 1].content->Name = nombre;
        arbol->arbol[j + 1].content->puntaje = puntaje;
        Equipos.push_back(arbol->arbol[j+1].content);
        j=j+2;
    }
}

int calc_puntaje(ArbolBinarioInverso* arbol, int id){
int Nuevo_puntaje;
if(arbol->arbol[id].parent == arbol->arbol[id+1].parent) {
    Nuevo_puntaje = arbol->arbol[id].content->puntaje + (1 + (arbol->arbol[id+1].content->puntaje)/arbol->arbol[id].content->puntaje);
}else if(arbol->arbol[id-1].parent == arbol->arbol[id].parent){
    Nuevo_puntaje = arbol->arbol[id].content->puntaje + (1 + (arbol->arbol[id-1].content->puntaje)/arbol->arbol[id].content->puntaje);
}
    return Nuevo_puntaje;
}

void Ingre_ganador(ArbolBinarioInverso* arbol,int Id) {
    int i = arbol->size;
    int j = 0;
    int n = 1;
   /* for (int k = 0; k < arbol->size; k++) {
        if (arbol->arbol[k].content->id == Id) {
            arbol->arbol[k].parent->content = arbol->arbol[k].content;
        }
    }*/

    Nodo <Equipo> *nodo1;
    Nodo <Equipo> *nodo2;
    Equipo *parent1;
    Equipo *parent2;
    //i = i / 2;

    while (i != 1) {
        for (int k = 0; k < i/2 ; k++) {
            if (i <= (arbol->size) / 4) {
                nodo1 = arbol->arbol[j].parent;
                nodo2 = arbol->arbol[j + 2].parent;
                for (int m = 0; m < n; m++) {
                    nodo1 = nodo1->parent;
                    nodo2 = nodo2->parent;
                }
                n++;
            } else if (i == (arbol->size) / 2) {
                nodo1 = arbol->arbol[j].parent;
                nodo2 = arbol->arbol[j + 2].parent;
                if (nodo1 != NULL || nodo2 != NULL) {
                    if (nodo1->parent == NULL) {
                        if (nodo1->content->id == Id) {
                            nodo1->parent=new Nodo<Equipo>;
                            nodo1->parent->content = nodo1->content;
                        }
                    }
                    if (nodo2->parent == NULL) {
                        if (nodo2->content->id== Id) {
                            nodo2->parent=new Nodo<Equipo>;
                            nodo2->parent->content=nodo2->content;
                        }
                    }
                }
            }else {
                nodo1 = &arbol->arbol[j];
                nodo2 = &arbol->arbol[j + 1];
                if (verificador(arbol,nodo1->parent->content->id) == false) {
                    if (nodo1->content->id == Id) {
                        nodo1->parent=new Nodo<Equipo>;
                        nodo1->parent->content = nodo1->content;

                    }
                }
                if (verificador(arbol,nodo2->parent->content->id)==false) {
                    if (nodo2->content->id== Id) {
                        nodo2->parent=new Nodo<Equipo>;
                        nodo2->parent->content=nodo2->content;

                    }
                }
            }


            if (i  <arbol->size){
                j = j + 4;
            }else{
                j = j + 2;
            }
        }
        j = 0;
        i = i / 2;
    }
}

void choque_contendientes(int Id1, int Id2){
/* if(nodo1.content.id==id1 || nodo2.content.id==id1 ||nodo1.content.id==id2 || nodo2.content.id==id2){
     * if(nodo1.content.id == id1 && nodo2.content.id ==id2){
     * mostrsr llave();
     * break;
     * }else{
     * ganan los dos encuentos;
     * }
     * }else{
     *
     * int nuimero =rand%1000;
     * numero%2 ==0;
     * ganada id 1
     * else ganda id2
     * }
     *
     *
     *
     * */


//va logica de recorrido
}

void Puntaje_campeon(ArbolBinarioInverso* arbol,int Id){
    /* if(nodo1.content.id==id || nodo2.content.id==id){
     * gana
     * }else{
     *
     * int nuimero =rand%1000;
     * numero%2 ==0;
     * ganada id 1
     * else ganda id2
     * }
     *
     *
     *
     * */
    int i = arbol->size;
    int j = 0;
    int n=1;
    for (int k = 0; k < arbol->size; k++) {
        if (arbol->arbol[k].content->id == Id) {
            arbol->arbol[k].parent->content = arbol->arbol[k].content;
        }
    }
    Nodo<Equipo> *nodo1;
    Nodo<Equipo> *nodo2;
    Equipo *parent1;
    Equipo *parent2;
    i=i/2;

    while (i!=1) {
        for (int k = 0; k < i / 2; k++) {
            if (i <= (arbol->size) / 4) {
                nodo1 = arbol->arbol[j].parent;
                nodo2 = arbol->arbol[j + 2].parent;
                if(nodo1!=NULL||nodo2!=NULL) {
                    if(nodo1!=NULL) {
                        if (arbol->arbol[j].content->id == Id) {
                            nodo1->content = arbol->arbol[j].content;
                        }
                    }if(nodo2!=NULL) {
                        if (arbol->arbol[j + 2].content->id == Id) {
                            nodo2->content = arbol->arbol[j + 2].content;
                        }
                    }
                    for (int m = 0; m < n; m++) {
                        nodo1 = nodo1->parent;
                        nodo2 = nodo2->parent;
                    }
                    n++;
                }
            }
            j=j+4;
        }
        j=0;
        i=i/2;
    }

}



void mostrar_llave(ArbolBinarioInverso* arbol){
    int i = arbol->size;
    int n = 1;
    int j = 0;
    for (int k = 0 ; k<i/2 ;k++){
        cout << arbol->arbol[j].content->id << ":" << arbol->arbol[j+1].content->id;
        cout << "\t";
        j=j+2;
    }
    cout << endl;
    cout<<"  ";
    i=i/2;
    j=0;
    Nodo<Equipo> *nodo1;
    Nodo<Equipo> *nodo2;
    Equipo *parent1;
    Equipo *parent2;
    while (i != 1 ){
        for (int k = 0 ; k<i/2 ;k++){
            if (i<=(arbol->size)/4){
                nodo1=arbol->arbol[j].parent;
                nodo2=arbol->arbol[j+2].parent;
                for (int m = 0 ; m<n ;m++){
                    nodo1=nodo1->parent;
                    nodo2=nodo2->parent;
                }
                n++;
            }else{
                nodo1=arbol->arbol[j].parent;
                nodo2=arbol->arbol[j+2].parent;
            }
            if(nodo1 == NULL || nodo2==NULL){
                if (nodo1 ==NULL&& nodo2==NULL){
                    cout<<"N/A"<<":"<<"N/A";
                    cout << "\t";
                }else if(nodo2== NULL){
                    parent1=nodo1->content;
                    cout<<parent1->id<<":"<<"N/A";
                    cout << "\t";
                }else if(nodo1== NULL){
                    parent2=nodo2->content;
                    cout<<"N/A"<<":"<<parent2->id;
                    cout << "\t";
                }
            }else {
                parent1 = nodo1->content;
                parent2 = nodo2->content;
                if (verificador(arbol, parent1->id) == false && verificador(arbol, parent2->id) == false) {
                    cout << "N/A" << ":" << "N/A";
                    cout << "\t";
                } else if (verificador(arbol, parent2->id) == false) {
                    cout << parent1->id << ":" << "N/A";
                    cout << "\t";
                } else if (verificador(arbol, parent1->id) == false) {
                    cout << "N/A" << ":" << parent2->id;
                    cout << "\t";
                } else {
                    cout << parent1->id << ":" << parent2->id;
                    cout << "\t";
                }
            }
            j=j+4;
        }
        j=0;
        cout << endl;
        cout << "  ";
        i=i/2;
    }

    if(nodo1->parent == NULL || nodo2->parent==NULL){
        cout<<"N/A";
        cout << "\t";
    }else{
        if(nodo1->parent != NULL || nodo2->parent != NULL){
            cout<<nodo1->content->id;
            cout << "\t";
        }

    }

    cout<<endl;
}



void bubbleSort()
{
    int i,j;
    Equipo* temp;
    for(i=0; i<Equipos.size(); i++)
    {
        for(j=0; j<(Equipos.size()-i-1); j++)
        {
            if(Equipos[j]->puntaje<Equipos[j+1]->puntaje)
            {
                temp = Equipos[j];
                Equipos[j] = Equipos[j+1];
                Equipos[j+1] = temp;
            }
        }
    }
}

void mostrar_contendientes(){
    bubbleSort();
    cout<<"Lista contendientes:"<<endl;
    for (auto const &i: Equipos) {
        cout <<"El nombre del equipo es:"<< i->Name << endl;
        cout <<"El id del equipo es:"<< i->id << endl;
        cout <<"El el puntjae del equipo es:"<< i->puntaje << endl;
        cout << endl<<endl<<endl;
    }
}

//acerca de
void acerca_de(){
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
	cout << "Instituto Tecnologico de Costa Rica." << endl;
	cout << "Sede Interuniversitaria de Alajuela." << endl;
	cout << "Analisis y disenno de algoritmos." << endl;
	cout << "Proyecto #2" << endl;
	cout << "Estudiantes: Michelle Gutierrez Araya." << endl;
	cout << "             Carnet: 2021437374 "<< endl;
	cout << "             Maria Paulina Camacho Herrera." << endl;
	cout << "             Carnet: 2021093601" << endl;
	cout << "II Semestre." << endl;
	cout << "Anno: 2021" << endl;
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
}

//funcion menu A -> primer menu
int menu_A(){
    int a;
    cout << "[MENU]" << endl;
    cout << "1. Configurar juego" << endl;
    cout << "2. Administracion de contendientes" << endl;
    cout << "3. Acerca de" << endl;
    cout << "4. Salir" << endl;
    cin >> a;
    return a;
}

//funcion menu B -> segundo menu
int menu_B(){
    int b;
    cout << "1. Ingresar ganador de partida" << endl;
    cout << "2. Choque de contendientes" << endl;
    cout << "3. Puntaje mas alto si es campeon" << endl;
    cout << "4. Mostrar llave" << endl;
    cout << "5. Mostrar contendientes ordenados de manera descendente" << endl;
    cout << "6. Volver"<<endl;
    cin >> b;
    return b;
}

void menu1(ArbolBinarioInverso* arbol){
    int id=0;
    int opcion_seleccionada = 0;
    do{
        opcion_seleccionada = menu_B();
        switch(opcion_seleccionada)
        {
            case 1: //configuracion de juego
                cout<<"Ingrese el ID del equipo ganador"<<endl;
                cin>>id;
                Ingre_ganador(arbol,id);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                mostrar_llave(arbol);
                break;
            case 5:
                mostrar_contendientes();
                break;
            case 6: //salir
                break;
        }
    }while(opcion_seleccionada < 6);
}

void menu(){
    int opcion_seleccionada = 0;
    int numCont=0;
    ArbolBinarioInverso* miArbol;
    do{
        opcion_seleccionada = menu_A();
        switch(opcion_seleccionada)
        {
            case 1: //configuracion de juego
            cout<< "Ingrese el numero de equipos que tendrá el torneo (el mumero tiene que ser potencia de 2):"<<endl;
            cin>>numCont;
               miArbol=new ArbolBinarioInverso(numCont);
                break;
            case 2: //admi de contendientes -> funcion menu B
                admin_contendientes(miArbol);
                menu1(miArbol);
                break;
            case 3: //acerca de
                acerca_de();
                break;
            case 4: //salir
                break;
        }
    }while(opcion_seleccionada < 4);
}

//FUNCION PRINCIPAL
int main(){
    menu();
}
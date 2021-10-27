
//Bibliotecas a usar en el menu
#include <iostream>
#include <string>
#include "ArbolBinario.h"
using namespace std;

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
        j=j+2;
    }
}



void choque_contendientes(){

}

void Puntaje_campeon(){

}

void mostrar_llave(ArbolBinarioInverso* arbol){

    int i =arbol->size;
    while (i != 1 ){
        int j = 0;
        for (int k = 0 ; k<i/2 ;k++){
            cout << arbol->arbol[j].content->id << ":" << arbol->arbol[j+1].content->id;
            cout << "\t";
            j=j+2;
        }
        cout << endl;
        i=i/2;
    }
    cout << "ganador";
}

void mostrar_contendientes(){

}

void calc_puntaje(){

}
void Ingre_ganador(int id){

    calc_puntaje();
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
    int opcion_seleccionada = 0;

    do{
        opcion_seleccionada = menu_B();

        switch(opcion_seleccionada)
        {
            case 1: //configuracion de juego
                break;
            case 2:
                break;
            case 3:
                break;
            case 4: //salir
                mostrar_llave(arbol);
                break;
            case 5: //salir
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
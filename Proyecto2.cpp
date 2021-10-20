//#include <iostream>
//#include <string>
//#include <cstdlib>
//#include <fstream>

//using namespace::std;

//void configurar_torneo(string nombre, ){

//}

//Bibliotecas a usar en el menu
#include <iostream>
#include <string>
using namespace std;

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
    cin >> b;
    return b;
}

//FUNCION PRINCIPAL
int main(){
    int opcion_seleccionada = 0;

    do{
        opcion_seleccionada = menu_A;

        switch(opcion_seleccionada)
        {
            case 1: //configuracion de juego

            case 2: //admi de contendientes -> funcion menu B

            case 3: //acerca de

            case 4: //salir
        }
    }while(opcion_seleccionada != 5);
    

}
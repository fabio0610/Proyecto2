
//Bibliotecas a usar en el menu
#include <iostream>
#include <string>
using namespace std;

void admin_contendientes(int contendiente, int puntaje){


}

void Ingre_ganador(int id){
     
    admin_contendientes(contendiente);
    calculo_puntaje(puntaje, ganador, perdedor);

    calc_puntaje();
}

void choque_contendientes(int id1, int id2){

    mostrar_llave();

}

void Puntaje_campeon(int id ){

    choque_contendientes(id1, id2);
}

void mostrar_llave(){

}

void mostrar_contendientes(){

    admin_contendientes();

}

void calculo_puntaje(int puntaje, int perdedor, int ganador){
    admin_contendientes(contendiente, puntaje);

}

void calc_puntaje(){

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



void menu1(){
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

    do{
        opcion_seleccionada = menu_A();

        switch(opcion_seleccionada)
        {
            case 1: //configuracion de juego
                break;

            case 2: //admi de contendientes -> funcion menu B

                menu1();
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
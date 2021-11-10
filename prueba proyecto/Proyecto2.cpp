//Bibliotecas a usar en el menu
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <bits/stdc++.h>
#include "ArbolBinario.h"
using namespace std;

//declaración de funciones
vector<Equipo*> Equipos;
bool verificador(ArbolBinarioInverso* arbol,int i);
bool checkrep(int n, int num[], ArbolBinarioInverso* arbol);
void admin_contendientes(ArbolBinarioInverso* arbol);
int calc_puntaje(ArbolBinarioInverso* arbol, int id);
void Ingre_ganador(ArbolBinarioInverso* arbol,int Id);
void choque_contendientes(ArbolBinarioInverso* arbol, int Id1, int Id2);
void Puntaje_campeon(ArbolBinarioInverso* arbol,int Id);
void mostrar_llave(ArbolBinarioInverso* arbol);
void bubbleSort();
void mostrar_contendientes();


/* 
-Funcion para la verificacion dentro del arbol
-Objetivo: A la funcion toma el entero y realiza verificacion
-Se ingresa en la funcion un puntero al arbol binario inverso y un entero
*/
bool verificador(ArbolBinarioInverso* arbol,int i){
    bool ver=false;
    if(i>0&&i<=arbol->size){
        ver= true;
    }else{
        ver=false;
    }
    return ver;
}

/* 
-Funcion para la revision de repeticion
-Objetivo: La funcion se usa para verificar si el numero entero que ingresa no sea repetido
-Se ingresa en la funcion un puntero al arbol binario inverso, un entero y un vector
*/
bool checkrep(int n, int num[], ArbolBinarioInverso* arbol)//se recibe un entero un vector y un puntero a arbol binario
{
    for(int i=0; i<arbol->size; i++)
        if(n == num[i]) // se recorre el vector y se verifica que el numero ingresado sea igual a alguna posicion del vector
            return true;
    return false;
}

/* 
-Funcion para la adminitracion de contendientes
-Objetivo: A la funcion toma los equipos, se pide la cantidad de equipos 
-Se ingresa en la funcion un puntero al arbol binario inverso y un entero
*/
void admin_contendientes(ArbolBinarioInverso* arbol){
    srand(time(NULL));//Es el encargado de que la funcion rand sea aleatoria siempre
    int vec[arbol->size];//vector
    int puntaje=0;
    int id=0;
    string nombre=" ";
    int j=0;
    
    /*for se va a repetir hasta que el arbol complete el tama�o asignado y este lo
	va a recorrer de 2 en 2 para la asignacion de las propiedades seg�n como estan en el constructor
    */
	for (int k = 0 ; k<(arbol->size)/2 ;k++) {
    	//primer equipo, se le coloca un papdre
        cout << "Ingrese el nombre del equipo" << endl;
        cin >> nombre;
        cout << "Ingrese el puntaje del equipo" << endl;
        cin >> puntaje;
        
        //Para que simepre se generen un id unico, entre 1 y el tama�o de arbol
		do
            id = 1 + rand() % arbol->size;
        while (checkrep(id, vec, arbol));
        vec[j] = id;
        
        //Asignacion de las variables ingresadas a cada uno de los atribujos correspondientes 
        arbol->arbol[j].content->id = id;
        arbol->arbol[j].content->Name = nombre;
        arbol->arbol[j].content->puntaje = puntaje;
        Equipos.push_back(arbol->arbol[j].content);
        
		//se crear el segundo equipo y va a tener el mismo papdre que el anterior
        cout << "Ingrese el nombre del equipo" << endl;
        cin >> nombre;
        cout << "Ingrese el puntaje del equipo" << endl;
        cin >> puntaje;
        
        // para que simepre se generen un id unico y entre 1 y el tama�o de arbol
        do
            id = 1 + rand() % arbol->size;
        while (checkrep(id, vec, arbol));
        vec[j + 1] = id;
        /*Asignacion de las variables ingresadas a cada uno de los atributos correspondientes*/
        arbol->arbol[j + 1].content->id = id;
        arbol->arbol[j + 1].content->Name = nombre;
        arbol->arbol[j + 1].content->puntaje = puntaje;
        Equipos.push_back(arbol->arbol[j+1].content);
        //Para que el j cambie y siga llenandose el arbol
        j=j+2;
    }
}

/* 
-Funcion de calcular puntaje 
-Objetivo: Se calcula el nuevo puntaje del ganador, y se acumulará
durante cada torneo
-Se ingresa en la funcion un puntero al arbol binario inverso y un entero
*/
int calc_puntaje(ArbolBinarioInverso* arbol, int id){
int Nuevo_puntaje; // Se crea el entero que almacenará el calculo de nuevo pntaje
if(arbol->arbol[id].parent == arbol->arbol[id+1].parent) { // se hace la verificación si "id" y "id +1 " poseen el mismo "papá"
    Nuevo_puntaje = arbol->arbol[id].content->puntaje + (1 + (arbol->arbol[id+1].content->puntaje)/arbol->arbol[id].content->puntaje); // de ser ese el caso se hace el recalculo de puntaje tomando como quipo perdedor "id + 1"
}else if(arbol->arbol[id-1].parent == arbol->arbol[id].parent){// se hace la verificación si "id" y "id -1 " poseen el mismo "papá"
    Nuevo_puntaje = arbol->arbol[id].content->puntaje + (1 + (arbol->arbol[id-1].content->puntaje)/arbol->arbol[id].content->puntaje); // de ser ese el caso se hace el recalculo de puntaje tomando como quipo perdedor "id - 1"
}
    return Nuevo_puntaje; // se retorna el nuevo puntaje calculado
}

/* 
-Funcion para ingresar ganador de partida
-Objetivo: Mueve a la siguiente fase al equipo que se ingrese como ganador y se vuelve a calular 
el puntaje
-Se ingresa en la funcion un puntero al arbol binario inverso y un entero
*/
void Ingre_ganador(ArbolBinarioInverso* arbol,int Id) {
    // se crean las variables a utilizar
    int i = arbol->size;
    int j = 0;
    int n = 1;
    Nodo <Equipo> *nodo1;
    Nodo <Equipo> *nodo2;
    Equipo *parent1;
    Equipo *parent2;

// se inicia la lógica de recorrido del arbol
    while (i != 1) { // el while verificará que "i" sea disitnto de 1
        for (int k = 0; k < i/2 ; k++) { //for para recorrer el arbol de 2 en 2
            if (i <= (arbol->size) / 4) { // en caso de que "i" sea menor que el tamaño del arbol entre 4 ejecuta lo que posee el if
                // los nodos tipo equipo se les asignan los parents de los arboles en la posición "j" y "j+2"
                nodo1 = arbol->arbol[j].parent;
                nodo2 = arbol->arbol[j + 2].parent;
                for (int m = 0; m < n; m++) { // es el encargado de subir de nivel en el arbol
                    // se asigna en los nodos el papá del papá
                    nodo1 = nodo1->parent;
                    nodo2 = nodo2->parent;
                }
                n++; // se aumenta en 1 a n
            } else if (i == (arbol->size) / 2) {// en caso de que "i" sea menor que el tamaño del arbol entre 2 ejecuta lo que posee el if
                // los nodos tipo equipo se les asignan los parents de los arboles en la posición "j" y "j+2"
                nodo1 = arbol->arbol[j].parent;
                nodo2 = arbol->arbol[j + 2].parent;
                // aqui primero se verifica que los nodos no esten nulos
                if (nodo1 != NULL || nodo2 != NULL) {
                    if (nodo1->parent == NULL) {// se verifica que el padre del nodo sea nulo
                            if (nodo1->content->id == Id) { // de ser el caso se verifica que el id sea igual al id ingresado por parametro
                                nodo1->parent = new Nodo<Equipo>; // se inicializa el padre del nodo
                                if (verificador(arbol,nodo1->parent->content->id) == false) {//se verficia que el "id" del padre inicializado esté entre los id's validos
                                nodo1->parent->content = nodo1->content; // se le asigna al padre el contenido del nodo
                            }
                        }
                    }
                    // para este caso se hace exactemente lo mismo que se explicó para el nodo1 pero para el nodo 2
                    if (nodo2->parent == NULL) {
                        if (nodo2->content->id== Id) {
                                nodo2->parent = new Nodo<Equipo>;
                            if (verificador(arbol, nodo2->parent->content->id) == false) {
                                nodo2->parent->content = nodo2->content;
                            }
                        }
                    }
                }
            }else {// de no cumplirse que i sea menor que el tamaño del arbol entre 4 o entre 2 entonces entra este else
                // se asigna a nodo1 y nodo2 la referencia del arbol en la posición j y j+1
                nodo1 = &arbol->arbol[j];
                nodo2 = &arbol->arbol[j + 1];
                if (verificador(arbol,nodo1->parent->content->id) == false) { // se verifica que el id que contiene el padre del nodo no esté entre los id's permitidos
                    if (nodo1->content->id == Id) {// se verifica que el id del contenido sea igual alingresado por parámetro
                        nodo1->parent=new Nodo<Equipo>;// se inicializa el padre
                        nodo1->parent->content = nodo1->content; // se le asigna el contenido del nodo al padre

                    }
                }
                // se hace exactamente el mismo proceso pero para el nodo2
                if (verificador(arbol,nodo2->parent->content->id)==false) {
                    if (nodo2->content->id== Id) {
                        nodo2->parent=new Nodo<Equipo>;
                        nodo2->parent->content=nodo2->content;

                    }
                }
            }


            if (i  <arbol->size){// si "i" es menor que arbol size entonces j aumenta en 4 si no este aumenta en 2
                j = j + 4;
            }else{
                j = j + 2;
            }
        }
        j = 0; //se reinicia j
        i = i / 2; // se va disminuyendo i en su mitad
    }
    calc_puntaje(arbol, Id); // se hace recálculo de puntaje
}

/* 
-Funcion de Choque de contendientes
-Objetivo: Se enfrentan los dos equipos ingresados, se realizan los partidos que se deban hasta que choquen.
-Se ingresa en la funcion un puntero al arbol binario inverso y un entero (ID del primer equipo) 
y el (ID del segundo)
*/
void choque_contendientes(ArbolBinarioInverso* arbol, int Id1, int Id2){
    /* Como se explico en el método de Ingre_ganador
     * la lógica que se encuentra de recorrido del arbol
    */
    srand(time(NULL));//linea encargada de escoger aleatorio siempre
    int i = arbol->size;
    int j = 0;
    int n = 1;
    int numero=0;
    Nodo <Equipo> *nodo1;
    Nodo <Equipo> *nodo2;
    Equipo *parent1;
    Equipo *parent2;


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
                if(nodo1->content->id==Id1||nodo1->content->id==Id2||nodo2->content->id==Id1||nodo2->content->id==Id2){// se verifica que alguno de los nodos tenga los id's ingresados por parametros
                    if((nodo1->content->id==Id1&&nodo2->content->id==Id2)||(nodo1->content->id==Id2&&nodo2->content->id==Id1)){// se verifica que los nodos 1 y 2 tengan los id's ingresados
                        mostrar_llave(arbol); //de ser el caso se muestra el arbol donde los contendientes estan en el choque entre si
                        break;
                    }else{
                        //de no entrar se le dice al programa que ambos equipos ganen los partidos que estén jugando
                        Ingre_ganador(arbol, Id1);
                        Ingre_ganador(arbol, Id2);
                    }
                }else{//se ser el caso que sea un partido en el que no estén ni id1 ni id2
                    // se hace que aleatoriamente se escoja un ganador
                    numero=1 + rand() % 100;
                    if(numero%2==0){
                        Ingre_ganador(arbol, j);
                    }else{
                        Ingre_ganador(arbol, j+2);
                    }
                }
            }else {
                //se hace el mismo procedimiento que arriba solo que para el nivel más bajo del arbol
                nodo1 = &arbol->arbol[j];
                nodo2 = &arbol->arbol[j + 1];
                if(nodo1->content->id==Id1||nodo1->content->id==Id2||nodo2->content->id==Id1||nodo2->content->id==Id2){
                    if((nodo1->content->id==Id1&&nodo2->content->id==Id2)||(nodo1->content->id==Id2&&nodo2->content->id==Id1)){
                        mostrar_llave(arbol);
                        break;
                    }else{
                        Ingre_ganador(arbol, Id1);
                        Ingre_ganador(arbol, Id2);
                    }
                }else{
                    numero=1 + rand() % 100;
                    if(numero%2==0){
                        Ingre_ganador(arbol, j);
                    }else{
                        Ingre_ganador(arbol, j+1);
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

/* 
-Funcion para el puntaje más alto
-Objetivo: Calcula el puntaje más alto usando un cualquier equipo como ganador
-Se ingresa en la funcion un puntero al arbol binario inverso y un entero (equipo para la simulacion)
*/
void Puntaje_campeon(ArbolBinarioInverso* arbol,int Id){
    /* Como se explico en el método de Ingre_ganador
        * la lógica que se encuentra de recorrido del arbol
       */
    srand(time(NULL));
    int i = arbol->size;
    int j = 0;
    int n = 1;
    int numero=0;
    Nodo <Equipo> *nodo1;
    Nodo <Equipo> *nodo2;
    Equipo *parent1;
    Equipo *parent2;


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
                if(nodo1->content->id==Id||nodo2->content->id==Id){// se verifica que el id ingresado sea igual que el que contiene nodo1 o nodo2
                    Ingre_ganador(arbol, Id); //de ser el caso se hace el id ganador

                }else{//de haber un enfrentamieto que no esté presnete id se eligente un ganador aleatorio
                    numero=1 + rand() % 100;
                    if(numero%2==0){
                        Ingre_ganador(arbol, j);
                    }else{
                        Ingre_ganador(arbol, j+2);
                    }
                }
            }else {
                nodo1 = &arbol->arbol[j];
                nodo2 = &arbol->arbol[j + 1];
                // se presente la misma lógica pero para el primer nivel
                if(nodo1->content->id==Id||nodo2->content->id==Id){
                        Ingre_ganador(arbol, Id);

                }else{
                    numero=1 + rand() % 100;
                    if(numero%2==0){
                        Ingre_ganador(arbol, j);
                    }else{
                        Ingre_ganador(arbol, j+1);
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


/* 
-Funcion para mostrar el arbol o la llave del torneo
-Objetivo: Muestra en pantalla el arbol actual del torneo y sus equipos
-Se ingresa en la funcion un puntero al arbol binario inverso
*/
void mostrar_llave(ArbolBinarioInverso* arbol){
    /* Como se explico en el método de Ingre_ganador
        * la lógica que se encuentra de recorrido del arbol
       */
    int i = arbol->size;
    int n = 1;
    int j = 0;
    for (int k = 0 ; k<i/2 ;k++){
        cout << arbol->arbol[j].content->id << ":" << arbol->arbol[j+1].content->id;//se imprime el primer nivel del arbol
        cout << "\t";
        j=j+2;//se aumenta a j en 2
    }
    cout << endl;
    cout<<"  ";
    i=i/2;//se disminuye i a la mitad
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
                if (nodo1 ==NULL&& nodo2==NULL){ //en caso de que ambos sean nulos se imprime que no hya info en ambos espacios
                    cout<<"N/A"<<":"<<"N/A";
                    cout << "\t";
                    //luego se verifica si solo uno de los 2 es nulo entonces se imprime que no hay info en uno y en el otro se imprime el id
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
                // aqui se aplica exactmaente la misma logica explicada anteriormente para imprimir el ultimo
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
// se imprime el padre total del arbol
    if(nodo1== NULL || nodo2==NULL){
        cout<<"N/A";
        cout << "\t";
    }else{
        if(nodo1 != NULL || nodo2 != NULL){
            cout<<nodo1->content->id;
            cout << "\t";
        }

    }

    cout<<endl;
}


//se implementa un ordenamiento de burbuja para el vector
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

/* 
-Funcion para mostrar contendientes
-Objetivo: muestra todos los equipos en orden y los puntos de cada equipo
*/
void mostrar_contendientes(){
    bubbleSort();// se ordenan los equipos conforme a su puntaje
    cout<<"Lista contendientes:"<<endl;
    for (auto const &i: Equipos) {
        cout <<"El nombre del equipo es:"<< i->Name << endl;
        cout <<"El id del equipo es:"<< i->id << endl;
        cout <<"El el puntjae del equipo es:"<< i->puntaje << endl;
        cout << endl<<endl<<endl;
    }
}

//acerca de
//Informacion sobre el proyecto
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
//Llenado de arbol
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
//Menu con el arbol lleno
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

//Menu con el arbol lleno
void menu1(ArbolBinarioInverso* arbol){
    int id=0, id2=0;
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
                cout<<"Ingrese el primer ID "<<endl;
                cin>>id;
                cout<<"Ingrese el segundo ID "<<endl;
                cin>>id2;
                choque_contendientes(arbol, id, id2);
                break;
            case 3:
                cout<<"Ingrese el ID del equipo que simule ser ganador"<<endl;
                cin>>id;
                Puntaje_campeon(arbol, id);
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

//Funion del menu para llenar el arbol
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

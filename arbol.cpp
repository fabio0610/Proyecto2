#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	
};

//prototipos
void menu();
Nodo *crearNodo(int );
void insertarNodo(Nodo *&,int);
void mostrarArbol(Nodo *&,int);

Nodo *arbol = NULL;


int main(){
	menu();
	getch();
	return 0;
	
}

//funcion de menu
void menu(){
	int dato, opcion, contador=0;
	do{
		cout<<"\t.:MENU:."<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2.Mostrar arbol"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"\nDigite un numero ";
				cin>>dato;
				insertarNodo(arbol,dato);//insertar un nuevo nodo
				cout<<"\n";
				system("pause");
				break;
			
			case 2:
				cout<<"\nMostrando el arbol completo:\n\n";
				mostrarArbol(arbol, contador);
				cout<<"\n";
				system("pause");
				break;
			
		}
		system("cls");
	}while(opcion!=3);
}

//funion para crear un nodo
Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	
	return nuevo_nodo;
	
}

//funcion para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol, int n){
	if(arbol == NULL){//Si el arbol esta vacio
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
		
	}
	else{//Si el arbol tiene un nodo o mas 
		int valorRaiz = arbol->dato;// Obtenemos el valor de la raiz
		if(n < valorRaiz){//Si el elemento  es menor a la raiz, insertamos en izquierda 
			insertarNodo(arbol->izq, n);
			
		}
		else{//Si el elemento  es mayor a la raiz, insertamos en derecha 
			insertarNodo(arbol->der, n);
		}
		
	}
}

//Funcion para mostrar el arbol oompleto
void mostrarArbol(Nodo *&arbol, int cont){
	if(arbol == NULL){//Si el arbol esta vacio
		
		return;
	}
	else{
		mostrarArbol(arbol->der, cont+1);
		for(int i=0; i<cont; i++){
			cout<<"    ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq, cont+1);
		
	}
}





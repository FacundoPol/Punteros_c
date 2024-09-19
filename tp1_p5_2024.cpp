#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	float valor;
	pnodo sig;
};

void menu_opciones(int &op);
void menu(int op,pnodo &lista);
void iniciar_lista(pnodo &lista);
void crear_nodo(pnodo &nuevo);
void agregar_inicio(pnodo &lista,pnodo &nuevo);
float sumar_lista(pnodo lista);
float maximo_lista(pnodo lista);
void mostrar_recursivo(pnodo lista);


main()
{
	pnodo lista;
	int op;
	iniciar_lista(lista);
	do
	{
		menu_opciones(op);
		menu(op,lista);
		system("pause");
		system("cls");
	}while(op!=0);
}
void menu_opciones(int &op)
{
	cout<<"-- MENU --"<<endl;
	cout<<"|1| AGREGAR INICIO"<<endl;
	cout<<"|2| SUMAR LISTA"<<endl;
	cout<<"|3| MAXIMO LISTA"<<endl;
	cout<<"|4| MOSTRAR LISTA"<<endl;
	cout<<"|0| SALIR"<<endl;
	cout<<"INGRESE OPCION: ";
	cin>>op;
	cout<<endl;
}
void menu(int op,pnodo &lista)
{
	pnodo nuevo;
	switch(op)
	{
	case 1:
		crear_nodo(nuevo);
		agregar_inicio(lista,nuevo);
		break;
	case 2:
		cout<<"La suma de todos los elementos es: "<<sumar_lista(lista)<<endl;
		break;
	case 3:
		cout<<"El elemnto mas grande es: "<<maximo_lista(lista)<<endl;
		break;
	case 4:
		mostrar_recursivo(lista);
		break;
	default:
		cout<<"SALISTE"<<endl;
	}
}
void iniciar_lista(pnodo &lista)
{
	lista=NULL;
}
void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	cout<<"Ingrese valor: ";
	cin>>nuevo->valor;
	nuevo->sig=NULL;
}
void agregar_inicio(pnodo &lista,pnodo &nuevo)
{
	bool repetido=false;
	pnodo i;
	if(lista==NULL)
	{
		lista=nuevo;
	}
	else
	{
		for(i=lista;i!=NULL && repetido==false;i=i->sig)
		{
			if(i->valor == nuevo->valor)
				repetido=true;
		}
		if(repetido!=true)
		{
			nuevo->sig=lista;
			lista=nuevo;
		}
		else
		{
			delete(nuevo);
			nuevo=NULL;
		}
	}
}
float sumar_lista(pnodo lista)
{
	pnodo i;
	float suma=0;
	for(i=lista;i!=NULL;i=i->sig)
	{
		suma = suma + i->valor;
	}
	return suma;
}
float maximo_lista(pnodo lista)
{
	pnodo i;
	float maximo;
	maximo=lista->valor;
	for(i=lista;i!=NULL;i=i->sig)
	{
		if(i->valor>maximo)
			maximo=i->valor;
	}
	return maximo;
}
void mostrar_recursivo(pnodo lista)
{
	if(lista==NULL)
		cout<<"Lista Vacia"<<endl;
	else
	{
		if(lista->sig==NULL)
			cout<<lista->valor;
		else
		{
			mostrar_recursivo(lista->sig);
			cout<<lista->valor;
		}
	}
	cout<<endl;
}

#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	char dato;
	pnodo sig;
};
typedef struct tlista{
	pnodo inicio;
	int cantidad;
};
void menu_opciones(int &op);
void menu(tlista &lista,int op);
void iniciar_lista(tlista &lista);
void crear_nodo(pnodo &nuevo);
void agregar_inicio(tlista &lista,pnodo nuevo);
void agregar_final(tlista &lista,pnodo nuevo);
void ordenacion_seleccion(tlista lista);
void intercambio(char &a,char &b);
void liberar_nodos(pnodo &lista);
void mostrar_recursivo(pnodo lista);

main()
{
	tlista lista;
	int op;
	iniciar_lista(lista);
	do{
		menu_opciones(op);
		menu(lista,op);
		system("pause");
		system("cls");
	}
	while(op!=0);
}
void menu_opciones(int &op)
{
	cout<<"-- MENU --"<<endl;
	cout<<"|1| AGREGAR AL INICIO"<<endl;
	cout<<"|2| AGREGAR AL FINAL"<<endl;
	cout<<"|3| ORDENACION CRECIENTE"<<endl;
	cout<<"|4| LIBERAR NODOS"<<endl;
	cout<<"|5| MOSTRAR LISTA"<<endl;
	cout<<"|0| SALIR"<<endl;
	cout<<endl;
	cout<<"Ingrese opcion: ";
	cin>>op;
}

void menu(tlista &lista,int op)
{
	pnodo nuevo;
	switch(op)
	{
	case 1:
		crear_nodo(nuevo);
		agregar_inicio(lista,nuevo);
		break;
	case 2:
		crear_nodo(nuevo);
		agregar_final(lista,nuevo);
		break;
	case 3:
		ordenacion_seleccion(lista);
		break;
	case 4:
		liberar_nodos(lista.inicio);
		lista.cantidad=0;
		break;
	case 5:
		mostrar_recursivo(lista.inicio);
		cout<<endl;
		cout<<"Cantidad: "<<lista.cantidad<<endl;
		break;
	case 0:
		cout<<"SALISTE"<<endl;
		break;
	}
}
void iniciar_lista(tlista &lista)
{
	lista.inicio=NULL;
	lista.cantidad=0;
}
void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	cout<<"INGRESE EL CARACTER: ";
	cin>>nuevo->dato;
	nuevo->sig=NULL;
}
void agregar_inicio(tlista &lista,pnodo nuevo)
{
	if(lista.inicio==NULL)
	{
		lista.inicio=nuevo;
		lista.cantidad++;
	}
	else
	{
		nuevo->sig=lista.inicio;
		lista.inicio=nuevo;
		lista.cantidad++;
	}
}

void agregar_final(tlista &lista,pnodo nuevo)
{
	pnodo i;
	if(lista.inicio==NULL)
	{
		lista.inicio=nuevo;
		lista.cantidad++;
	}
	else
	{
		for(i=lista.inicio;i->sig!=NULL;i=i->sig);
		i->sig=nuevo;
		lista.cantidad++;
	}
}

void ordenacion_seleccion(tlista lista)
{
	pnodo i,j;
	for(i=lista.inicio;(i->sig)->sig!=NULL;i=i->sig)
	{
		for(j=i->sig;j->sig!=NULL;j=j->sig)
		{
			if(i->dato>j->dato)
			{
				intercambio(i->dato,j->dato);
			}
		}
	}
}

void intercambio(char &a,char &b)
{
	char aux;
	aux=a;
	a=b;
	b=aux;
}

void liberar_nodos(pnodo &lista)
{
	if(lista==NULL)
		cout<<"LISTA VACIA"<<endl;
	else
	{
		if(lista->sig==NULL)
		{
			delete(lista);
			lista=NULL;
		}
		else
		{
			liberar_nodos(lista->sig);
			delete(lista);
			lista=NULL;
		}
	}
}
void mostrar_recursivo(pnodo lista)
{
	if(lista==NULL)
		cout<<"LISTA VACIA"<<endl;
	else
	{
		if(lista->sig==NULL)
			cout<<lista->dato<<endl;
		else
		{
			cout<<lista->dato<<endl;
			mostrar_recursivo(lista->sig);
		}
	}
}

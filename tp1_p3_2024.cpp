#include <iostream>

using namespace std;

const int limite=3;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	int dato;
	pnodo sig;
};
typedef struct tlista{
	pnodo inicio;
	int impares;
	int pares;
};

void menu_opciones(int &op);
void menu(tlista &lista,int op);
void iniciar_lista(tlista &lista);
void crear_nodo(pnodo &nuevo);
void agregar_inicio(tlista &lista,pnodo nuevo);
pnodo quitar_inicio(tlista &lista);
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
	cout<<"|2| ELIMINAR DEL INICIO"<<endl;
	cout<<"|3| MOSTRAR LISTA"<<endl;
	cout<<endl;
	cout<<"Ingrese opcion: ";
	cin>>op;
}
void menu(tlista &lista,int op)
{
	pnodo nuevo,extraido;
	switch(op)
	{
	case 1:
		crear_nodo(nuevo);
		agregar_inicio(lista,nuevo);
		break;
	case 2:
		extraido=quitar_inicio(lista);
		if(extraido==NULL)
		{
			cout<<"LISTA VACIA"<<endl;
		}
		else
		{
			cout<<"El extraido es: "<<extraido->dato<<endl;
		}
		break;
	case 3:
		mostrar_recursivo(lista.inicio);
		break;
	case 0:
		cout<<"SALISTE"<<endl;
		break;
	}
}
void iniciar_lista(tlista &lista)
{
	lista.inicio=NULL;
	lista.pares=0;
	lista.impares=0;
}
void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		cout<<"Ingrese el dato: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
	}
	else
	{
		cout<<"NO HAY MEMORIA SUFICIENTE"<<endl;
	}
}
void agregar_inicio(tlista &lista,pnodo nuevo)
{
	if(lista.pares+lista.impares < limite)
	{
		nuevo->sig=lista.inicio;
		lista.inicio=nuevo;
		if(nuevo->dato/2==0)
		{
			lista.pares++;
		}
		else
		{
			lista.impares++;
		}
	}
	else
	{
		cout<<"No se pueden agregar mas"<<endl;
		delete(nuevo);
		nuevo=NULL;
	}
}
pnodo quitar_inicio(tlista &lista)
{
	pnodo extraido;
	if(lista.inicio==NULL)
	{
		extraido=NULL;
	}
	else
	{
		extraido=lista.inicio;
		lista.inicio=extraido->sig;
		extraido->sig=NULL;
		if(extraido->dato/2==0)
		{
			lista.pares--;
		}
		else
		{
			lista.impares--;
		}
	}
	return extraido;
}
void mostrar_recursivo(pnodo lista)
{
	if(lista==NULL)
	{
		cout<<"LISTA VACIA"<<endl;
	}
	else
	{
		if(lista->sig==NULL)
		{
			cout<<lista->dato;
		}
		else
		{
			cout<<lista->dato<<endl;
			mostrar_recursivo(lista->sig);
		}
	}
	cout<<endl;
}

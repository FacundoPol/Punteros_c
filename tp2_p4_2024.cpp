#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	int dato;
	pnodo sig;
};

typedef struct tlista{
	pnodo inicio;
	pnodo lfinal;
};

void mostrar(pnodo i,pnodo f);
void invertir_lista(tlista &lista,tlista &lista2);
bool repetido(tlista lista);
void agregar_inicio(tlista &lista,pnodo nuevo);
void crear_nodo(pnodo &nuevo);
void iniciar_lista(tlista &lista);
void menu_op(int op,tlista &lista,tlista &lista2);
void menu(int &op);
void copiar_lista(tlista lista,tlista lista2);
void lista_invertida(tlista &lista);
main()
{
	int op;
	tlista lista,lista2;
	iniciar_lista(lista);
	iniciar_lista(lista2);
	do
	{
		menu(op);
		menu_op(op,lista,lista2);
		system("pause");
		system("cls");
	}while(op!=0);
}

void menu(int &op)
{
	cout<<"--MENU--"<<endl;
	cout<<"|1| AGREGAR INICIO"<<endl;
	cout<<"|2| REPETIDO"<<endl;
	cout<<"|3| INVERTIR LISTA"<<endl;
	cout<<"|4| CREAR COPIA"<<endl;
	cout<<"|5| MOSTRAR"<<endl;
	cout<<"INGRESE SU OPCION: ";
	cin>>op;
}

void menu_op(int op,tlista &lista,tlista &lista2)
{
	pnodo nuevo;
	switch(op)
	{
	case 1:
		crear_nodo(nuevo);
		agregar_inicio(lista,nuevo);
		break;
	case 2:
		if(repetido(lista)==true)
			cout<<"Hay un elemento repetido"<<endl;
		else
			cout<<"No hay un elemento repetido"<<endl;
		break;
	case 3:
		//invertir_lista(lista,lista2);
		lista_invertida(lista);
		mostrar(lista.inicio,lista.lfinal);
		break;
	case 4:
		copiar_lista(lista,lista2);
		break;
	case 5:
		mostrar(lista.inicio,lista.lfinal);
		break;
	}
}

void iniciar_lista(tlista &lista)
{
	lista.inicio=NULL;
	lista.lfinal=NULL;
}

void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		cout<<"INGRESE DATOS: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
	}
	else
	   cout<<"NO HAY MEMORIA SUFICIENTE"<<endl;
}

void agregar_inicio(tlista &lista,pnodo nuevo)
{
	if(lista.inicio==NULL)
	{
		lista.inicio=nuevo;
		lista.lfinal=nuevo;
	}
	else
	{
		nuevo->sig=lista.inicio;
		lista.inicio=nuevo;
	}
}

bool repetido(tlista lista)
{
	bool repetido=false;
	pnodo i,j;
	i=lista.inicio;
	while(i!=NULL)
	{
		for(j=i->sig;j!=NULL;j=j->sig)
		{
			if(i->dato==j->dato)
				repetido=true;
		}
		i=i->sig;
	}
	return repetido;
}

void invertir_lista(tlista &lista,tlista &lista2)
{
	pnodo i,nuevo;
	lista2.lfinal=lista.inicio;
	lista2.inicio=lista.inicio;
	for(i=lista.inicio->sig;i!=NULL;i=i->sig)
	{
		nuevo=new tnodo;
		nuevo->dato=i->dato;
		nuevo->sig=lista2.inicio;
		lista2.inicio=nuevo;
	}
	mostrar(lista2.inicio,lista2.lfinal);
}

void copiar_lista(tlista lista,tlista lista2)
{
	pnodo i,nuevo;
	lista2.inicio=lista.inicio;
	lista2.lfinal=lista.inicio;
	for(i=lista.inicio->sig;i!=NULL;i=i->sig)
	{
		nuevo=new tnodo;
		nuevo->dato=i->dato;
		lista2.lfinal->sig=nuevo;
		lista2.lfinal=nuevo;
	}
	lista2.lfinal->sig=NULL;
	mostrar(lista2.inicio,lista2.lfinal);
}
void mostrar(pnodo i,pnodo f)
{
	if(i==NULL)
		cout<<"LISTA VACIA"<<endl;
	else
	{
		if(i==f)
			cout<<i->dato<<endl;
		else
		{
			cout<<i->dato<<endl;
			mostrar(i->sig,f);
		}
	}
}

void lista_invertida(tlista &lista)
{
	pnodo i=NULL,aux;
	aux=new tnodo ;
	aux->sig=NULL;
	aux->dato=lista.inicio->dato;
	lista.inicio->dato=lista.lfinal->dato;
	lista.lfinal->dato=aux->dato;

	while(lista.inicio->sig!=i)
	{
		for(i=lista.inicio->sig;(i->sig)->sig!=aux->sig;i=i->sig)
		{
			aux->dato=i->dato;
			i->dato=(i->sig)->dato;
			(i->sig)->dato=aux->dato;
		}
			
		aux->sig=i->sig;
	}
}

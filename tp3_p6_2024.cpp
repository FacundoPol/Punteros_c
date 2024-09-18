#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	int dato;
	pnodo sig;
	pnodo ant;
};
typedef struct tlista{
	pnodo inicio;
	pnodo fin;
};
main()
{
	
}

void iniciar_lista(tlista &lista)
{
	lista.inicio=NULL;
}

void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		cout<<"INGRESE NUMERO: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
		nuevo->ant=NULL;
	}
}

void agregar_orden(tlista &lista,pnodo nuevo)
{
	pnodo i;
	if(lista.inicio==NULL)
	{
		lista.inicio=nuevo;
		nuevo->sig=lista.inicio;
		nuevo->ant=lista.inicio;
	}
	else
	{
		if(lista.inicio->dato>nuevo->dato)
		{
			nuevo->ant=lista.inicio->ant;
			nuevo->sig=lista.inicio;
			lista.inicio->ant=nuevo;
			lista.inicio=nuevo;
			(nuevo->ant)->sig=nuevo;
		}
		else
		{
			for(i=lista.inicio->sig;i->sig!=lista.inicio;i=i->sig);
			if(i->dato<nuevo->dato)
			{
				nuevo->sig=i->sig;
				nuevo->ant=i;
				i->sig=nuevo;
				(nuevo->sig)->ant=nuevo;
			}
			else
			{
				for(i=lista.inicio->sig;i!=lista.inicio&&i->dato<nuevo->dato;i=i->sig)
				{
					nuevo->sig=i;
					nuevo->ant=i->ant;
					i->ant=nuevo;
					(nuevo->ant)->sig=nuevo;
				}
			}
		}
	}
}

pnodo quitar_nodo(tlista &lista)
{
	
}

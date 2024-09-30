#include <iostream>

using namespace std;

typedef pnodo tpunteros[2];
typedef struct tnodo *pnodo;
typedef struct tnodo{
	char dato;
	tpunteros vecinos;
};

typedef struct tlista{
	tpunteros posicion;
	int contador;
};

main()
{
	
}

void iniciar_lista(tlista &lista)
{
	lista.posicion[0]=NULL;
	lista.posicion[1]=NULL;
	lista.contador=0;
}

void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		cout<<"Ingrese caracter: ";
		cin>>nuevo->dato;
		nuevo->vecinos[0]=NULL;
		nuevo->vecinos[1]=NULL;
	}
}

void agregar_final(tlista &lista,pnodo nuevo)
{
	if(lista_llena(lista)==false)
	{
		if(lista.posicion[0]==NULL)
		{
			lista.posicion[0]=nuevo;
			lista.posicion[1]=nuevo;
		}
		else
		{
			lista.posicion[1]->vecino[0]=nuevo;
			nuevo->vecino[1]=lista.posicion[1];
			lista.posicion[1]=nuevo;
		}
		lista.contador++;
	}
	else
	{
		cout<<"LISTA LLENA"<<endl;
	}
}

pnodo quitar_inicio(tlista &lista)
{
	pnodo extraido;
	if(lista.posicion[0]==NULL)
		extraido=NULL;
	else
	{
		extraido=lista.posicion[0];
		lista.posicion[0]=lista.posicion[0]->vecinos[0];
		lista.posicion[0]->vecinos[1]=NULL;
		extraido->vecino[0]=NULL;
		extraido->vecino[1]=NULL;
	}
	lista.contador--;
	return extraido;
}

bool lista_llena(tlista lista)
{
	if(lista.contador<=20)
	{
		return false;
	}
	else
	{
		return true;
	}
}

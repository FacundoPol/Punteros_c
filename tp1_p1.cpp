#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	char dato;
	pnodo sig;
};

void iniciar_lista(pnodo &lista);
void crear_nodo(pnodo &nuevo);
void agregar_inicio(pnodo &lista,pnodo nuevo);
void agregar_final(pnodo &lista,pnodo nuevo);
void agregar_orden(pnodo &lista,pnodo nuevo);


pnodo quitar_inicio(pnodo &lista);
pnodo quitar_final(pnodo &lista);


main()
{
	pnodo lista,nuevo;
	iniciar_lista(lista);
	crear_nodo(nuevo);
	if(nuevo!=NULL)
	{
		agregar_inicio(lista,nuevo);
		agregar_final(lista,nuevo);
		agregar_orden(lista,nuevo);
	}
	
}
void iniciar_lista(pnodo &lista)
{
	lista=NULL;
}
void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	if(nuevo != NULL)
	{
		cout<<"Ingrese caracter: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
	}
	else
	{
		cout<<"No hay memoria suficiente"<<endl;
	}
}
void agregar_inicio(pnodo &lista,pnodo nuevo)
{
	nuevo->sig=lista;
	lista=nuevo;
}
void agregar_final(pnodo &lista,pnodo nuevo)
{
	pnodo i;
	if(lista==NULL)
	{
		lista=nuevo;
	}
	else
	{
		for(i=lista;i->sig!=NULL;i=i->sig);
		i->sig=nuevo;
	}
	
}
void agregar_orden(pnodo &lista,pnodo nuevo)
{
	pnodo i;
	if(lista==NULL)
		lista=nuevo;
	else
	{
		if(nuevo->dato<lista->dato)
		{
			nuevo->sig=lista;
			lista=nuevo;
		}
		else
		{
			for(i=lista;nuevo->dato < (i->sig)->dato && i->sig!=NULL;i=i->sig);
			nuevo->sig=i->sig;
			i->sig=nuevo;
		}
	}
}
pnodo quitar_inicio(pnodo &lista)
{
	pnodo extraido;
	if(lista==NULL)
		extraido=NULL;
	else
	{
		extraido=lista;
		lista=lista->sig;
		extraido->sig=NULL;
	}
	
	return extraido;
}
pnodo quitar_final(pnodo &lista)
{
	pnodo extraido,i;
	if(lista==NULL)
	{
		extraido=NULL;
	}
	else
	{
		if(lista->sig==NULL)
		{
			extraido=lista;
			lista=NULL;
		}
		else
		{
			for(i=lista;(i->sig)->sig!=NULL;i=i->sig);
			extraido=i->sig;
			i->sig=NULL;
		}
	}
	return extraido;
}
pnodo quitar_especifico(pnodo &lista,char ingresado)
{
	pnodo extraido,i;
	
	if(lista==NULL)
		extraido=NULL;
	else
	{
		if(ingresado==lista->dato)
		{
			extraido=lista;
			lista=extraido->sig;
			extraido->sig=NULL;
		}
		else
		{
			for(i=lista;i->sig!=NULL && (i->sig)->dato!=ingresado;i=i->sig);
			if(i->sig!=NULL)
			{
				extraido=i->sig;
				i->sig=extraido->sig;
				extraido->sig=NULL;
			}
			else
			{
				extraido=NULL;
			}
		}
		
	}
	return extraido;
}


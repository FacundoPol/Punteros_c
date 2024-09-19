#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
	char dato;
	pnodo sig;
};



main()
{
	pnodo lista,nuevo;
	
}
void crear_lista(pnodo &lista)
{
	lista=NULL;
}
void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	if(nuevo != NULL)
	{
		cout<<"Ingrese numero: ";
		cin<<nuevo->dato;
		nuevo->sig=NULL;
	}
	else{
		cout<<"NO TIENE MEMORIA SUFICIENTE";
	}
}
void agregar_inicio(pnodo nuevo,pnodo &lista)
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
	{
		lista=nuevo;
	}
	else
	{
		if(nuevo->dato < lista->dato)
		{
			nuevo->sig=lista;
			lista=nuevo;
		}
		else
		{
			for(i=lista;nuevo->dato > (i->sig)->dato && i->sig!=NULL;i=i->sig);
			nuevo->sig=i->sig;
			i->sig=nuevo;
		}
	}
}
pnodo quitar_inicio(pnodo &lista)
{
	pnodo extraido;
	if(lista==NULL)
	{
		extraido=NULL;
	}
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
}
pnodo quitar_especifico(pnodo &lista,char ingresado)
{
	pnodo extraido,i;
	if(lista==NULL)
	{
		extraido=NULL;
	}
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
			   extraido=NULL;
		}
	}
	return extraido;
}
void mostrar_lista(pnodo lista)
{
	pnodo i;
	for(i=lista;i!=NULL;i=i->sig)
	{
		cout<<"Numero: "<<i->dato<<endl;
	}
	else
	{
		cout<<"Lista Vacia"<<endl;
	}
}
bool buscar_nodo(pnodo lista,char buscado)
{
	pnodo i;
	bool encontrado=false;
	if(lista!=NULL)
	{
		for(i=lista;i!=NULL && encontrado==false;i=i->sig)
		{
			if(i->dato==buscado)
			{
				encontrado=true;
			}
		}
	}
	return encontrado;
}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef char tcat [20];

typedef struct tnodo *pnodo;
typedef struct tnodo{
	tarticulo dato;
	pnodo sig;
};
typedef struct tarticulo{
	int codigo;
	tcat descripcion;
	tcat marca;
	float precio;
	int stock;
};
typedef tlista

main()
{
	
}

void iniciar_lista(pnodo &lista)
{
	lista=NULL;
}

void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		cout<<"Ingrese codigo de Articulo: ";
		cin>>dato.codigo;
		cout<<"Ingrese Descripcion de Articulo";
		gets(dato.descripcion);
		cout<<"Ingrese Marca de Articulo";
		gets(dato.marca);
		cout<<"Ingrese Precio de Articulo";
		cin>>dato.precio;
		cout<<"Ingrese Stock de Articulo";
		cin>>dato.stock;
		nuevo->sig=NULL;
	}
	else
	{
		cout<<"MEMORIA LLENA"<<endl;
	}
}

void agregar_inicio(pnodo &lista,pnodo nuevo)
{
	pnodo i;
	if(lista==NULL)
		lista=nuevo;
	else
	{
		for(i=lista;i->dato.codigo!=nuevo->dato.codigo&&i!=NULL;i=i->sig);
		if(i!=NULL)
		{
			i->dato.stock++;
			delete(nuevo);
			nuevo=NULL;
		}
		else
		{
			nuevo->sig=lista;
			lista=nuevo;
		}
	}
}

void buscar_marca(pnodo lista,tcat marca_b)
{
	pnodo i;
	for(i=lista;i<=NULL;i=i->sig)
	{
		if(strcmp(i->dato.marca,marca_b)==0)
		{
			cout<<"Marca: "<<i->dato.marca<<endl;
			cout<<"Descripcion: "<<i->dato.descripcion<<endl;
			cout<<"Stock: "<<i->dato.stock<<endl;
			cout<<"Precio: "<<i->dato.precio<<endl;
		}
	}
}

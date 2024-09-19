#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

typedef char tcad[30];
typedef struct tnodo *pnodo;
typedef struct tnodo{
	tcad palabra;
	int cant;
	pnodo sig;
};
typedef struct tlista{
	pnodo inicio;
	pnodo lfinal;
};

void m_op(int &op);
void menu_op(int op,tlista &lista);
void iniciar_lista(tlista &lista);
void crear_nodo(pnodo &nuevo);
void agregar_orden(tlista &lista,pnodo nuevo);
pnodo long_max(pnodo i,pnodo f);
void mostrar(pnodo i,pnodo f);

main()
{
	int op;
	tlista lista;
	iniciar_lista(lista);
	do
	{
		m_op(op);
		menu_op(op,lista);
		system("pause");
		system("cls");
	}while(op!=0);
}

void m_op(int &op)
{
	cout<<"-MENU-"<<endl;
	cout<<"|1|AGREGAR EN ORDEN"<<endl;
	cout<<"|2|MAXIMO"<<endl;
	cout<<"|3|MOSTRAR"<<endl;
	cout<<"INGRESE OPCION: ";
	cin>>op;
}

void menu_op(int op,tlista &lista)
{
	pnodo nuevo;
	switch(op)
	{
	case 1:
		crear_nodo(nuevo);
		agregar_orden(lista,nuevo);
		break;
	case 2:
		if(long_max(lista.inicio,lista.lfinal)!=NULL)
			cout<<long_max(lista.inicio,lista.lfinal)->cant<<" "<<long_max(lista.inicio,lista.lfinal)->palabra<<endl;
		else
			cout<<"LISTA VACIA"<<endl;
		break;
	case 3:
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
		cout<<"Ingrese la palabra: ";
		cin>>nuevo->palabra;
		nuevo->cant=strlen(nuevo->palabra);
		nuevo->sig=NULL;
	}
	else
	   cout<<"NO HAY MEMEORIA SUFICIENTE"<<endl;
}

void agregar_orden(tlista &lista,pnodo nuevo)
{
	pnodo i;
	bool repetido=false;
	if(lista.inicio==NULL)
	{
		lista.inicio=nuevo;
		lista.lfinal=nuevo;
	}
	else
	{
		if(lista.inicio->cant > nuevo->cant)
		{
			nuevo->sig=lista.inicio;
			lista.inicio=nuevo;
		}
		else
		{
			if(lista.lfinal->cant < nuevo->cant)
			{
				lista.lfinal->sig=nuevo;
				lista.lfinal=nuevo;
			}
			else
			{
				for(i=lista.inicio;i!=lista.lfinal&&nuevo->cant > (i->sig)->cant;i=i->sig)
				{
					if(strcmp(i->palabra,nuevo->palabra)==0)
						repetido=true;
				}
				if(repetido==false)
				{
					nuevo->sig=i->sig;
					i->sig=nuevo;
				}
				else
				{
					cout<<"PALABRA REPETIDA"<<endl;
					delete(nuevo);
					nuevo=NULL;
				}
			}
		}
	}
}

pnodo long_max(pnodo i,pnodo f)
{
	pnodo max;
	if(i==NULL)
		return NULL;
	else
	{
		if(i==f)
			return f;
		else
		{
			max=long_max(i->sig,f);
			if(i->cant>max->cant)
				max=i;
			return max;
		}
	}
}

void mostrar(pnodo i,pnodo f)
{
	if(i==NULL)
	{
		cout<<"LISTA VACIA"<<endl;
	}
	else
	{
		if(i==f)
			cout<<i->cant<<" "<<i->palabra<<endl;
		else
		{
			cout<<i->cant<<" "<<i->palabra<<endl;
			mostrar(i->sig,f);
		}
	}
}

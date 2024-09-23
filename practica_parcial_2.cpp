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
	int cant_par;
	int cant_impar;
};

void menu_opciones(int &op);
void menu(int op,tlista &lista);
void crear_lista(tlista &lista);
void crear_nodo(pnodo &nuevo);
void agregar_orden(tlista &lista,pnodo nuevo);
void mostrar_lista(pnodo i,pnodo f);

main()
{
	tlista lista;
	crear_lista(lista);
	int op;
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
	cout<<"|1| AGREGAR ORDEN"<<endl;
	cout<<"|3| MOSTRAR LISTA"<<endl;
	cout<<"INGRESE OPCION: ";
	cin>>op;
}

void menu(int op,tlista &lista)
{
	pnodo nuevo;
	switch(op)
	{
	case 1:
		crear_nodo(nuevo);
		agregar_orden(lista,nuevo);
		break;
	case 2:
		mostrar_lista(lista.inicio,lista.fin);
		cout<<"CANTIDAD PAR: "<<lista.cant_par<<endl;
		cout<<"CANTIDAD IMPAR: "<<lista.cant_impar<<endl;
		break;
	}
}



void crear_lista(tlista &lista)
{
	lista.inicio=NULL;
	lista.fin=NULL;
	lista.cant_par=0;
	lista.cant_impar=0;
}

void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	cout<<"INGRESE DATO: ";
	cin>>nuevo->dato;
	nuevo->sig=NULL;
	nuevo->ant=NULL;
}

void agregar_orden(tlista &lista,pnodo nuevo)
{
	pnodo i;
	if(lista.inicio==NULL)
	{
		lista.inicio=nuevo;
		lista.fin=nuevo;
	}
	else
	{
		if(lista.inicio->dato>nuevo->dato)
		{
			nuevo->sig=lista.inicio;
			lista.inicio->ant=nuevo;
			lista.inicio=nuevo;
		}
		else
		{
			if(lista.fin->dato<nuevo->dato)
			{
				nuevo->ant=lista.fin;
				lista.fin->sig=nuevo;
				lista.fin=nuevo;
			}
			else
			{
				for(i=lista.fin->ant;i!=NULL&&i->dato>nuevo->dato;i=i->ant);
				if(i!=NULL)
				{
					nuevo->ant=i;
					nuevo->sig=i->sig;
					i->sig=nuevo;
					(nuevo->sig)->ant=nuevo;
				}
			}
		}
		
	}
	
	if(nuevo->dato%2==0)
		lista.cant_par++;
	else
	   lista.cant_impar++;
}


void mostrar_lista(pnodo i,pnodo f)
{
	if(i==NULL)
	{
		cout<<"LISTA VACIA"<<endl;
	}
	else
	{
		if(i==f)
		{
			cout<<i->dato<<endl;
		}
		else
		{
			cout<<i->dato<<endl;
			mostrar_lista(i->sig,f);
		}
	}
}


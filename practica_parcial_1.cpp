#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	char dato;
	pnodo sig;
};

void m_op(int &op);
void menu(int op,pnodo &inicio);
void iniciar_lista(pnodo &inicio);
void crear_nodo(pnodo &nuevo);
void agregar_final(pnodo &inicio,pnodo nuevo);
bool buscar_repetido(pnodo inicio,pnodo nuevo);
void mostrar_lista(pnodo lista);
main()
{
	pnodo inicio;
	iniciar_lista(inicio);
	int op;
	do{
		m_op(op);
		menu(op,inicio);
	} while(op!=0);
}

void m_op(int &op)
{
	cout<<"|1|AGREGAR FINAL"<<endl;
	cout<<"|2|MOSTRAR"<<endl;
	cout<<"INGRESE OPCION: ";
	cin>>op;
}

void menu(int op,pnodo &inicio)
{
	pnodo nuevo;
	switch(op)
	{
	case 1:
		crear_nodo(nuevo);
		agregar_final(inicio,nuevo);
		break;
	case 2:
		mostrar_lista(inicio);
		break;
	}
}

void iniciar_lista(pnodo &inicio)
{
	inicio=NULL;
}

void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		cout<<"INGRESE CARACTER: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
	}
}

void agregar_final(pnodo &inicio,pnodo nuevo)
{
	pnodo i;
	if(inicio==NULL)
	{
		inicio=nuevo;
		nuevo->sig=inicio;
	}
	else
	{
		if(buscar_repetido(inicio,nuevo)==false)
		{
			for(i=inicio->sig;i->sig!=inicio;i=i->sig);
			nuevo->sig=i->sig;
			i->sig=nuevo;
		}
		else
		{
			cout<<"REPETIDO"<<endl;
			delete(nuevo);
			nuevo=NULL;
		}
	}
}

bool buscar_repetido(pnodo inicio,pnodo nuevo)
{
	pnodo i;
	bool rep=false;
	if(inicio->dato==nuevo->dato)
		rep=true;
	else
	{
		for(i=inicio->sig;i!=inicio&&i->dato!=nuevo->dato;i=i->sig);
		if(i==inicio)
			rep=false;
		else
		   rep=true;
	}
	return rep;
}

void mostrar_lista(pnodo lista)
{
	pnodo i;
	cout<<lista->dato<<endl;
		for(i=lista->sig;i!=lista;i=i->sig)
			cout<<i->dato<<endl;
}

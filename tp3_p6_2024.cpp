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

void m_op(int &op);
void menu(int op,tlista &lista);
void iniciar_lista(tlista &lista);
void crear_nodo(pnodo &nuevo);
void agregar_orden(tlista &lista,pnodo nuevo);
pnodo quitar_nodo(tlista &lista,int valor);
bool buscar(tlista lista,int valor);
void mostrar(tlista lista);

main()
{
	tlista lista;
	int op;
	iniciar_lista(lista);
	do{
		m_op(op);
		menu(op,lista);
		system("pause");
		system("cls");
	}while(op!=0);
}

void m_op(int &op)
{
	cout<<"|1| AGREGAR ORDEN"<<endl;
	cout<<"|2| QUITAR ESPECIFICO"<<endl;
	cout<<"|3| BUSCAR"<<endl;
	cout<<"|4| MOSTRAR"<<endl;
	cout<<"INGRESE OPCION: ";
	cin>>op;
}

void menu(int op,tlista &lista)
{
	pnodo nuevo;
	int valor;
	switch(op)
	{
	case 1:
		crear_nodo(nuevo);
		agregar_orden(lista,nuevo);
		break;
	case 2:
		cout<<"INGRESE EL VALOR A QUITAR: ";
		cin>>valor;
		quitar_nodo(lista,valor);
		break;
	case 3:
		cout<<"INGRESE EL VALOR A BUSCAR: ";
		cin>>valor;
		if(buscar(lista,valor)==true)
			cout<<"VALOR ENCONTRADO"<<endl;
		else
			cout<<"VALOR NO ENCONTRADO"<<endl;
		break;
	case 4:
		mostrar(lista);
		break;
	}
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
			(nuevo->ant)->sig=lista.inicio;
		}
		else
		{
			for(i=lista.inicio->sig;i->sig!=lista.inicio&&i->dato<nuevo->dato;i=i->sig);
			if(i->dato>nuevo->dato)
			{
				nuevo->sig=i;
				nuevo->ant=i->ant;
				(nuevo->ant)->sig=nuevo;
				i->ant=nuevo;
			}
			else
			{
				nuevo->sig=i->sig;
				i->sig=nuevo;
				nuevo->ant=i;
				(nuevo->sig)->ant=nuevo;
			}
		}
	}
}

pnodo quitar_nodo(tlista &lista,int valor)
{
	pnodo extraido,i;
	if(lista.inicio==NULL)
	{
		extraido=NULL;
	}
	else
	{
		if(lista.inicio->dato==valor)
		{
			if(lista.inicio->sig==lista.inicio)
			{
				extraido=lista.inicio;
				lista.inicio=NULL;
				extraido->sig=NULL;
				extraido->ant=NULL;
			}
			else
			{
				extraido=lista.inicio;
				lista.inicio=lista.inicio->sig;
				lista.inicio->ant=extraido->ant;
				(lista.inicio->ant)->sig=lista.inicio;
			}
		}
		else
		{
			for(i=lista.inicio->sig;i!=lista.inicio&&i->dato!=valor;i=i->sig);
			extraido=i;
			(i->ant)->sig=i->sig;
			(i->sig)->ant=i->ant;
			extraido->sig=NULL;
			extraido->ant=NULL;
		}
	}
	
	return extraido;
}

bool buscar(tlista lista,int valor)
{
	bool encontrado=false;
	pnodo i;
	if(lista.inicio!=NULL)
	{
		if(lista.inicio->dato==valor)
			encontrado=true;
		else
		{
			for(i=lista.inicio->sig;i!=lista.inicio&&i->dato!=valor;i=i->sig);
			if(i!=lista.inicio)
				encontrado=true;
		}
	}
	
	return encontrado;
}

void mostrar(tlista lista)
{
	pnodo i;
	cout<<lista.inicio->dato<<endl;
	for(i=lista.inicio->sig;i!=lista.inicio;i=i->sig)
		cout<<i->dato<<endl;
}

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
	pnodo lfinal;
};

void m_op(int &op);
void menu(int op,tlista &lista);
void iniciar_lista(tlista &lista);
void crear_nodo(pnodo &nuevo);
void agregar_inicio(tlista &lista,pnodo nuevo);
void agregar_final(tlista &lista,pnodo nuevo);
void agregar_orden(tlista &lista,pnodo nuevo);
pnodo quitar_inicio(tlista &lista);
pnodo quitar_final(tlista &lista);
pnodo quitar_especifico(tlista &lista,int valor);
void mostrar(tlista lista);
bool buscar(tlista lista,int valor);

main()
{
	int op;
	tlista lista;
	iniciar_lista(lista);
	do
	{
		m_op(op);
		menu(op,lista);
		system("pause");
		system("cls");
	}while(op!=0);
}

void m_op(int &op)
{
	cout<<"-- MENU --"<<endl;
	cout<<"|1| AGERGAR INICIO"<<endl;
	cout<<"|2| AGERGAR FINAL"<<endl;
	cout<<"|3| AGERGAR ORDEN"<<endl;
	cout<<"|4| QUITAR INICIO"<<endl;
	cout<<"|5| QUIAR FINAL"<<endl;
	cout<<"|6| QUITAR ESPECIFICO"<<endl;
	cout<<"|7| BUSCAR"<<endl;
	cout<<"|8| MOSTRAR"<<endl;
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
		agregar_inicio(lista,nuevo);
		break;
	case 2:
		crear_nodo(nuevo);
		agregar_final(lista,nuevo);
		break;
	case 3:
		crear_nodo(nuevo);
		agregar_orden(lista,nuevo);
		break;
	case 4:
		quitar_inicio(lista);
		break;
	case 5:
		quitar_final(lista);
		break;
	case 6:
		cout<<"Ingrese el valor que desea quitar: ";
		cin>>valor;
		quitar_especifico(lista,valor);
		break;
	case 7:
		cout<<"Ingrese el valor que desea buscar: ";
		cin>>valor;
		if(buscar(lista,valor)==true)
			cout<<"El valor existe"<<endl;
		else
			cout<<"El valor NO existe"<<endl;
		
		break;
	case 8:
		mostrar(lista);
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
		cout<<"Ingresa el dato: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
		nuevo->ant=NULL;
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
		lista.inicio->ant=nuevo;
		lista.inicio=nuevo;
	}
}

void agregar_final(tlista &lista,pnodo nuevo)
{
	if(lista.lfinal==NULL)
	{
		lista.inicio=nuevo;
		lista.lfinal=nuevo;
	}
	else
	{
		lista.lfinal->sig=nuevo;
		nuevo->ant=lista.lfinal;
		lista.lfinal=nuevo;
	}
}

void agregar_orden(tlista &lista,pnodo nuevo)
{
	pnodo i;
	if(lista.inicio==NULL)
	{
		lista.inicio=nuevo;
		lista.lfinal=nuevo;
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
			if(lista.lfinal->dato<nuevo->dato)
			{
				lista.lfinal->sig=nuevo;
				nuevo->ant=lista.lfinal;
				lista.lfinal=nuevo;
			}
			else
			{
				for(i=lista.inicio;i!=lista.lfinal&&i->dato<nuevo->dato;i=i->sig);
				(i->ant)->sig=nuevo;
				nuevo->ant=i->ant;
				i->ant=nuevo;
				nuevo->sig=i;
			}
		}
	}
}

pnodo quitar_inicio(tlista &lista)
{
	pnodo extraido=NULL;
	
	if(lista.inicio!=NULL)
	{
		if(lista.inicio==lista.lfinal)
		{
			extraido=lista.inicio;
			lista.inicio=NULL;
			lista.lfinal=NULL;
		}
		else
		{
			extraido=lista.inicio;
			lista.inicio=lista.inicio->sig;
			lista.inicio->ant=NULL;
			extraido->sig=NULL;
		}
	}
	
	return extraido;
}

pnodo quitar_final(tlista &lista)
{
	pnodo extraido=NULL;
	
	if(lista.lfinal!=NULL)
	{
		if(lista.lfinal==lista.inicio)
		{
			extraido=lista.lfinal;
			lista.lfinal=NULL;
			lista.inicio=NULL;
		}
		else
		{
			extraido=lista.lfinal;
			lista.lfinal->ant=lista.lfinal;
			lista.lfinal->sig=NULL;
			extraido->ant=NULL;
		}
	}
	
	return extraido;
}

pnodo quitar_especifico(tlista &lista,int valor)
{
	pnodo i;
	pnodo extraido=NULL;
	if(lista.inicio!=NULL)
	{
		if(lista.inicio->dato==valor)
		{
			if(lista.inicio==lista.lfinal)
			{
				extraido=lista.inicio;
				lista.inicio=NULL;
				lista.lfinal=NULL;
			}
			else
			{
				extraido=lista.inicio;
				lista.inicio->sig=lista.inicio;
				lista.inicio->ant=NULL;
				extraido->sig=NULL;
			}
		}
		else
		{
			if(lista.lfinal->dato==valor)
			{
				extraido=lista.lfinal;
				lista.lfinal=lista.lfinal->ant;
				lista.lfinal->sig=NULL;
				extraido->ant=NULL;
			}
			else
			{
				for(i=lista.inicio;i!=lista.lfinal&&i->dato==valor;i=i->sig);
				extraido=i;
				(i->ant)->sig=i->sig;
				(i->sig)->ant=i->ant;
				extraido->sig=NULL;
				extraido->ant=NULL;
			}
		}
	}
	
	return extraido;
}

bool buscar(tlista lista,int valor)
{
	pnodo i;
	bool encontrado=false;
	for(i=lista.inicio;i!=NULL&&i->dato!=valor;i=i->sig);
	if(i!=NULL)
		encontrado = true;
	
	return encontrado;
}

void mostrar(tlista lista)
{
	pnodo i;
	for(i=lista.inicio;i!=NULL;i=i->sig)
		cout<<i->dato<<endl;
}

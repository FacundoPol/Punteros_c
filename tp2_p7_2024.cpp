#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	char dato;
	pnodo sig;
};
typedef struct tlista{
	pnodo inicio;
	pnodo lfinal;
	int cant_num;
	int cant_may;
	int cant_min;
	int cant_sim;
};

void mostrar(pnodo i,pnodo f);
void contador_caracteres(pnodo i,pnodo f,tlista lista);
void agregar_inicio(tlista &lista,pnodo nuevo);
void contador(tlista &lista,pnodo &nuevo);
void crear_nodo(pnodo &nuevo);
void iniciar_lista(tlista &lista);
void menu(int op,tlista &lista);
void m_op(int &op);

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
	} while(op!=0);
}

void m_op(int &op)
{
	cout<<"-- MENU --"<<endl;
	cout<<"|1| AGREGAR INICIO"<<endl;
	cout<<"|2| CONTAR NODOS"<<endl;
	cout<<"|3| CONTAR CARACTERES"<<endl;
	cout<<"|4| MOSTRAR LISTA"<<endl;
	cout<<"INGRESE SU OPCION: ";
	cin>>op;
}

void menu(int op,tlista &lista)
{
	pnodo nuevo;
	switch(op)
	{
	case 1:
		crear_nodo(nuevo);
		agregar_inicio(lista,nuevo);
		break;
	case 2:
		
		break;
	case 3:
		contador_caracteres(lista.inicio,lista.lfinal,lista);
		cout<<"NUMEROS: "<<lista.cant_num<<endl;
		cout<<"MAYUSCULAS: "<<lista.cant_may<<endl;
		cout<<"MINUSCULAS: "<<lista.cant_min<<endl;
		cout<<"SIMBOLOS: "<<lista.cant_sim<<endl;
		break;
	case 4:
		mostrar(lista.inicio,lista.lfinal);
		break;
	}
}

void iniciar_lista(tlista &lista)
{
	lista.inicio=NULL;
	lista.lfinal=NULL;
	lista.cant_num=0;
	lista.cant_may=0;
	lista.cant_min=0;
	lista.cant_sim=0;
}

void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		cout<<"Ingrese dato: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
	}
	else
	{
		cout<<"MEMORIA INSUFICIENTE"<<endl;
	}
}

void contador(tlista &lista,pnodo &nuevo)
{
	if(nuevo->dato>='a'&&nuevo->dato<='z')
		lista.cant_min++;
	else
		if(nuevo->dato>='A'&&nuevo->dato<='Z')
			lista.cant_may++;
		else
		if(nuevo->dato>='1'&&nuevo->dato<='9')
			lista.cant_num++;
		else
			if(nuevo->dato<'1'&&nuevo->dato>'9'&&nuevo->dato<'a'&&nuevo->dato>'z'&&nuevo->dato<'A'&&nuevo->dato>'Z')
				lista.cant_sim++;
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
		lista.inicio=nuevo;
	}
}

void contador_caracteres(pnodo i,pnodo f,tlista lista)
{
	if(i==NULL)
		cout<<"LISTA VACIA"<<endl;
	else
	{
		if(i==f)
			contador(lista,i);
		else
		{
			contador(lista,i);
			contador_caracteres(i->sig,f,lista);
		}
	}
}
void mostrar(pnodo i,pnodo f)
{
	if(i==NULL)
		cout<<"LISTA VACIA"<<endl;
	else
	{
		if(i==f)
			cout<<i->dato<<endl;
		else
		{
			cout<<i->dato<<endl;
			mostrar(i->sig,f);
		}
	}
}

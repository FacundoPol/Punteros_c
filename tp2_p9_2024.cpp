#include <iostream>

using namespace std;

typedef  struct tnodo *pnodo;
typedef struct tnodo{
	pnodo sig;
	int dato;
};

void m_op(int &op);
void menu(pnodo &lista,int op);
void iniciar_lista(pnodo &lista);
void crear_nodo(pnodo &nuevo);
void agregar_inicio(pnodo &lista,pnodo nuevo);
pnodo quitar_final(pnodo &lista);
void mostrar_lista(pnodo lista);
bool buscar_valor(pnodo lista,int valor);

main()
{
	pnodo lista;
	int op;
	iniciar_lista(lista);
	do{
		m_op(op);
		menu(lista,op);
		system("pause");
		system("cls");
	}while(op!=0);
}

void m_op(int &op)
{
	cout<<"|1| AGREGAR INICIO"<<endl;
	cout<<"|2| QUITAR FINAL"<<endl;
	cout<<"|3| MOSTRAR"<<endl;
	cout<<"INGRESE SU OPCION: ";
	cin>>op;
}

void menu(pnodo &lista,int op)
{
	pnodo nuevo;
	switch(op)
	{
	case 1:
		crear_nodo(nuevo);
		agregar_inicio(lista,nuevo);
		break;
	case 2:
		cout<<"Dato borrado: "<<quitar_final(lista)->dato<<endl;
		break;
	case 3:
		mostrar_lista(lista);
		break;
	}
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
		cout<<"Ingresar dato: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
	}
}

void agregar_inicio(pnodo &lista,pnodo nuevo)
{ pnodo i;
	if(lista==NULL)
	{
		lista=nuevo;
		nuevo->sig=lista;
	}
	else
	{
		for(i=lista->sig;i->sig!=lista;i=i->sig);
		nuevo->sig=lista;
		lista=nuevo;
		i->sig=lista;
	}
}

pnodo quitar_final(pnodo &lista)
{
	pnodo extraido,i;
	if(lista==NULL)
		extraido=NULL;
	else
	{
		for(i=lista->sig;(i->sig)->sig!=lista;i=i->sig);
		extraido=i->sig;
		i->sig=lista;
	}
	return extraido;
}

void mostrar_lista(pnodo lista)
{
	pnodo i;
	if(lista!=NULL)
	{
		cout<<lista->dato<<endl;
		for(i=lista->sig;i!=lista;i=i->sig)
			cout<<i->dato<<endl;
	}
	else
	   cout<<"LISTA VACIA"<<endl;
}

bool buscar_valor(pnodo lista,int valor)
{
	bool encontrado;
	pnodo i;
	if(lista->dato==valor)
		encontrado=true;
	else
	{
		for(i=lista->sig;i!=lista&&i->dato!=valor;i=i->sig);
			if(i!=lista)
				encontrado=true;
			else
				encontrado=false;
	}
	
	return encontrado;
}

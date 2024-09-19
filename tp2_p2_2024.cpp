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
	int cant_may;
	int cant_min;
	int cant_num;
	int cant_sim;
};

void menu_opciones(int &op);
void menu(int op,tlista &lista);
void iniciar_lista(tlista &lista);
void crear_nodo(pnodo &nuevo);
void contador(tlista &lista,pnodo nuevo);
void decrementador(tlista &lista,pnodo nuevo);
void agregar_final(tlista &lista,pnodo nuevo);
pnodo quitar_inicio(tlista &lista);
void mostrar_lista(pnodo i,pnodo f);
bool contador_caracteres(tlista lista,pnodo nuevo);
main()
{
	tlista lista;
	iniciar_lista(lista);
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
	cout<<"|1| AGREGAR FINAL"<<endl;
	cout<<"|2| QUITAR INICIO"<<endl;
	cout<<"|3| MOSTRAR LISTA"<<endl;
	cout<<"|0| SALIR"<<endl;
	cout<<"INGRESE OPCION: ";
	cin>>op;
	cout<<endl;
}
void menu(int op,tlista &lista)
{
	pnodo nuevo;
	switch(op)
	{
	case 1:
		crear_nodo(nuevo);
		agregar_final(lista,nuevo);
		break;
	case 2:
		quitar_inicio(lista);
		break;
	case 3:
		mostrar_lista(lista.inicio,lista.lfinal);
		cout<<"CANTIDAD NUMEROS: "<<lista.cant_num<<endl;
		cout<<"CANTIDAD MAYUSCULAS: "<<lista.cant_may<<endl;
		cout<<"CANTIDAD MINUSCULAS: "<<lista.cant_min<<endl;
		cout<<"CANTIDAD SIMBOLOS: "<<lista.cant_sim<<endl;
		break;
	default:
		cout<<"SALISTE"<<endl;
	}
}
void iniciar_lista(tlista &lista)
{
	lista.inicio=NULL;
	lista.lfinal=NULL;
	lista.cant_may=0;
	lista.cant_min=0;
	lista.cant_num=0;
	lista.cant_sim=0;
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
	else
	{
		cout<<"NO HAY MEMORIA SUFICIENTE"<<endl;
	}
}

void contador(tlista &lista,pnodo nuevo)
{
	if(nuevo->dato>='1'&&nuevo->dato<='9')
	{
		lista.cant_num++;
	}
	else
	{
		if(nuevo->dato>='a'&&nuevo->dato<='z')
		{
			lista.cant_min++;
		}
		else
		{
			if(nuevo->dato>='A'&&nuevo->dato<='Z')
			{
				lista.cant_may++;
			}
			else
			{
				lista.cant_sim++;
			}
		}
	}
}

bool contador_caracteres(tlista lista,pnodo nuevo)
{
	if(nuevo->dato>='1'&&nuevo->dato<='9' && lista.cant_num<5)
	{
		return true;
	}
	else
	{
		if(nuevo->dato>='a'&&nuevo->dato<='z' && lista.cant_min<5)
		{
			return true;
		}
		else
		{
			if(nuevo->dato>='A'&&nuevo->dato<='Z'&& lista.cant_may<5)
			{
				return true;
			}
			else
			{
				if(!(nuevo->dato>='1'&&nuevo->dato<='9')&&!(nuevo->dato>='a'&&nuevo->dato<='z')&&!(nuevo->dato>='A'&&nuevo->dato<='Z')&&lista.cant_sim<5)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
}
void decrementador(tlista &lista,pnodo nuevo)
{
	if(nuevo->dato>='1'&&nuevo->dato<='9')
	{
		lista.cant_num--;
	}
	else
	{
		if(nuevo->dato>='a'&&nuevo->dato<='z')
		{
			lista.cant_min--;
		}
		else
		{
			if(nuevo->dato>='A'&&nuevo->dato<='Z')
			{
				lista.cant_may--;
			}
			else
			{
				lista.cant_sim--;
			}
		}
	}
}

void agregar_final(tlista &lista,pnodo nuevo)
{
	if(contador_caracteres(lista,nuevo)==true)
	{
		if(lista.inicio==NULL)
		{
			lista.inicio=nuevo;
			lista.lfinal=nuevo;
		}
		else
		{
			lista.lfinal->sig=nuevo;
			lista.lfinal=nuevo;
		}
		contador(lista,nuevo);
	}
	else
	{
		cout<<"SE LLENO LA CANTIDAD DE CARACTERES PERMITIDOS DE ESE TIPO"<<endl;
		delete(nuevo);
		nuevo=NULL;
	}
}

pnodo quitar_inicio(tlista &lista)
{
	pnodo extraido;
	if(lista.inicio==NULL)
	{
		extraido=NULL;
	}
	else
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
			lista.inicio=extraido->sig;
			extraido->sig=NULL;
		}
		decrementador(lista,extraido);
	}
	return extraido;
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

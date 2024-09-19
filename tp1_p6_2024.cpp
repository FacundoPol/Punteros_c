#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	int cantidad;
	char caracter;
	pnodo sig;
};
void menu_opciones(int &op);
void menu(int op,pnodo &lista);
void iniciar_lista(pnodo &lista);
void crear_nodo(pnodo &nuevo);
void agregar_final(pnodo &lista,pnodo &nuevo);
void detectar_repetido(pnodo &lista,pnodo &nuevo);
pnodo quitar_especifico(pnodo &lista,char valor);
void mostrar_recursivo(pnodo lista);
main()
{
	pnodo lista;
	int op;
	iniciar_lista(lista);
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
	cout<<"|2| QUITAR ESPECIFICO"<<endl;
	cout<<"|3| MOSTRAR RECURSIVO"<<endl;
	cout<<"|0| SALIR"<<endl;
	cout<<"INGRESE OPCION: ";
	cin>>op;
	cout<<endl;
}
void menu(int op,pnodo &lista)
{
	pnodo nuevo,extraido;
	char valor;
	switch(op)
	{
	case 1:
		crear_nodo(nuevo);
		agregar_final(lista,nuevo);
		break;
	case 2:
		cout<<"INGRESE CARACTER A QUITAR: ";
		cin>>valor;
		extraido=quitar_especifico(lista,valor);
		cout<<"EL caracter quitado era: "<<extraido->caracter<<endl;
		break;
	case 3:
		mostrar_recursivo(lista);
		break;
	default:
		cout<<"SALISTE"<<endl;
	}
}
void iniciar_lista(pnodo &lista)
{
	lista=NULL;
}
void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	cout<<"INGRESE SU CARACTER: ";
	cin>>nuevo->caracter;
	nuevo->sig=NULL;
	nuevo->cantidad=0;
}
void agregar_final(pnodo &lista,pnodo &nuevo)
{
	pnodo i;
	if(lista==NULL)
	{
		lista=nuevo;
		lista->cantidad++;
	}
	else
	{
		for(i=lista;i->sig!=NULL&&i->caracter!=nuevo->caracter;i=i->sig);
		detectar_repetido(i,nuevo);
	}
}
void detectar_repetido(pnodo &lista,pnodo &nuevo)
{
	pnodo i;
	if(lista->caracter!=nuevo->caracter)
	{
		for(i=lista;i->sig!=NULL;i=i->sig);
		i->sig=nuevo;
		nuevo->cantidad++;
	}
	else
	{
		lista->cantidad++;
		delete(nuevo);
		nuevo=NULL;
	}

}
pnodo quitar_especifico(pnodo &lista,char valor)
{
	pnodo i,extraido;
	if(lista==NULL)
	{
		extraido=NULL;
	}
	else
	{
		if(lista->caracter==valor)
		{
			if(lista->cantidad>1)
			{
				lista->cantidad--;
			}
			else
			{
				extraido=lista;
				lista->cantidad--;
				lista=extraido->sig;
				extraido->sig=NULL;
			}
		}
		else
		{
			for(i=lista;i->sig!=NULL&&(i->sig)->caracter!=valor;i=i->sig)
			{
				if(i->sig!=NULL)
				{
					if((i->sig)->cantidad>1)
					{
						(i->sig)->cantidad--;
					}
					else
					{
						extraido=i->sig;
						(i->sig)->cantidad--;
						i->sig=NULL;
						extraido->sig=NULL;
					}
				}
				else
				   extraido=NULL;
			}
		}
	}
	return extraido;
}
void mostrar_recursivo(pnodo lista)
{
	if(lista==NULL)
		cout<<"LISTA VACIA"<<endl;
	else
	{
		if(lista->sig==NULL)
			cout<<lista->caracter<<","<<lista->cantidad<<endl;
		else
		{
			cout<<lista->caracter<<","<<lista->cantidad<<endl;
			mostrar_recursivo(lista->sig);
		}
	}
}

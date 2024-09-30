#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	char dato;
	pnodo sig;
};
typedef struct tlista{
	pnodo inicio;
	pnodo fin;
	int cant;
};

void mostrar(tlista lista);
void cambio(char &a,char &b);
void ordenar(tlista &lista);
pnodo quitar_nodo(tlista &lista,char valor);
void agregar_final(tlista &lista,pnodo nuevo);
void crear_nodo(pnodo &nuevo);
void iniciar_lista(tlista &lista);
void menu(tlista &lista,int op);
void m_op(int &op);

main()
{
	tlista lista;
	int op;
	iniciar_lista(lista);
	do
	{
		m_op(op);
		menu(lista,op);
		system("pause");
		system("cls");
	}while(op!=0);
}

void m_op(int &op)
{
	cout<<"|1| AGREAGAR FINAL"<<endl;
	cout<<"|2| QUITAR ESPECIFICO"<<endl;
	cout<<"|3| ORDENAR MAY A MEN"<<endl;
	cout<<"|4| MOSTRAR"<<endl;
	cout<<"INGRESE OPCION: ";
	cin>>op;
}

void menu(tlista &lista,int op)
{
	char valor;
	pnodo nuevo;
	switch(op)
	{
	case 1:
		crear_nodo(nuevo);
		agregar_final(lista,nuevo);
		break;
	case 2:
		cout<<"Ingresar valor a quitar: ";
		cin>>valor;
		cout<<"ELEMENTO ELIMINADO: "<<quitar_nodo(lista,valor)->dato<<endl;
		break;
	case 3:
		ordenar(lista);
		break;
	case 4:
		mostrar(lista);
		break;
	}
}

void iniciar_lista(tlista &lista)
{
	lista.inicio=NULL;
	lista.fin=NULL;
}

void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		cout<<"INGRESE SU DATO: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
	}
}

void agregar_final(tlista &lista,pnodo nuevo)
{
	if(lista.fin==NULL)
	{
		lista.inicio=nuevo;
		lista.fin=nuevo;
		lista.fin->sig=lista.inicio;
	}
	else
	{
		lista.fin->sig=nuevo;
		nuevo->sig=lista.inicio;
		lista.fin=nuevo;
	}
}

pnodo quitar_nodo(tlista &lista,char valor)
{
	pnodo i,extraido;
	if(lista.inicio==NULL)
		extraido=NULL;
	else
	{
		if(lista.inicio==lista.fin)
		{
			if(lista.inicio->dato==valor)
			{
				extraido=lista.inicio;
				lista.inicio=NULL;
				lista.fin=NULL;
			}
			else
			   extraido=NULL;
		}
		else
		{
			if(lista.inicio->dato==valor)
			{
				extraido=lista.inicio;
				lista.inicio=lista.inicio->sig;
				lista.fin->sig=lista.inicio;
				extraido->sig=NULL;
			}
			else
			{
				if(lista.fin->dato==valor)
				{
					for(i=lista.inicio;i->sig!=lista.fin;i=i->sig);
					extraido=lista.fin;
					i->sig=lista.inicio;
					extraido->sig=NULL;
				}
				else
				{
					for(i=lista.inicio;i!=lista.fin&&(i->sig)->dato!=valor;i=i->sig);
					if(i->sig!=lista.fin)
					{
						extraido=i->sig;
						i->sig=(i->sig)->sig;
						extraido->sig=NULL;
					}
				}
			}
		}
	}
	
	return extraido;
}

void ordenar(tlista &lista)
{
	pnodo i,k;
	
	for(i=lista.inicio;i!=lista.fin;i=i->sig)
	{
		for(k=i->sig;k!=lista.inicio;k=k->sig)
		{
			if(i->dato>k->dato)
				cambio(i->dato,k->dato);
		}
	}
}

void cambio(char &a,char &b)
{
	char aux;
	aux=a;
	a=b;
	b=aux;
}

void mostrar(tlista lista)
{
	pnodo i;
	for(i=lista.inicio;i!=lista.fin;i=i->sig)
		cout<<i->dato<<endl;
	cout<<lista.fin->dato<<endl;
}

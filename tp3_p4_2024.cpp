#include <iostream>
#include <string.h>
using namespace std;

typedef char tcad[15];

typedef struct tnodo *pnodo;
typedef struct tnodo{
	tcad dato;
	pnodo sig;
	pnodo ant;
};
typedef tcad tvector[7];
typedef struct tlista{
	pnodo inicio;
};

void m_op(int &op);
void menu(tlista &lista,int op);
void iniciar_lista(tlista lista);
void crear_nodo(pnodo &nuevo,tcad dia);
void formar_lista(tlista &lista,tvector v);
void agregar_final(tlista &lista,pnodo nuevo);
void mostrar(tlista lista);
void cambiar_inicio(tlista &lista);
void cambio(tcad &cad1,tcad &cad2);
void orden_inverso(tlista &lista);

main()
{
	int op;
	tvector v{"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"};
	tlista lista;
	iniciar_lista(lista);
	formar_lista(lista,v);
	do{
		m_op(op);
		menu(lista,op);
		system("pause");
		system("cls");
	}while(op!=0);
}

void m_op(int &op)
{
	cout<<"|1| CAMBIAR INICIO"<<endl;
	cout<<"|2| INVERTIR"<<endl;
	cout<<"|3| MOSTRAR"<<endl;
	cout<<"INGRESE SU OPCION: ";
	cin>>op;
}

void menu(tlista &lista,int op)
{
	switch(op)
	{
	case 1:
		cambiar_inicio(lista);
		break;
	case 2:
		orden_inverso(lista);
		break;
	case 3:
		mostrar(lista);
		break;
	}
}

void iniciar_lista(tlista lista)
{
	lista.inicio=NULL;
}

void crear_nodo(pnodo &nuevo,tcad dia)
{
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		strcpy(nuevo->dato,dia);
		nuevo->sig=NULL;
		nuevo->ant=NULL;
	}
	else
	   cout<<"NO HAY MEMO SUF"<<endl;
}

void formar_lista(tlista &lista,tvector v)
{
	pnodo nuevo;
	int i;
	for(i=0;i<7;i++)
	{
		crear_nodo(nuevo,v[i]);
		agregar_final(lista,nuevo);
	}
}

void agregar_final(tlista &lista,pnodo nuevo)
{
	pnodo i;
	if(lista.inicio==NULL)
	{
		lista.inicio=nuevo;
	}
	else
	{
		for(i=lista.inicio;i->sig!=NULL;i=i->sig);
		i->sig=nuevo;
		nuevo->ant=i;
	}
}

void mostrar(tlista lista)
{
	pnodo i;
	for(i=lista.inicio;i!=NULL;i=i->sig)
		cout<<i->dato<<endl;
}

void cambiar_inicio(tlista &lista)
{
	pnodo i,a;
	tcad dia;
	cout<<"Elija el dia de inicio: ";
	cin>>dia;
	a=lista.inicio;
	for(i=lista.inicio;i!=NULL;i=i->sig)
	{
		if(strcmp(i->dato,dia)==0)
		{
			lista.inicio=i;
			(lista.inicio->ant)->sig=NULL;
			lista.inicio->ant=NULL;
		}
	}
	agregar_final(lista,a);
	
	mostrar(lista);
}

void orden_inverso(tlista &lista)
{
	pnodo i,j;
	
	for(i=lista.inicio;i->sig!=NULL;i=i->sig);
	j=i;
	i=lista.inicio;
	while(i!=j)
	{
		cambio(j->dato,i->dato);
		j=j->ant;
		i=i->sig;
	}
	mostrar(lista);
}

void cambio(tcad &cad1,tcad &cad2)
{
	tcad aux;
	strcpy(aux,cad1);
	strcpy(cad1,cad2);
	strcpy(cad2,aux);
	
}

#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	char dato;
	pnodo sig;
	pnodo ant;
};
typedef struct tlista{
	pnodo inicio;
	pnodo fin;
};

void mostrar(tlista lista);
void agregar_final(tlista &lista,pnodo nuevo);
void agregar_inicio(tlista &lista,pnodo nuevo);
void ingresar_inicio_final(tlista &lista,pnodo nuevo);
void crear_nodo(pnodo &nuevo);
void inicar_lista(tlista &lista);
void menu(tlista &lista,int op);
void m_op(int &op);

main()
{
	tlista lista;
	int op;
	inicar_lista(lista);
	do{
		m_op(op);
		menu(lista,op);
		system("pause");
		system("cls");
	}while(op!=0);
}

void m_op(int &op)
{
	cout<<"|1| AGREGAR"<<endl;
	cout<<"|2| MOSTRAR"<<endl;
	cout<<"INGRESE SU OPCION: ";
	cin>>op;
}

void menu(tlista &lista,int op)
{
	pnodo nuevo;
	switch(op)
	{
	case 1:
		crear_nodo(nuevo);
		ingresar_inicio_final(lista,nuevo);
		break;
	case 2:
		mostrar(lista);
		break;
	}
}

void inicar_lista(tlista &lista)
{
	lista.inicio=NULL;
	lista.fin=NULL;
}

void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		cout<<"INGRESE CARACTER: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
		nuevo->ant=NULL;
	}
	else
	   cout<<"NO HAY MEMORIA SUFICIENTE"<<endl;
}

void ingresar_inicio_final(tlista &lista,pnodo nuevo)
{
	pnodo i;
	int op;
	if(lista.inicio==NULL)
	{
		cout<<"|1| AGREGAR INICIO"<<endl;
		cout<<"|2| AGREGAR FINAL"<<endl;
		cout<<"INGRESE OPCION: ";
		cin>>op;
		if(op==1)
			agregar_inicio(lista,nuevo);
		else
			agregar_final(lista,nuevo);
	}
	else
	{
		if(lista.inicio->dato==nuevo->dato)
		{
			cout<<"EL CARACTER YA EXISTE"<<endl;
			delete(nuevo);
			nuevo=NULL;
		}
		else
		{
			if(lista.fin->dato==nuevo->dato)
			{
				cout<<"EL CARACTER YA EXISTE"<<endl;
				delete(nuevo);
				nuevo=NULL;
			}
			else
			{
				for(i=lista.inicio;i!=lista.fin&&i->dato!=nuevo->dato;i=i->sig);
				if(i->dato==nuevo->dato)
				{
					cout<<"EL CARACTER YA EXISTE"<<endl;
					delete(nuevo);
					nuevo=NULL;
				}
				else
				{
					cout<<"|1| AGREGAR INICIO"<<endl;
					cout<<"|2| AGREGAR FINAL"<<endl;
					cout<<"INGRESE OPCION: ";
					cin>>op;
					if(op==1)
						agregar_inicio(lista,nuevo);
					else
						agregar_final(lista,nuevo);
				}
			}
		}
	}
}

void agregar_inicio(tlista &lista,pnodo nuevo)
{
	if(lista.inicio==NULL)
	{
		lista.inicio=nuevo;
		lista.fin=nuevo;
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
	if(lista.inicio==NULL)
	{
		lista.inicio=nuevo;
		lista.fin=nuevo;
	}
	else
	{
		lista.fin->sig=nuevo;
		nuevo->ant=lista.fin;
		lista.fin=nuevo;
	}
}

void mostrar(tlista lista)
{
	pnodo i;
	int op;
	cout<<"|1| PRIMERO AL ULTIMO"<<endl;
	cout<<"|2| ULTIMO AL PRIMERO"<<endl;
	cout<<"INGRESE SU OPCION: ";
	cin>>op;
	if(op==1)
		i=lista.inicio;
	else
		i=lista.fin;
	
	while(i!=NULL)
	{
		cout<<i->dato<<endl;
		if(op==1)
			i=i->sig;
		else
			i=i->ant;
	}
}


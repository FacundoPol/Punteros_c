#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	float dato;
	pnodo sig;
};
typedef struct tlista{
	pnodo inicio;
	pnodo lfinal;
};

void menu_op(int &op);
void menu(int op,tlista &lista);
void iniciar_lista(tlista &lista);
void crear_nodo(pnodo &nuevo);
void agregar_inicio(tlista &lista,pnodo nuevo);
void agregar_final(tlista &lista,pnodo nuevo);
void agregar(tlista &lista,pnodo nuevo,int op);
pnodo quitar_inicio(tlista &lista);
pnodo quitar_final(tlista &lista);
void quitar(tlista &lista,int op);
bool buscar_recur_logico(pnodo i,pnodo f,float valor);
pnodo buscar_recur_puntero(pnodo i,pnodo f,float valor);
void mostrar(pnodo i,pnodo f);

main()
{
	int op;
	tlista lista;
	iniciar_lista(lista);
	do{
		menu_op(op);
		menu(op,lista);
		system("pause");
		system("cls");
	} while(op!=0);
}
void menu_op(int &op)
{
	cout<<"-- MENU --"<<endl;
	cout<<"|1|AGREGAR"<<endl;
	cout<<"|2|QUITAR"<<endl;
	cout<<"|3|BUSCAR"<<endl;
	cout<<"|4|MOSTRAR"<<endl;
	cout<<"INGRESE OPCION: ";
	cin>>op;
}

void menu(int op,tlista &lista)
{
	int valor;
	pnodo nuevo;
	switch(op)
	{
	case 1:
		cout<<"|1|AGREGAR INICIO"<<endl;
		cout<<"|2|AGREGAR FINAL"<<endl;
		cout<<"INGRESE OPCION: ";
		cin>>op;
		crear_nodo(nuevo);
		agregar(lista,nuevo,op);
		break;
	case 2:
		cout<<"|1|QUITAR INICIO"<<endl;
		cout<<"|2|QUITAR FINAL"<<endl;
		cout<<"INGRESE OPCION: ";
		cin>>op;
		quitar(lista,op);
		break;
	case 3:
		cout<<"INGRESE EL VALOR BUSCADO: ";
		cin>>valor;
		if(buscar_recur_logico(lista.inicio,lista.lfinal,valor)==true)
			cout<<"EL VALOR BUSCADO ESTA EN LA LISTA: "<<buscar_recur_puntero(lista.inicio,lista.lfinal,valor)->dato<<endl;
		else
			cout<<"NO EXISTE EL VALOR EN LA LISTA"<<endl;
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
		cout<<"NO HAY MEMORIA SUFICIENTE"<<endl;
	}
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

void agregar_final(tlista &lista,pnodo nuevo)
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
}

void agregar(tlista &lista,pnodo nuevo,int op)
{
	if(buscar_recur_logico(lista.inicio,lista.lfinal,nuevo->dato)==false)
	{
		if(op==1)
			agregar_inicio(lista,nuevo);
		else
			agregar_final(lista,nuevo);
	}
	else
	{
		cout<<"EL VALOR YA EXISTE EN LA LISTA"<<endl;
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
	}
	return extraido;
}

pnodo quitar_final(tlista &lista)
{
	pnodo i,extraido;
	if(lista.lfinal==NULL)
		extraido=NULL;
	else
	{
		if(lista.lfinal==lista.inicio)
		{
			extraido=lista.lfinal;
			lista.inicio=NULL;
			lista.lfinal=NULL;
		}
		else
		{
			for(i=lista.inicio;i->sig!=lista.lfinal;i=i->sig);
			extraido=lista.lfinal;
			lista.lfinal=i;
			lista.lfinal->sig=NULL;
		}
	}
	return extraido;
}

void quitar(tlista &lista,int op)
{
	if(op==1)
		quitar_inicio(lista);
	else
		quitar_final(lista);
}

bool buscar_recur_logico(pnodo i,pnodo f,float valor)
{
	if(i==NULL)
		return false;
	else
	{
		if(i->dato==valor)
			return true;
		else
		{
			if(i==f)
				return false;
			else
				return buscar_recur_logico(i->sig,f,valor);
		}
	}
}

pnodo buscar_recur_puntero(pnodo i,pnodo f,float valor)
{
	pnodo buscado=NULL;
	if(i!=NULL)
	{
		if(i->dato==valor)
			return buscado=i;
		else
		{
			if(i==f)
				return buscado;
			else
				return buscar_recur_puntero(i->sig,f,valor);
		}
	}
	return buscado;
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

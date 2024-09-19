#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	int dato;
	pnodo sig;
	pnodo ant;
};

void m_op(int &op);
void menu(int op,pnodo &lista);
void iniciar_lista(pnodo &lista);
void crear_nodo(pnodo &nuevo);
void agregar_inicio(pnodo &lista,pnodo nuevo);
void agregar_final(pnodo &lista,pnodo nuevo);
void agregar_orden(pnodo &lista,pnodo nuevo);
pnodo quitar_inicio(pnodo &lista);
pnodo quitar_final(pnodo &lista);
pnodo quitar_especifico(pnodo &lista,int valor);
void mostrar(pnodo lista);
void mostrar_invertido(pnodo lista);
bool buscar(pnodo lista,int valor);

main()
{
	int op;
	pnodo lista;
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

void menu(int op,pnodo &lista)
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

void iniciar_lista(pnodo &lista)
{
	lista = NULL;
}

void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		cout<<"INGRESE DATO: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
		nuevo->ant=NULL;
	}
	else
	   cout<<"NO HAY MAS MEMORIA"<<endl;
}

void agregar_inicio(pnodo &lista,pnodo nuevo)
{
	if(lista==NULL)
	{
		lista=nuevo;
	}
	else
	{
		nuevo->sig=lista;
		lista=nuevo;
		(lista->sig)->ant=lista;
	}
}

void agregar_final(pnodo &lista,pnodo nuevo)
{
	pnodo i;
	if(lista==NULL)
	{
		lista=nuevo;
	}
	else
	{
		for(i=lista;i->sig!=NULL;i=i->sig);
		i->sig=nuevo;
		nuevo->ant=i;
	}
}

void agregar_orden(pnodo &lista,pnodo nuevo)
{
	pnodo i;
	if(lista==NULL)
		lista=nuevo;
	else
	{
		if(lista->dato>nuevo->dato)
		{
			nuevo->sig=lista;
			lista=nuevo;
			(lista->sig)->ant=lista;
		}
		else
		{
			for(i=lista;i->sig!=NULL;i=i->sig);
			if(i->dato<nuevo->dato)
			{
				i->sig=nuevo;
				nuevo->ant=i;
			}
			else
			{
				for(i=lista;i->sig!=NULL&&i->dato<nuevo->dato;i=i->sig);
					(i->ant)->sig=nuevo;
					nuevo->ant=i->ant;
					i->ant=nuevo;
					nuevo->sig=i;
			}
		}
	}
}

pnodo quitar_inicio(pnodo &lista)
{
	pnodo extraido=NULL;
	if(lista!=NULL)
	{
		if(lista->sig==NULL)
		{
			extraido=lista;
			lista=NULL;
			extraido->sig=NULL;
		}
		else
		{
			extraido=lista;
			lista=lista->sig;
			lista->ant=NULL;
			extraido->sig=NULL;
		}
	}
	return extraido;
}

pnodo quitar_final(pnodo &lista)
{
	pnodo extraido=NULL,i;
	
	if(lista!=NULL)
	{
		if(lista->sig==NULL)
		{
			extraido=lista;
			lista=NULL;
		}
		else
		{
			for(i=lista;i->sig!=NULL;i=i->sig);
			extraido=i;
			(i->ant)->sig=NULL;
			i->ant=NULL;
		}
	}
	
	return extraido;
}

pnodo quitar_especifico(pnodo &lista,int valor)
{
	pnodo i,extraido=NULL;
	
	if(lista!=NULL)
	{
		if(lista->sig==NULL)
		{
			extraido=lista;
			lista=NULL;
		}
		else
		{
			if(lista->dato==valor)
			{
				extraido=lista;
				lista=lista->sig;
				lista->ant=NULL;
				extraido->sig=NULL;
			}
			else
			{
				for(i=lista;i->sig!=NULL;i=i->sig);
				if(i->dato==valor)
				{
					extraido=i;
					(i->ant)->sig=NULL;
					extraido->ant=NULL;
				}
				else
				{
					for(i=lista;i->sig!=NULL;i=i->sig)
					{
						if(i->dato==valor && i->sig != NULL)
						{
							extraido=i;
							(i->sig)->ant=i->ant;
							(i->ant)->sig=i->sig;
							extraido->sig=NULL;
							extraido->ant=NULL;
						}
					}
				}
			}
		}
	}
	
	return extraido;
}

void mostrar(pnodo lista)
{
	pnodo i;
	for(i=lista;i!=NULL;i=i->sig)
	{
		cout<<i->dato<<endl;
	}
	
	
}

void mostrar_invertido(pnodo lista)
{
	pnodo i;
	for(i=lista;i->sig!=NULL;i=i->sig);
	for(i=i;i!=NULL;i=i->ant)
	{
		cout<<i->dato<<endl;
	}
}

bool buscar(pnodo lista,int valor)
{
	pnodo i;
	bool encontrado = false;
	for(i=lista;i!=NULL&&valor!=i->dato;i=i->sig);
	if(i!=NULL)
		encontrado=true;
	
	return encontrado;
}

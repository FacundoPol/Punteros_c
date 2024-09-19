#include <iostream>

using namespace std;

const int limite=2;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	char dato;
	pnodo sig;
};
typedef struct tlista{
	pnodo inicio;
	int cantidad;
};

void menu_opciones(int &op);
void menu_seleccion(int op,tlista &lista);
void crear_lista(tlista &lista);
void crear_nodo(pnodo &nuevo);
void agregar_inicio(tlista &lista,pnodo nuevo);
void agregar_final(tlista &lista,pnodo nuevo);
void agregar_orden(tlista &lista,pnodo nuevo);
pnodo quitar_inicio(tlista &lista);
pnodo quitar_final(tlista &lista);
pnodo quitar_especifico(tlista &lista,char valor);
bool buscar_nodo(tlista lista,char valor);
void mostrar_lista(tlista lista);
void mostrar_lista_recursiva(pnodo lista);

main()
{
	tlista lista;
	crear_lista(lista);
	int op;
	do
	{
		menu_opciones(op);
		menu_seleccion(op,lista);
		system("pause");
		system("cls");
	}
	while(op!=0);
}
void menu_opciones(int &op)
{
	cout<<"--- MENU ---"<<endl;
	cout<<"|1| AGREGAR INICIO"<<endl;
	cout<<"|2| AGREGAR FINAL"<<endl;
	cout<<"|3| AGREGAR EN ORDEN"<<endl;
	cout<<"|4| QUITAR INICIO"<<endl;
	cout<<"|5| QUITAR FINAL"<<endl;
	cout<<"|6| QUITAR ESPECIFICO"<<endl;
	cout<<"|7| BUSCAR ELEMENTO"<<endl;
	cout<<"|8| MOSTRAR RECURSIVO"<<endl;
	cout<<"|9| MOSTRAR BUCLE"<<endl;
	cout<<endl;
	cout<<"INGRESE OPCION: ";
	cin>>op;
}
void menu_seleccion(int op,tlista &lista)
{
	pnodo nuevo;
	char valor;
	pnodo extraido;
	switch(op)
	{
	case 1:
		crear_nodo(nuevo);
		if(nuevo!=NULL)
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
		extraido=quitar_inicio(lista);
		cout<<"El valor extraido es: "<<extraido->dato<<endl;
		break;
	case 5:
		extraido=quitar_final(lista);
		cout<<"El valor extraido es: "<<extraido->dato<<endl;
		break;
	case 6:
		cout<<"Ingrese caracter a extraer: ";
		cin>>valor;
		extraido=quitar_especifico(lista,valor);
		cout<<"El valor extraido es: "<<valor<<endl;
		break;
	case 7:
		cout<<"Ingrese caracter a buscar: ";
		cin>>valor;
		if(buscar_nodo(lista,valor)==true)
		{
			cout<<"Valor "<<valor<< "encontrado"<<endl;
		}
		break;
	case 8:
		cout<<"Datos: ";
		mostrar_lista_recursiva(lista.inicio);
		break;
	case 9:
		mostrar_lista(lista);
		break;
	default:
		cout<<"SALISTE"<<endl;
		break;
	}
}
void crear_lista(tlista &lista)
{
	lista.inicio=NULL;
	lista.cantidad=0;
}
void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		cout<<"Ingresar Dato: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
	}
	else
	{
		cout<<"NO hay mas memoria"<<endl;
	}
}
void agregar_inicio(tlista &lista,pnodo nuevo)
{
	if(lista.cantidad<limite)
	{
		nuevo->sig=lista.inicio;
		lista.inicio=nuevo;
		lista.cantidad++;
	}
	else
	{
		delete(nuevo);
		nuevo=NULL;
		cout<<"No se pueden agregar mas elementos"<<endl;
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
		for(i=lista.inicio;i->sig==NULL;i=i->sig);
		i->sig=nuevo;
	}
}
void agregar_orden(tlista &lista,pnodo nuevo)
{
	pnodo i;
	if(lista.inicio==NULL)
	{
		lista.inicio=nuevo;
	}
	else
	{
		if(lista.inicio->dato>nuevo->dato)
		{
			nuevo->sig=lista.inicio;
			lista.inicio=nuevo;
		}
		else
		{
			for(i=lista.inicio;i->sig!=NULL&&nuevo->dato>(i->sig)->dato;i=i->sig);
			nuevo->sig=i->sig;
			i->sig=nuevo;
		}
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
		extraido=lista.inicio;
		lista.inicio=extraido->sig;
		extraido->sig=NULL;
		lista.cantidad--;
	}
	return extraido;
}
pnodo quitar_final(tlista &lista)
{
	pnodo extraido,i;
	if(lista.inicio==NULL)
	{
		extraido=NULL;
	}
	else
	{
		if(lista.inicio->sig==NULL)
		{
			extraido=lista.inicio;
			lista.inicio=NULL;
		}
		else
		{
			for(i=lista.inicio;(i->sig)->sig!=NULL;i=i->sig);
			extraido=i->sig;
			i->sig=NULL;
		}
	}
	return extraido;
}
pnodo quitar_especifico(tlista &lista,char valor)
{
	pnodo i,extraido;
	if(lista.inicio==NULL)
	{
		extraido=NULL;
	}
	else
	{
		if(lista.inicio->dato==valor)
		{
			extraido=lista.inicio;
			lista.inicio=NULL;
			extraido->sig=NULL;
		}
		else
		{
			for(i=lista.inicio;i->sig!=NULL&&(i->sig)->dato!=valor;i=i->sig);
			if(i->sig!=NULL)
			{
				extraido=i->sig;
				i->sig=extraido->sig;
				extraido->sig=NULL;
			}
			else
			{
				extraido=NULL;
			}
		}
	}
	return extraido;
}
bool buscar_nodo(tlista lista,char valor)
{
	bool encontrado=false;
	pnodo i;
	if(lista.inicio!=NULL)
	{
		for(i=lista.inicio;i!=NULL&&encontrado==false;i=i->sig)
		{
			if(i->dato==valor)
				encontrado=true;
		}
	}
	return encontrado;
}
void mostrar_lista(tlista lista)
{
	pnodo i;
	cout<<"Datos: ";
	if(lista.inicio != NULL)
	{
		for(i=lista.inicio;i!=NULL;i=i->sig)
			cout<<i->dato<<" ";
	}
	else
	{
		cout<<"Lista Vacia"<<endl;
	}
	cout<<endl;
}
void mostrar_lista_recursiva(pnodo lista)
{
	if(lista==NULL)
		cout<<"Lista Vacia"<<endl;
	else
	{
		if(lista->sig==NULL)
		{
			cout<<lista->dato<<" ";
		}
		else
		{
			cout<<lista->dato<<" ";
			mostrar_lista_recursiva(lista->sig);
		}
	}
	cout<<endl;
}

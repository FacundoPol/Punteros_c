#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct pnodo{
	int dato;
	pnodo sig;
};
typedef struct tlista{
	pnodo inicio;
	pnodo lfinal;
};

main()
{
	
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
	   cout<<"NO HAY MEMORIA SUFICIENTE"<<endl;
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
		lista.inicio=NULL;
		lista.lfinal=NULL;
	}
	else
	{
		lista.lfinal->sig=nuevo;
		lista.lfinal=nuevo;
	}
}
void agegar_orden(tlista &lista,pnodo nuevo)
{
	pnodo i;
	if(lista.inicio==NULL)
	{
		lista.inicio=nuevo;
		lista.lfinal=nuevo;
	}
	else
	{
		if(lista.inicio->dato > nuevo->dato)
		{
			nuevo->sig=lista.inicio;
			lista.inicio=nuevo;
		}
		else
		{
			if(lista.lfinal->dato > nuevo->dato)
			{
				lista.lfinal->sig=nuevo;
				lista.lfinal=nuevo;
			}
			else
			{
				for(i=lista.inicio;i->sig!=NULL&&(i->sig)->dato < nuevo->dato;i=i->sig);
				nuevo->sig=i->sig;
				i->sig=nuevo;
			}
		}
	}
}

pnodo quitar_inicio(tlista &lista)
{
	pnodo extraido;
	if(lista.inicio==NULL)
		extraido=NULL;
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
	pnodo extraido,i;
	if(lista.lfinal==NULL)
	{
		extraido=NULL;
	}
	else
	{
		if(lista.lfinal==lista.inicio)
		{
			extraido=lista.lfinal;
			lista.lfinal=NULL;
			lista.inicio=NULL;
		}
		else
		{
			for(i=lista.inicio;i->sig!=lista.lfinal;i=i->sig);
			extraido=lista.lfinal;
			lista.lfinal=i;
			lista.lfinal->sig=extraido->sig;
		}
	}
	return extraido;
}

pnodo quitar_especifico(tlista &lista,int valor)
{
	pnodo extraido,i;
	if(lista.inicio==NULL)
	{
		extraido=NULL;
	}
	else
	{
		if(lista.inicio->dato==valor)
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
		else
		{
			for(i=lista.inicio;i->sig!=NULL&&(i->sig)->dato!=valor;i=i->sig);
			if(i->sig!=NULL)
			{
				extraido=i->sig;
				i->sig=extraido->sig;
				extraido->sig=NULL;
				if(i->sig==lista.lfinal)
					lista.lfinal=i;
			}
			else
				extraido=NULL;
		}
	}
	return extraido;
}

bool buscar(tlista lista,int valor)
{
	pnodo i;
	
	for(i=lista.inicio;i!=NULL&i->dato!=valor;i=i->sig);
	return i!=NULL;
}

void mostrar(tlista lista) 
{
	pnodo i;
	if(lista.inicio==NULL)
	{
		cout<<"LISTA VACIA"<<endl;
	}
	else
	{
		for(i=lista.inicio;i!=NULL;i=i->sig)
		{
			cout<<i->dato<<endl;
		}
	}
}
void mostrar_recursivo(pnodo i,pnodo f)
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
			mostrar_recursivo(i->sig,f);
		}
	}
	
}

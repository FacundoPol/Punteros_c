#include <iostream>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	char dato;
	pnodo sig;
};
typedef pnodo tlista[2];

void m_op(int &op);
void menu(tlista &lista,int op);
void iniciar_lista(tlista &lista);
void crear_nodo(pnodo &nuevo);
void agrear_orden(tlista &lista,pnodo nuevo);
pnodo quitar_final(tlista &lista);
void mostrar_recur(pnodo i,pnodo f);

main()
{
	tlista lista;
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
	cout<<"|1| AGREGAR ORDEN"<<endl;
	cout<<"|2| QUITAR FINAL"<<endl;
	cout<<"|3| MOSTRAR RECUR"<<endl;
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
		agrear_orden(lista,nuevo);
		break;
	case 2:
		cout<<"Dato borrado: "<<quitar_final(lista)->dato<<endl;
		break;
	case 3:
		mostrar_recur(lista[0],lista[1]);
		break;
	}
}

void iniciar_lista(tlista &lista)
{
	lista[0]=NULL;
	lista[1]=NULL;
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

void agrear_orden(tlista &lista,pnodo nuevo)
{
	pnodo i;
	if(lista[0]==NULL)
	{
		lista[0]=nuevo;
		lista[1]=nuevo;
	}
	else
	{
		if(lista[0]->dato>nuevo->dato)
		{
			nuevo->sig=lista[0];
			lista[0]=nuevo;
		}
		else
		{
			if(lista[1]->dato<nuevo->dato)
			{
				lista[1]->sig=nuevo;
				lista[1]=nuevo;
			}
			else
			{
				for(i=lista[0]->sig;i!=lista[1]&&(i->sig)->dato<nuevo->dato;i=i->sig);
				if(i!=lista[1])
				{
					nuevo->sig=i->sig;
					i->sig=nuevo;
				}
			}
		}
	}
}

pnodo quitar_final(tlista &lista)
{
	pnodo extraido,i;
	if(lista[1]==NULL)
		extraido=NULL;
	else
	{
		for(i=lista[0];i->sig!=lista[1];i=i->sig)
		extraido=lista[1];
		i->sig=NULL;
		lista[1]=i;
	}
	
	return extraido;
}

void mostrar_recur(pnodo i,pnodo f)
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
			mostrar_recur(i->sig,f);
		}
	}
}

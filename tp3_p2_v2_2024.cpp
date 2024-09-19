#include <iostream>
#include <ctime>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct  tnodo {
	int dato;
	pnodo sig;
	pnodo ant;
};
typedef struct tlista{
	int cantidad_nodo;
	int limite_nodo;
	pnodo inicio;
};

void cambio(int &n1,int &n2);
void ordenar(tlista &lista);
void agregar_final(tlista &lista,pnodo nuevo);
void crear_nodo(pnodo &nuevo,int num);
void iniciar_lista(tlista &lista);
void generar_nodos(tlista &lista);
void m_op(int &op);
void menu(tlista &lista,int op);
void mostrar(tlista lista);
void mostrar2(tlista lista);
void seleccionar_orden(tlista lista,pnodo i);

main()
{
	tlista lista;
	int op;
	iniciar_lista(lista);
	system("cls");
	do{
		m_op(op);
		menu(lista,op);
		system("pause");
		system("cls");
	}while(op!=0);
}
void m_op(int &op)
{
	cout<<"|1|GENERAR NODOS"<<endl;
	cout<<"|2|ORDENAR"<<endl;
	cout<<"INGRESE SU OPCION: ";
	cin>>op;
}

void menu(tlista &lista,int op)
{
	switch(op)
	{
	case 1:
		generar_nodos(lista);
		break;
	case 2:
		ordenar(lista);
		mostrar(lista);
		break;
	}
}
void generar_nodos(tlista &lista)
{
	int cant,i,num;
	srand(time(NULL));
	cout<<"INGRESE LA CANTIDAD DE NUMEROS QUE QUIERE GENERAR: ";
	cin>>cant;
	pnodo nuevo;
	if(cant<=lista.limite_nodo)
	{
		for(i=0;i<cant;i++)
		{
			num = 100 + rand()%900;
			crear_nodo(nuevo,num);
			agregar_final(lista,nuevo);
		}
	}
	else
	   cout<<"SUPERAR EL LIMITE PERMITIDO DE NODOS"<<endl;
	
}

void iniciar_lista(tlista &lista)
{
	lista.inicio=NULL;
	cout<<"INGRESE EL LIMITE DE NUMEROS QUE VA A INGRESAR: ";
	cin>>lista.limite_nodo;
	lista.cantidad_nodo=0;
}

void crear_nodo(pnodo &nuevo,int num)
{
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		nuevo->dato=num;
		nuevo->sig=NULL;
		nuevo->ant=NULL;
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
	lista.cantidad_nodo++;
}

void ordenar(tlista &lista)
{
	pnodo i,j;
	int opc;
	cout<<"|1|ORDEN DE MAYOR A MENOR"<<endl;
	cout<<"|2|ORDEN DE MENOR A MAYOR"<<endl;
	cout<<"Ingrese opcion: ";
	cin>>opc;
	for(i=lista.inicio;i->sig!=NULL;i=i->sig)
	{
		for(j=i->sig;j!=NULL;j=j->sig)
		{
			if(opc==2)
			{
				if(i->dato>j->dato)
					cambio(j->dato,i->dato);
			}
			else
			{
				if(i->dato<j->dato)
					cambio(j->dato,i->dato);
			}
		}
		
	}
}

void cambio(int &n1,int &n2)
{
	int aux;
	aux=n1;
	n1=n2;
	n2=aux;
}

void mostrar(tlista lista)
{
	pnodo i;
	for(i=lista.inicio;i!=NULL;i=i->sig)
		cout<<i->dato<<endl;
}

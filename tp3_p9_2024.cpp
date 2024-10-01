#include <iostream>
#include <time.h>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	int num;
	pnodo sig;
	pnodo ant;
	char color;
};
typedef struct tlista{
	pnodo inicio;
	pnodo fin;
	int cant;
};

void iniciar_lista(tlista &lista);
void crear_nodo(pnodo &nuevo);
void agregar_final(tlista &lista,pnodo &nuevo,int n);
void crear_ruleta(tlista &lista);
pnodo movimiento_ruleta(tlista lista);
void resultado(tlista lista,pnodo ganador,int num,char c,int paridad);

main()
{
	tlista lista;
	iniciar_lista(lista);
	char c;
	int op,num,paridad;
	pnodo ganador;
	crear_ruleta(lista);
	do
	{
		cout<<"INGRESE NUMERO A APOSTAR: ";
		cin>>num;
		cout<<"INGRESE COLOR A APOSTAR (r -> ROJO || n -> NEGRO): ";
		cin>>c;
		cout<<"INGRESE PARIDAD A APOSTAR (1 -> PAR || 2 -> IMPAR): ";
		cin>>paridad;
		ganador=movimiento_ruleta(lista);
		resultado(lista,ganador,num,c,paridad);
		cout<<endl;
		cout<<"|1| VOLVER A INTENTAR"<<endl;
		cout<<"|0| SALIR "<<endl;
		cout<<"INGRESE OPCION: ";
		cin>>op;
		
	}while(op!=0);
}

void iniciar_lista(tlista &lista)
{
	lista.inicio=NULL;
	lista.fin=NULL;
	lista.cant=0;
}

void crear_nodo(pnodo &nuevo)
{
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		nuevo->num=0;
		nuevo->sig=NULL;
		nuevo->ant=NULL;
	}
}

void agregar_final(tlista &lista,pnodo &nuevo,int n)
{

	lista.cant++;
	if(lista.inicio==NULL)
	{
		lista.inicio=nuevo;
		lista.fin=nuevo;
		nuevo->color='v';
		lista.fin->sig=lista.inicio;
		lista.inicio->ant=lista.fin;
	}
	else
	{
		nuevo->num=n;
		lista.fin->sig=nuevo;
		nuevo->ant=lista.fin;
		nuevo->sig=lista.inicio;
		lista.inicio->ant=nuevo;
		lista.fin=nuevo;
		if(nuevo->num%2==0)
		{
			nuevo->color='n';
		}
		else
		{
			nuevo->color='r';
		}
	}
}

void crear_ruleta(tlista &lista)
{
	pnodo i,nuevo;
	srand(time(NULL));
	while(lista.cant<37)
	{
		int ale=rand() % 37;
		if(lista.inicio==NULL)
		{
			crear_nodo(nuevo);
			agregar_final(lista,nuevo,ale);
		}
		else
		{
			for(i=lista.inicio;i!=lista.fin&&i->num!=ale;i=i->sig);
			if(i==lista.fin)
			{
				if(lista.fin->num!=ale)
				{
					crear_nodo(nuevo);
					agregar_final(lista,nuevo,ale);
				}
			}
		}
	}
}

pnodo movimiento_ruleta(tlista lista)
{
	int i=0;
	pnodo k=lista.inicio;
	srand(time(NULL));
	int ale=rand() % 100;
	if(ale%2==0)
	{
		while(i<=ale)
		{
			k=k->sig;
			i++;
		}
	}
	else
	{
		while(i<=ale)
		{
			k=k->ant;
			i++;
		}
	}
	
	return k;
}

void resultado(tlista lista,pnodo ganador,int num,char c,int paridad)
{
	int premio=0;
	if(num==ganador->num)
	{
		cout<<"EL NUMERO QUE TOCO ES: "<<ganador->num<<endl;
		cout<<"GANASTE: $10.000"<<endl;
		premio=premio+10000;
	}
	else
	{
		cout<<"EL NUMERO QUE TOCO ES: "<<ganador->num<<endl;
		cout<<"NO LE ACERTASTE AL NUMERO"<<endl;
	}
	
	if(c==ganador->color)
	{
		cout<<"ACERTASTE AL COLOR"<<endl;
		cout<<"GANASTE: $10.000"<<endl;
		premio=premio+10000;
	}
	else
	{
		cout<<"NO ACERTASTE AL COLOR"<<endl;
	}
	if(ganador->num%2==0&&paridad==1)
	{
		cout<<"EL NUMERO ES PAR"<<endl;
		cout<<"GANASTE: $3.000"<<endl;
		premio=premio+3000;
	}
	else
	{
		if(paridad==2)
		{
			cout<<"EL NUMERO ES IMPAR"<<endl;
			cout<<"GANASTE: $3.000"<<endl;
			premio=premio+3000;
		}
		else
			cout<<"NO ACERTASTE A LA PARIDAD"<<endl;
	}
	cout<<"GANASTE EN TOTAL: "<<premio<<endl;
}

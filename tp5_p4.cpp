#include <iostream>
using namespace std;
typedef struct tpila *ppila;
typedef struct tpila{
	int dato;
	ppila ant;
	ppila sig;
};
void iniciar_pila(ppila &p);
void crear_nodo(ppila &nuevo,int valor);
void agregar_pila(ppila &p,int nuevo);
int quitar_pila(ppila &p);
int tope_pila(ppila p);
bool pila_vacia(ppila p);
main()
{ 
	ppila p;
	int num,n,salida=0;
	cout << "Ingrese un numero:";
	cin >> num;
	n=num;
	iniciar_pila(p);
	while (num>0)
	{ 
		agregar_pila(p,num%10);
		num=num/10;
	}
	while (pila_vacia(p)!=true)
		salida=salida*10+quitar_pila(p);
	if (n==salida)
		cout << salida << endl;
	else
		cout <<"Es num solo: "<<salida << endl;
}
void iniciar_pila(ppila &p)
{
	p=NULL;
}
void crear_nodo(ppila &nuevo,int valor)
{
	nuevo=new tpila;
	if (nuevo!=NULL)
	{ 
		nuevo->dato=valor;
		nuevo->ant=NULL;
		nuevo->sig=NULL;
	}
}

void agregar_pila(ppila &p,int valor)
{ 
	ppila nuevo;
	crear_nodo(nuevo,valor);
	if (nuevo==NULL)
		cout << "PILA LLENA" << endl;
	else
	{
		if(p==NULL)
		{
			p=nuevo;
		}
		else
		{
			nuevo->sig=p;
			p->ant=nuevo;
			p=nuevo;
		}
	}
}
int quitar_pila(ppila &p)
{ 	int extraido;
	ppila nodo;
	if (pila_vacia(p)==true)
		extraido=0;
	else
	{ extraido=p->dato;
		nodo=p;
		p=p->sig;
		if (p!=NULL)
		{ 
			p->ant=NULL;
			nodo->sig=NULL;
		}
		delete(nodo);
	}
	return extraido;
}
int tope_pila(ppila p)
{ 
	int tope;
	if (pila_vacia(p)==true)
		tope=0;
	else
		tope=p->dato;
	return tope;
}
bool pila_vacia(ppila p)
{
	return p==NULL;
}

#include <iostream>
#include <string.h>

using namespace std;

#include "tda_cola_tp7_p6_a_1.hpp"

typedef char tcad [20];

void menu_op(int &op);
void menu(pnodo &c,int op);
void cargar_cola(pnodo &c,tcad cad);
void convertir_mayus(pnodo c);
void convertir_minus(pnodo c);
void listar_quitar(pnodo &c);
main()
{
	int op;
	pnodo c;
	iniciar_lista(c);
	do
	{
		menu_op(op);
		menu(c,op);
		system("pause");
		system("cls");
	}while(op!=0);
}

void menu_op(int &op)
{
	cout<<"|1| AGREGAR CADENA"<<endl;
	cout<<"|2| EN MAYUSCULA"<<endl;
	cout<<"|3| EN MINUSCULA"<<endl;
	cout<<"|4| VER LISTA QUITAR"<<endl;
	cout<<"|5| VER LISTA"<<endl;
	cout<<"INGRESE OPCION: ";
	cin>>op;
}

void menu(pnodo &c,int op)
{
	tcad cad;
	switch(op)
	{
	case 1:
		cout<<"INGRESE LA FRASE A CONVERTIR: ";
		cin>>cad;
		cargar_cola(c,cad);
		break;
	case 2:
		convertir_mayus(c);
		break;
	case 3:
		convertir_minus(c);
		break;
	}
}

void cargar_cola(pnodo &c,tcad cad)
{
	pnodo n;
	int i;
	int longitud=strlen(cad);
	for(i=0;i<=longitud;i++)
	{
		crear_nodo(n,cad[i]);
		agregar_final(c,n);
	}
}

void convertir_mayus(pnodo c)
{
	int k=0;
	char aux;
	tcad cad2;
	do{
		aux=quitar_inicio(c);
		if((aux>='a' && aux<='z') && aux!=' '&& aux!='*')
		{
			cad2[k]=aux-32;
		}
		k++;
	}while(aux!='*');
	
	cout<<"MAYUSCULAS: "<<cad2<<endl;
}

void convertir_minus(pnodo c)
{
	int k=0;
	char aux;
	tcad cad2;
	do{
		aux=quitar_inicio(c);
		if((aux>='A' && aux<='Z') && aux!=' '&& aux!='*')
		{
			cad2[k]=aux+32;
		}
		k++;
	}while(aux!='*');
	
	cout<<"MINUSCULAS: "<<cad2<<endl;
}

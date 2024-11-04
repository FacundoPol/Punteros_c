#include <iostream>

using namespace std;

#include "tda_bicola_salida_rest.hpp"

void menu_op(int &op);
void menu(tbicola &c,int op);
main()
{
	int op;
	tbicola c;
	iniciar_bicola(c);
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
	cout<<"|1| AGREGAR COLA"<<endl;
	cout<<"|2| QUITAR COLA"<<endl;
	cout<<"|3| PRIMERO COLA"<<endl;
	cout<<"|4| ULTIMO COLA"<<endl;
	cout<<"|5| INGRESE OPCION: ";
	cin>>op;
}

void menu(tbicola &c,int op)
{
	int n;
	char opcion;
	switch(op)
	{
	case 1:
		cout<<"Ingrese caracter agregar: ";
		cin>>n;
		cout<<"INGRESAR POR ULTIMO (U) O FRENTE (F): ";
		cin>>opcion;
		if(opcion=='U' || opcion=='u')
			agregar_bicola(c,n,true);
		else
			agregar_bicola(c,n,false);
		
		break;
	case 2:
		cout<<"NUMERO QUITADO DE COLA: "<<quitar_bicola(c)<<endl;
		break;
	case 3:
		cout<<"PRIMERO COLA: "<<primero_bicola(c)<<endl;
		break;
	case 4:
		cout<<"ULTIMO COLA: "<<ultimo_bicola(c)<<endl;
		break;
	}
}

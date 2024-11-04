#include <iostream>

using namespace std;

//#include "tda_cola_tp7_p6_a_1.hpp"
#include "tda_cola_tp7_p6_a_1.hpp"

void menu_op(int &op);
void menu(pnodo &c,int op);
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
	cout<<"|1| AGREGAR COLA"<<endl;
	cout<<"|2| QUITAR COLA"<<endl;
	cout<<"|3| PRIMERO COLA"<<endl;
	cout<<"|4| ULTIMO COLA"<<endl;
	cout<<"|5| INGRESE OPCION: ";
	cin>>op;
}

void menu(pnodo &c,int op)
{
	pnodo n;
	switch(op)
	{
	case 1:
		crear_nodo(n);
		agregar_final(c,n);
		break;
	case 2:
		cout<<"NUMERO QUITADO DE COLA: "<<quitar_inicio(c)<<endl;
		break;
	case 3:
		cout<<"PRIMERO COLA: "<<primero_lista(c)<<endl;
		break;
	case 4:
		cout<<"ULTIMO COLA: "<<ultimo_lista(c)<<endl;
		break;
	}
}

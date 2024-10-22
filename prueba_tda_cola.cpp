#include <iostream>

using namespace std;

//#include "tda_cola_tp7_p3.hpp"
//#include "tda_cola_tp7_p1.hpp"
//#include "tda_cola_tp7_p1_v2.hpp"
//#include "tda_cola_tp7_p1_v3.hpp"
//#include "tda_cola_tp7_p2.hpp"
//#include "tda_cola_prior_almacenamiento.hpp"
//#include "tda_cola_tp7_p4.hpp"
#include "tda_cola_tp7_p4_v2.hpp"

void menu_op(int &op);
void menu(tcola &c,int op);
main()
{
	int op;
	tcola c;
	iniciar_cola(c);
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

void menu(tcola &c,int op)
{
	int n;
	switch(op)
	{
	case 1:
		cout<<"Ingrese caracter agregar: ";
		cin>>n;
		agregar_cola(c,n);
		break;
	case 2:
		cout<<"NUMERO QUITADO DE COLA: "<<quitar_cola(c)<<endl;
		break;
	case 3:
		cout<<"PRIMERO COLA: "<<primero_cola(c)<<endl;
		break;
	case 4:
		cout<<"ULTIMO COLA: "<<ultimo_cola(c)<<endl;
		break;
	}
}

#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#include "tda_cola_tp7_p6_a_2.hpp"

typedef char tcad [30];

float convertir(pnodo &c,tcad cad);

main()
{
	tcad cad;
	pnodo c;
	iniciar_lista(c);
	cout<<"INGRESAR NUMERO: ";
	cin>>cad;
	cout<<"TOTAL: "<<convertir(c,cad)<<endl;
}

float convertir(pnodo &c,tcad cad)
{
	float total=0;
	float resultado;
	float num;
	int i=2;
	int aux=strlen(cad);
	while(i<=aux)
	{
		switch(cad[i])
		{
		case '1':
			agregar_inicio(c,1);
			break;
		case '2':
			agregar_inicio(c,2);
			break;
		case '3':
			agregar_inicio(c,3);
			break;
		case '4':
			agregar_inicio(c,4);
			break;
		case '5':
			agregar_inicio(c,5);
			break;
		case '6':
			agregar_inicio(c,6);
			break;
		case '7':
			agregar_inicio(c,7);
			break;
		case '8':
			agregar_inicio(c,8);
			break;
		case '9':
			agregar_inicio(c,9);
			break;
		}
		i++;
	}
	cout<<"PRIMERO: "<<primero_lista(c)<<endl;
	cout<<"ULTIMO: "<<primero_lista(c)<<endl;
	i=1;
	while(c!=NULL)
	{
		num=quitar_final(c);
		resultado=num*pow(10,-(i));
		total=resultado+total;
		i++;
	}
	
	return total;
}

#include <iostream>

using namespace std;

#include "tda_bicola_salida_rest.hpp"

int invertir_digitos(tbicola &c,int n);
int fibo(tbicola &c,int termino);

main()
{
	int num;
	tbicola c;
	iniciar_bicola(c);
	cout<<"INGRESE EL NUMERO: ";
	cin>>num;
	
	
	//cout<<fibo(c,num)<<endl;
	
	cout<<invertir_digitos(c,num)<<endl;
}

int fibo(tbicola &c,int termino)
{
	int f,a;
	if(termino == 1 || termino == 2)
	{
		f=1;
	}
	else
	{
		agregar_bicola(c,1,false);
		agregar_bicola(c,1,false);
		while(termino>3)
		{
			a = quitar_bicola(c);
			f = quitar_bicola(c)+a;
			agregar_bicola(c,a,false);
			agregar_bicola(c,f,false);
			termino--;
		}
		
		f=quitar_bicola(c) + quitar_bicola(c);
		
	}
	
	return f;
}

int invertir_digitos(tbicola &c,int num)
{
	int aux;	
	while(num!=0)
	{
		aux=num % 10;
		agregar_bicola(c,aux,true);
		
		num = num / 10;
	}
	aux=0;
	while(bicola_vacia(c)!=true)
	{
		num = quitar_bicola(c);
		aux = aux * 10 + num;
	}
	
	return aux;
}

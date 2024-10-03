#include <iostream>

using namespace std;

#include "tp5_p2_d.hpp"

main()
{
	int c;
	float n;
	tpila p;
	iniciar_pila(p);
	while(pila_llena(p)!=true)
	{
		cout<<"Agregar a pila: ";
		cin>>n;
		agregar_pila(p,n);
	}
	cout<<"TOPE PILA: "<<tope_pila(p)<<endl;
	
	
	cout<<"MOSTRAR PILA ( 1:SI - 2:NO ): ";
	cin>>c;
	if(c==1)
	{
		while(pila_vacia(p)!=true)
		{
			cout<<quitar_pila(p)<<endl;
		}
	}
}


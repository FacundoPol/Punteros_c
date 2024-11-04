#include <iostream>
#include <string.h>
using namespace std;

#include "tda_bicola_salida_rest_char.hpp"

typedef char tcad [10];

bool capicua(tbicola &c,tcad cad);

main()
{
	tcad cad;
	tbicola c;
	iniciar_bicola(c);
	cout<<"INGRESE EL CADENA: ";
	cin>>cad;
	
	if(capicua(c,cad)==true)
		cout<<"ES CAPICUA"<<endl;
	else
	   cout<<"NO ES CAPICUA"<<endl;
}

bool capicua(tbicola &c,tcad cad)
{
	int i;
	char l;
	bool cap=true;
	l=strlen(cad);
	for(i=0;i<l;i++)
		agregar_bicola(c,cad[i],false);
	i=0;
	while(bicola_vacia(c)!=true && cap == true)
	{
		int aux;
		aux=quitar_bicola(c);
		if(cad[i]!=aux)
			cap=false;
		
		i++;
	}
	
	return cap;
}

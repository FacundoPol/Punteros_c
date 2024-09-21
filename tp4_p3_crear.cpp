#include <iostream>
using namespace std;

#include "tp4_p3.hpp"

main()
{
	ttriangulo t;
	crear_tringulo(t);
	if(validar(t)==true)
		cout<<"ES VALIDO"<<endl;
	else
		cout<<"NO ES VALIDO"<<endl;
	
	tipo(t);
	
	if(rectangulo(t)==true)
		cout<<"ES RECTANGULO"<<endl;
	else
		cout<<"NO ES RECTANGULO"<<endl;
}

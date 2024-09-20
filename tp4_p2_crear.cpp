#include <iostream>

using namespace std;
#include "tp4_p2.hpp"

main()
{
	tangulo ang;
	crear_angulo(ang);
	if(validar_angulo(ang)==true)
		cout<<"ANGULO VALIDO"<<endl;
	else
		cout<<"ANGULO NO VALIDO"<<endl;
	
	tipo_angulo(ang);
	
	cout<<"LA CANTIDA DDE RADIANES ES: "<<radianes(ang)<<endl;
}

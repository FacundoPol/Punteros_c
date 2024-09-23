#include <string.h>

const int max=10;
const int mid=max/2;

typedef int tpila[max];

void iniciar_pila(tpila &p)
{
	p.[mid]=-1;
}

bool pila_llena(tpila p)
{
	return p[mid]==max-1;
}

void agregar_pila(tpila &p,int nuevo)
{
	if(pila_llena(p)==true)
		cout<<"PILA LLENA"<<endl;
	else
	{
		p[m]=p[m]+1;
		p[p[m]]=nuevo;
	}
}



tcad cad;


bool verificacion(tcad cad,tpila p)
{
	int i=0;
	while(i<=strlen(cad))
	{
		if(cad[i]=='(')
		{
			agregar_pila(p,cad[i]);
		}
		else
		{
			if(cad[i]==')')
			{
				quitar_pila(p);
			}
		}
	}
	
	if(pila_vacia(p)==true)
		return true;
	else
		return false;
}

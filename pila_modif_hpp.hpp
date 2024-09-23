const int max_p=10;
typedef int tpila [max_p];

void iniciar_pila(tpila &p)
{
	p[max_p-1]=-1;
}

bool pila_llena(tpila p)
{
	return p[max_p-1]==max_p-2;
}

void agregar_pila(tpila &p,int nuevo)
{
	if(pila_llena(p)==true)
		cout<<"PILA LLENA"<<endl;
	else
	{
		p[max_p-1]=p[max_p-1]+1;
		p[p[max_p]-1]=nuevo;
	}
}

bool pila_vacia(tpila p)
{
	return p[max_p-1]==-1;
}

int tope_pila(tpila p)
{
	int consultado;
	
	if(pila_vacia(p)==true)
		consultado = 0;
	else
	{
		consultado=p[p[max_p-1]];
	}
}

int quitar_pila(tpila &p)
{
	int extraido;
	if(pila_vacia(p)==true)
		extraido=0;
	else
	{
		extraido=p[p[max_p-1]];
		p[p[max_p-1]]=p[p[max_p-1]]-1;
	}
}

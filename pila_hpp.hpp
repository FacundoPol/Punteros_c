cons int max=5;

typedef int vpila [max_p];
typedef struct tpila{
	vpila dato;
	int cima;
};
void iniciar_pila(tpila &p)
{
	p.cima=-1;
}


void agregar_pila(tpila &p,int nuevo)
{
	if(pila_llena(p)==true)
		cout<<"PILA LLENA"<<endl;
	else
	{
		p.cima=p.cima+1;
		p.dato[p.cima]=nuevo;
	}
}

bool pila_llena(tpila p)
{
	return p.cima==max_p-1;
}

int quitar_pila(tpila &p)
{
	int extraido;
	if(pila_vacia(p)==true)
	{
		extraido=0;
	}
	else
	{
		extraido=p.datos[p.cima];
		p.cima=p.cima-1;
	}
	
	return extraido;
}

bool pila_vacia(tpila p)
{
	return pila.cima==-1;
}

int tope_pila(tpila p)
{
	int consultado;
	
	if(pila_vacia(p)==true)
		consultado=0;
	else
	{
		consultado=p.datos[p.cima];
	}
	
	return consultado;
}

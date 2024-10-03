const int m=5;
typedef char tdato[m];
typedef struct tpila{
	tdato dato1;
	tdato dato2;
	int cima1;
	int cima2;
};

void iniciar_pila(tpila &p)
{
	p.cima1=-1;
	p.cima2=-1;
}

bool pila_llena(tpila p)
{
	return p.cima2==m-1;
}

void agregar_pila(tpila &p,char nuevo)
{
	if(pila_llena(p)!=true)
	{
		if(cima1<m-1)
		{
			cima1=cima1+1;
			dato1[cima1]=nuevo;
		}
		else
		{
			cima2=cima2+1;
			dato2[cima2]=nuevo;
		}
	}
}

bool pila_vacia(tpila p)
{
	return p.cima1=-1;
}

char quitar_pila(tpila &p)
{
	char extraido;
	if(pila_vacia(p)!=true)
	{
		if(p.cima2>-1)
		{
			extraido=p.dato2[p.cima2];
			p.cima2=p.cima2-1;
		}
		else
		{
			extraido=p.dato1[p.cima1];
			p.cima1=p.cima1-1;
		}
	}
	return extraido;
}

char tope_pila(tpila p)
{
	char aux='@';
	if(pila_vacia(p)!=true)
	{
		if(p.cima2>=0)
			aux=p.dato2[p.cima2];
		else
			aux=p.dato1[p.cima1];
	}
	
	return aux;
}

const int m=5;

typedef float tcontenedor[m];

typedef struct tpila{
	tcontenedor c1;
	tcontenedor c2;
	int cima;
};

void iniciar_pila(tpila &p)
{
	p.cima=-1;
}

bool pila_llena(tpila p)
{
	return p.cima==2*m-1;
}

bool pila_vacia(tpila p)
{
	return p.cima==-1;
}

void agregar_pila(tpila &p,float nuevo)
{
	if(pila_llena(p)!=true)
	{
		if(p.cima<m-1)
		{
			p.cima=p.cima+1;
			p.c1[p.cima]=nuevo;
		}
		else
		{
			p.cima=p.cima+1;
			p.c2[p.cima-m]=nuevo;
		}
	}
	else
	   cout<<"PILA LLENA"<<endl;
}

float quitar_pila(tpila &p)
{
	float extraido=0;
	if(pila_vacia(p)!=true)
	{
		if(p.cima>m)
		{
			extraido=p.c2[p.cima-m];
			p.cima=p.cima-1;
		}
		else
		{
			extraido=p.c1[p.cima];
			p.cima=p.cima-1;
		}
	}
	return extraido;
}

float tope_pila(tpila p)
{
	if(p.cima<m)
		return p.c1[p.cima];
	else
		return p.c2[p.cima-m];
}

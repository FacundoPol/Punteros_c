const int m=6;

typedef int tcontenedor[m];
typedef struct tpila{
	tcontenedor c1;
	tcontenedor c2;
	tcontenedor c3;
};

void iniciar_pila(tpila &p)
{
	p.c1[m-1]=-1;
}

bool pila_llena(tpila p)
{
	return p.c1[m-1]==3*m-2;
}

void agregar_pila(tpila &p,int nuevo)
{
	if(pila_llena(p)!=true)
	{
		p.c1[m-1]=p.c1[m-1]+1;
		if(p.c1[m-1]<m)
		{
			p.c3[p.c1[m-1]]=nuevo;
		}
		else
		{
			if(p.c1[m-1]<m*2)
			{
				p.c2[p.c1[m-1]-m]=nuevo;
			}
			else
			{
				p.c1[p.c1[m-1]-m*2]=nuevo;
			}
		}
	}
}

bool pila_vacia(tpila p)
{
	return p.c1[m-1]==-1;
}

int quitar_pila(tpila &p)
{
	int extraido;
	if(pila_vacia(p)!=true)
	{
		if(p.c1[m-1]>=m*2)
		{
			extraido=p.c1[p.c1[m-1]-m*2];
			p.c1[m-1]= p.c1[m-1] - 1;
		}
		else
		{
			if(p.c1[m-1]>=m)
			{
				extraido=p.c2[p.c1[m-1]-m];
				p.c1[m-1]=p.c1[m-1]-1;
				
			}
			else
			{
				extraido=p.c3[p.c1[m-1]];
				p.c1[m-1]=p.c1[m-1]-1;
				
			}
		}
	}
	else
	   extraido=0;
	
	return extraido;
}

int tope_pila(tpila p)
{
	int retornado;
	if(pila_vacia(p)!=true)
	{
		if(p.c1[m-1]<m)
		{
			retornado=p.c3[p.c1[m-1]];
		}
		else
		{
			if(p.c1[m-1]<m*2)
			{
				retornado=p.c2[p.c1[m-1]-m];
			}
			else
			{
				retornado=p.c1[p.c1[m-1]-m*2];
			}
		}
	}
	
	return retornado;
}

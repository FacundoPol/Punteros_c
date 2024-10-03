const int m=5;

typedef int tpila[m];

void iniciar_pila(tpila &p)
{
	p[0]=0;
}

bool pila_llena(tpila p)
{
	return p[0]==m-1;
}

void agregar_pila(tpila &p,int nuevo)
{
	if(pila_llena(p)==false)
	{
		p[0]=p[0]+1;
		p[p[0]]=nuevo;
	}
	else
		cout<<"PILA LLENA"<<endl;
}

bool pila_vacia(tpila p)
{
	return p[0]==0;
}

int quitar_pila(tpila &p)
{
	int extraido;
	if(pila_vacia(p)==false)
	{
		extraido=p[p[0]];
		p[0]--;
	}
	else
	   extraido=0;
	return extraido;
}

int tope_pila(tpila p)
{
	if(pila_vacia(p)!=true)
		return p[p[0]];
	else
		return 0;
}


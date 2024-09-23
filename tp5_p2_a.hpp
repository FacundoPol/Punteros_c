const int mp=20;

typedef char tcontenedor [mp];
typedef struct tpila{
	tcontenedor dato;
	int cima;
};

void iniciar_pila(tpila &p)
{
	p.cima=-1;
}

bool pila_llena(tpila p)
{
	return p.cima==mp-1;
}

void agregar_pila(tpila &p,char nuevo)
{
	if(pila_llena(p)==true)
		cout<<"PILA LLENA"<<endl;
	else
	{
		p.cima=p.cima+1;
		p.dato[p.cima]=nuevo;
	}
}

bool pila_vacia(tpila p)
{
	return p.cima==-1;
}

char quitar_pila(tpila &p)
{
	char extraido;
	if(pila_vacia(p)==true)
		extraido='0';
	else
	{
		extraido=p.dato[p.cima];
		p.cima--;
	}
	
	return extraido;
}

char tope_pila(tpila p)
{
	char contenedor;
	
	if(pila_vacia(p)==true)
		contenedor='0';
	else
		contenedor=p.dato[p.cima];
	
	return contenedor;
}

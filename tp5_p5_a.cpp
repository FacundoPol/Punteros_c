typedef struct tpila *ppila;
typedef struct tpila{
	int dato;
	ppila sig;
};

void iniciar_pila(ppila &p)
{
	p=NULL;
}

void crear_nodo(ppila &nuevo)
{
	nuevo=new tpila;
	{
		cout<<"INGRESE DATO: ";
		cin>>nuevo->dato;
		nuevo->sig=NULL;
	}
}

void agregar_pila(ppila &p,ppila nuevo)
{
	if(nuevo==NULL)
		cout<<"PILA LLENA"<<endl;
	else
	{
		if(p==NULL)
		{
			p=nuevo;
		}
		else
		{
			nuevo->sig=p;
			p=nuevo;
		}
	}
}

bool pila_vacia(ppila p)
{
	return p==NULL;
}

int quitar_pila(ppila &p)
{
	int extraido;
	ppila nodo;
	if(pila_vacia(p)!=true)
	{
		extraido=p->dato;
		nodo=p;
		p=p->sig;
		if(p!=NULL)
			nodo->sig=NULL;
		delete(nodo);
	}
	else
	   extraido=0;
	
	return extraido;
}

int tope_pila(ppila p)
{
	int tope;
	if(pila_vacia!=true)
		tope=p->dato;
	else
	   cout<<"PILA VACIA"<<endl;
	
	return tope;
}

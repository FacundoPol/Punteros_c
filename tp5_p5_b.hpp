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
	if(nuevo!=NULL)
	{
		cout<<"INGRESE DATO: ";
		cin>>nuevo->dato;
		nuevo->sig=nuevo;
	}
}

bool pila_vacia(ppila p)
{
	return p==NULL;
}

void agregar_pila(ppila &p,ppila nuevo)
{
	ppila i;
	if(nuevo!=NULL)
	{
		if(p==NULL)
		{
			p=nuevo;
		}
		else
		{
			for(i=p;i->sig!=NULL;i=i->sig);
			i->sig=nuevo;
		}
	}
	else
	   cout<<"PILA LLENA"<<endl;
}

int quitar_pila(ppila &p)
{
	int extraido;
	ppila aux,i;
	if(pila_vacia(p)!=true)
	{
		for(i=p;i->sig!=NULL;i=i->sig);
		extraido=i->dato;
		aux=i;
		i=i->sig;
		if(p!=NULL)
			aux->sig=NULL;
		delete(aux);
		else
			extraido=-99;
	}
	
	return extraido;
}

int tope_pila(ppila p)
{
	int tope;
	ppila i;
	if(pila_vacia(p)!=true)
	{
		for(i=p;i->sig!=NULL;i=i->sig);
		tope=i->dato;
	}
	else
	   cout<<"PILA VACIA"<<endl;
}

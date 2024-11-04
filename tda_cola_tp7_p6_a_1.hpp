typedef struct tnodo *pnodo;
typedef struct tnodo{
	char dato;
	pnodo sig;
};

void iniciar_lista(pnodo &lista)
{
	lista=NULL;
}

void crear_nodo(pnodo &nuevo,char d)
{
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		nuevo->dato=d;
		nuevo->sig=NULL;
	}
	else
	   cout<<"LA MEMORIA ESTA LLENA"<<endl;
}

void agregar_final(pnodo &lista,pnodo nuevo)
{
	pnodo i;
	if(lista==NULL)
		lista=nuevo;
	else
	{
		for(i=lista;i->sig!=NULL;i=i->sig);
		i->sig=nuevo;
	}
}

char quitar_inicio(pnodo &lista)
{
	pnodo extraido;
	if(lista==NULL)
		extraido=NULL;
	else
	{
		extraido=lista;
		lista=lista->sig;
		extraido->sig=NULL;
	}
	
	if(lista!=NULL)
		return extraido->dato;
	else
		return '*';
	
	delete(extraido);
	extraido=NULL;
}

int primero_lista(pnodo &lista)
{
	int pri;
	if(lista==NULL)
		pri=-999;
	else
		pri=lista->dato;
	
	return pri;
}

int ultimo_lista(pnodo &lista)
{
	pnodo i;
	int ult;
	if(lista==NULL)
		ult=-999;
	else
	{
		for(i=lista;i->sig!=NULL;i=i->sig);
		ult=i->dato;
	}
	
	return ult;
}

void listar(pnodo &lista)
{
	pnodo i;
	
	for(i=lista;i!=NULL;i=i->sig)
		cout<<i->dato;
}


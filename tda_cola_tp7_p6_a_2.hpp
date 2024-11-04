typedef struct tnodo *pnodo;
typedef struct tnodo{
	int dato;
	pnodo sig;
	pnodo ant;
};

void iniciar_lista(pnodo &lista)
{
	lista=NULL;
}

void agregar_inicio(pnodo &lista,int num)
{
	pnodo nuevo;
	nuevo=new tnodo;
	nuevo->dato=num;
	nuevo->sig=NULL;
	nuevo->ant=NULL;
	
	if(lista==NULL)
		lista=nuevo;
	else
	{
		nuevo->sig=lista;
		lista->ant=nuevo;
		lista=nuevo;
	}
}

int quitar_final(pnodo &lista)
{
	pnodo i;
	pnodo extraido;
	if(lista==NULL)
		extraido=NULL;
	else
	{
		for(i=lista;i->sig!=NULL;i=i->sig);
		extraido=i;
		(extraido->ant)->sig=NULL;
		extraido->ant=NULL;
	}
	
	if(extraido==NULL)
		return -999;
	else
		return extraido->dato;
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

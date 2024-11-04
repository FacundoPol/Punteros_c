
typedef struct tnodo *pnodo;
typedef struct tnodo{
	int dato;
	pnodo sig;
	pnodo ant;
};
typedef struct tcola{
	pnodo inicio;
	pnodo fin;
	
};

void iniciar_bicola(tcola &c)
{
	c.inicio=NULL;
	c.fin=NULL;
}


void crear_nodo(pnodo &nuevo,int num)
{
	nuevo=new tnodo;
	if(nuevo!=NULL)
	{
		nuevo->dato=num;
		nuevo->sig=NULL;
		nuevo->ant=NULL;
	}
	else
	   cout<<"SI VES ESTE CARTEL LA PC TE ESTA POR EXPLOTAR!!! CORREEE!!!"<<endl;
	
}

void agregar_bicola(tcola &c,pnodo nuevo,bool seleccion)
{
	if(c.inicio==NULL)
	{
		c.inicio=nuevo;
		c.fin=nuevo;
	}
	else
	{
		if(selecion==true)//frente
		{
			nuevo->sig=c.inicio;
			c.inicio->ant=nuevo;
			c.inicio = nuevo;
		}
		else
		{
			c.fin->sig=nuevo;
			nuevo->ant=c.fin;
			c.fin=nuevo;
		}
	}
}

int quitar_bicola(tcola &c)
{
	pnodo ex;
	if(c.inicio==NULL)
		ex=NULL;
	else
	{
		ex=lista.incio;
		lista.inicio=ex->sig;
		lista.inicio->ant=NULL;
		ex->sig=NULL;
	}
	
	if(ex!=NULL)
	   return ex->dato;
	else
		return -999;
}

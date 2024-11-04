
const int MAX = 10;
typedef char tcontenedor[MAX];
typedef struct tbicola{
	tcontenedor datos;
	int frente;
	int ultimo;
};

int sig(int i)
{
	if(i==MAX-1)
		i=0;
	else
		i++;
	
	return i;
}

int ant(int i)
{
	if(i==0)
		i=MAX-1;
	else
		i--;
	
	return i;
}

void iniciar_bicola(tbicola &c)
{
	c.frente=0;
	c.ultimo=0;
}

bool bicola_llena(tbicola &c)
{
	return c.frente==sig(c.ultimo);
}

bool bicola_vacia(tbicola &c)
{
	return c.frente == c.ultimo;
}

void agregar_bicola(tbicola &c,int nuevo,bool opcion)
{
	if(bicola_llena(c)==true)
		cout<<"COLA LLENA"<<endl;
	else
	{
		if(opcion==true)
		{
			c.ultimo=sig(c.ultimo);
			c.datos[c.ultimo]=nuevo;
		}
		else
		{
			c.datos[c.frente]=nuevo;
			c.frente=ant(c.frente);
		}
	}
}

char quitar_bicola(tbicola &c)
{
	char extraido;
	if(bicola_vacia(c)==true)
		extraido='*';
	else
	{
		c.frente=sig(c.frente);
		extraido=c.datos[c.frente];
	}
	
	return extraido;
}

char primero_bicola(tbicola &c)
{
	char pri;
	if(bicola_vacia(c)==true)
		pri='*';
	else
		pri=c.datos[sig(c.frente)];
	
	return pri;
}

char ultimo_bicola(tbicola &c)
{
	char ult;
	
	if(bicola_vacia(c)==true)
		ult='*';
	else
		ult=c.datos[c.ultimo];
	
	return ult;
}

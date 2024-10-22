const int m = 5;
typedef int contenedor[m];
typedef struct tcola{
	contenedor dato;
	int frente;
	int fin;
};

int sig(int indice)
{
	if(indice==m-1)
		indice=0;
	else
		indice++;
	
	return indice;
}

void iniciar_cola(tcola &c)
{
	c.frente=0;
	c.fin=0;
}

bool cola_llena(tcola c)
{
	return sig(c.fin)==c.frente;
}

bool cola_vacia(tcola c)
{
	return c.fin==c.frente;
}

void agregar_cola(tcola &c,int nuevo)
{
	if(cola_llena(c)==true)
		cout<<"COLA LLENA"<<endl;
	else
	{
		c.fin=sig(c.fin);
		c.dato[c.fin]=nuevo;
	}
}



int quitar_cola(tcola &c)
{
	int extraido;
	if(cola_vacia(c)==true)
	{
		extraido=-999;
	}
	else
	{
		c.frente = sig(c.frente);
		extraido=c.dato[c.frente];
	}
	
	return extraido;
}



int primero_cola(tcola c)
{
	int pri;
	if(cola_vacia(c)==true)
		pri=-999;
	else
		pri=c.dato[sig(c.frente)];
	
	return pri;
}

int ultimo_cola(tcola c)
{
	int ult;
	if(cola_vacia(c)==true)
		ult=-999;
	else
		ult=c.dato[c.fin];
	
	return ult;
}

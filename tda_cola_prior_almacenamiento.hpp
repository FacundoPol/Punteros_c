const int m=5;
typedef int contenedor[m];
typedef struct tcola{
	contenedor dato;
	int frente;
	int ultimo;
	int contador;
};

int sig(int n)
{
	if(n==m-1)
		n=0;
	else
		n++;
	
	return n;
}

void iniciar_cola(tcola &c)
{
	c.frente=0;
	c.ultimo=0;
	c.contador=0;
}

bool cola_llena(tcola c)
{
	return c.contador==m;
}

bool cola_vacia(tcola c)
{
	return c.contador==0;
}


void agregar_cola(tcola &c,int nuevo)
{
	if(cola_llena(c)==true)
		cout<<"COLA LLENA"<<endl;
	else
	{
		c.ultimo=sig(c.ultimo);
		c.dato[c.ultimo]=nuevo;
		c.contador ++;
	}
}

int quitar_cola(tcola &c)
{
	int extraido;
	if(cola_vacia(c)==true)
		extraido='*';
	else
	{
		c.frente=sig(c.frente);
		extraido=c.dato[c.frente];
		c.contador--;
	}
	return extraido;
}

int primero_cola(tcola c)
{
	int pri;
	if(cola_vacia(c)==true)
		pri= '*';
	else
		pri=c.dato[sig(c.frente)];
	
	return pri;
}

int ultimo_cola(tcola c)
{
	int ult;
	if(cola_vacia(c)==true)
		ult='*';
	else
		ult=c.dato[c.ultimo];
	
	return ult;
}

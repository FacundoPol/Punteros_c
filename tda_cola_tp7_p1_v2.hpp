const int m= 5;
typedef int contenedor[m];
typedef int indicadores[2];
typedef struct tcola{
	contenedor dato;
	indicadores indice;
};
void iniciar_cola(tcola &c)
{
	c.indice[0]=0;//frente
	c.indice[1]=0;//final
}

int sig(int n)
{
	if(n==m-1)
		n=0;
	else
		n++;
	
	return n;
}

bool cola_llena(tcola c)
{
	return c.indice[0]==sig(c.indice[1]);
}

bool cola_vacia(tcola c)
{
	return c.indice[1]==c.indice[0];
}

void agregar_cola(tcola &c, int  nuevo)
{
	if(cola_llena(c)==true)
		cout<<"COLA LLENA"<<endl;
	else
	{
		c.indice[1] = sig(c.indice[1]);
		c.dato[c.indice[1]]=nuevo;
	}
}

int quitar_cola(tcola &c)
{
	int extraido;
	if(cola_vacia(c)==true)
		extraido=-999;
	else
	{
		c.indice[0]=sig(c.indice[0]);
		extraido=c.dato[c.indice[0]];
	}
	
	return extraido;
}

int primero_cola(tcola c)
{
	int pri;
	if(cola_vacia(c)==true)
		pri=-999;
	else
		pri=c.dato[sig(c.indice[0])];
	
	return pri;
}

int ultimo_cola(tcola c)
{
	int ult;
	if(cola_vacia(c)==true)
		ult=-999;
	else
		ult=c.dato[c.indice[1]];
	
	return ult;
}

const int m=5;
typedef int tcola[m];

int sig(int n)
{
	if(n==m-1)
		n=2;
	else
		n++;
	
	return n;
}

void iniciar_cola(tcola &c)
{
	c[0]=2;
	c[1]=2;
}

bool cola_llena(tcola c)
{
	return c[0]==sig(c[1]);
}

bool cola_vacia(tcola c)
{
	return c[0]==c[1];
}

void agregar_cola(tcola &c,int nuevo)
{
	if(cola_llena(c)==true)
		cout<<"COLA LLENA"<<endl;
	else
	{
		c[1]=sig(c[1]);
		c[c[1]]=nuevo;
	}
}

int quitar_cola(tcola &c)
{
	int extraido;
	if(cola_vacia(c)==true)
		extraido=-999;
	else
	{
		c[0]=sig(c[0]);
		extraido=c[c[0]];
	}
	return extraido;
}

int primero_cola(tcola c)
{
	int pri;
	if(cola_vacia(c)==true)
		pri=-999;
	else
		pri=c[sig(c[0])];
	
	return pri;
}

int ultimo_cola(tcola c)
{
	int ult;
	if(cola_vacia(c)==true)
		ult=-999;
	else
		ult=c[c[1]];
	
	return ult;
}

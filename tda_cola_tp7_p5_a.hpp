//cola que prioriza el espacio de almacenamiento

cont int MAX=15;
typedef int tcola[MAX];

void iniciar_cola(tcola &c)
{
	c[MAX/2]=0;
	c[MAX/2+1]=0;
}

int ant(int n)
{
	if(n==0)
		n=MAX-1;
	else
	{
		if(n==MAX/2+2)
			n=n-3;
		else
			n--;
	}
	
	return n;
}

bool cola_vacia(tcola c)
{
	return c[MAX/2]==c[MAX/2+1];
}

void agregar_cola(tcola &c,int nuevo)
{
	if(cola_llena(c)==true)
		cout<<"COLA LLENA"<<endl;
	else
	{
		c[MAX/2+1]=ant(c[MAX/2+1]);
		c[c[MAX/2+1]]=nuevo;
	}
}

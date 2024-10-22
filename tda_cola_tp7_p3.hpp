const int m=5;
typedef int contenedor[m];
typedef struct tcola{
	contenedor dato1;
	contenedor dato2;
};

void iniciar_cola(tcola &c)
{
	c.dato1[0]=2; //frente
	c.dato1[1]=2; //ultimo
}

int sig(int n)
{
	if(n>2*m)
		n=2;
	else
		n++;
	
	return n;
}

bool cola_vacia(tcola c)
{
	return c.dato1[0]==c.dato1[1];
}

bool cola_llena(tcola c)
{
	return sig(c.dato1[1])==c.dato1[0];
}

void agregar_cola(tcola &c,int nuevo)
{
	if(cola_llena(c)==true)
		cout<<"LISTA LLENA"<<endl;
	else
	{
		c.dato1[1]=sig(c.dato1[1]);
		if(c.dato1[1]<=m-1)
		{
			c.dato1[c.dato1[1]]=nuevo;
		}
		else
		{
			c.dato2[c.dato1[1]-m]=nuevo;
		}
	}
	
	cout<<"FRENTE: "<<c.dato1[0]<<endl; //frente
	cout<<"ULTIMO: "<<c.dato1[1]<<endl;
}

int quitar_cola(tcola &c)
{
	int extraido;
	if(cola_vacia(c)==true)
		extraido=-999;
	else
	{
		c.dato1[0]=sig(c.dato1[0]);
		if(c.dato1[0]>=m)
			extraido=c.dato2[c.dato1[0]-m];
		else
			extraido=c.dato1[c.dato1[0]];
	}
	
	return extraido;
}

int primero_cola(tcola c)
{
	int pri;
	if(cola_vacia(c)==true)
		pri=-999;
	else
	{
		if(c.dato1[0]>=m)
			pri=c.dato2[sig(c.dato1[0])-m];
		else
			pri=c.dato1[sig(c.dato1[0])];
	}
	
	return pri;
}

int ultimo_cola(tcola c)
{
	int ult;
	if(cola_vacia(c)==true)
		ult=-999;
	else
	{
		if(c.dato1[1]>=m)
			ult=c.dato2[c.dato1[1]-m];
		else
			ult=c.dato1[c.dato1[1]];
	}
	
	return ult;
}


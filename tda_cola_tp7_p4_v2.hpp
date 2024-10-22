const int m=2;
typedef int contenedor [m];
typedef struct tcola{
	contenedor datos1;
	contenedor datos2;
	contenedor datos3;
	int contador;
};

void iniciar_cola(tcola &c)
{
	c.datos3[m-2]=0;//frente
	c.datos3[m-1]=0;//ultimo
	c.contador=0;
}

sig(int n)
{
	if(n==3*m-3)
		n=0;
	else
		n++;
	
	return n;
}

bool cola_llena(tcola c)
{
	return c.contador == 3*m-2;
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
		c.datos3[m-1] = sig(c.datos3[m-1]);
		if(c.contador < m)
			c.datos1[c.datos3[m-1]]=nuevo;
		else
		{
			if(c.contador < m*2)
				c.datos2[c.datos3[m-1]-m]=nuevo;
			else
				c.datos3[c.datos3[m-1]-2*m-2]=nuevo;
		}
		
		c.contador++;
	}
}

int quitar_cola(tcola &c)
{
	int extraido;
	if(cola_vacia(c)==true)
		extraido=-999;
	else
	{
		c.datos3[m-2]=sig(c.datos3[m-2]);
		if(c.contador<m)
			extraido=c.datos1[c.datos3[m-2]];
		else
		{
			if(c.contador<2*m)
				extraido=c.datos2[c.datos3[m-2]-m];
			else
				extraido =c.datos3[c.datos3[m-2]-2*m];
		}
		
		c.contador--;
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
		if(c.contador<m)
			pri=c.datos1[sig(c.datos3[m-2])];
		else
		{
			if(c.contador<2*m)
				pri=c.datos2[sig(c.datos3[m-2]-m)];
			else
				pri=c.datos3[sig(c.datos3[m-2]-2*m)];
		}
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
		if(c.contador<m)
			ult=c.datos1[c.datos3[m-1]];
		else
		{
			if(c.contador < m*2)
				ult=c.datos2[c.datos3[m-1]-m];
			else
				ult=c.datos3[c.datos3[m-1]-2*m];
		}
	}
	
	return ult;
}

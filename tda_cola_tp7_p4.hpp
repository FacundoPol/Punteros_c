const int m=2;
typedef int contenedor [m];
typedef struct tcola{
	contenedor datos1;
	contenedor datos2;
	contenedor datos3;
	int frente;
	int ultimo;
	int contador;
};

void iniciar_cola(tcola &c)
{
	c.frente=0;
	c.ultimo=0;
	c.contador=0;
}

sig(int n)
{
	if(n==3*m-1)
		n=0;
	else
		n++;
	
	return n;
}

bool cola_llena(tcola c)
{
	return c.contador == 3*m;
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
		c.ultimo = sig(c.ultimo);
		if(c.contador < m)
			c.datos1[c.ultimo]=nuevo;
		else
		{
			if(c.contador < m*2)
				c.datos2[c.ultimo-m]=nuevo;
			else
				c.datos3[c.ultimo-2*m]=nuevo;
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
		c.frente=sig(c.frente);
		if(c.contador<m)
			extraido=c.datos1[c.frente];
		else
		{
			if(c.contador<2*m)
				extraido=c.datos2[c.frente-m];
			else
				extraido =c.datos3[c.frente-2*m];
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
			pri=c.datos1[sig(c.frente)];
		else
		{
			if(c.contador<2*m)
				pri=c.datos2[sig(c.frente-m)];
			else
				pri=c.datos3[sig(c.frente-2*m)];
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
			ult=c.datos1[c.ultimo];
		else
		{
			if(c.contador < m*2)
				ult=c.datos2[c.ultimo-m];
			else
				ult=c.datos3[c.ultimo-2*m];
		}
	}
	
	return ult;
}

//Cola que prioriza espacio de alMAXacenaMAXiento

const int MAX=3;
typedef int tcontenedor[MAX];
typedef struct tcola{
	tcontenedor datos1;
	tcontenedor datos2;
	tcontenedor datos3;
};

//iniciar_cola, agregar_cola, anterior y cola_vacía

void iniciar_cola(tcola &c)
{
	c.datos2[MAX-2]=MAX*3-1; //FRENTE
	c.datos2[MAX-1]=MAX*3-1; //ULTIMAXO
}


int ant(int n)
{
	if(n==0)
		n=MAX*3-1;
	else
	{
		if(n==MAX*2) 
			n=MAX*2-3;
		else
			n--;
	}
	
	return n;
}

bool cola_vacia(tcola c)
{
	return c.datos2[MAX-1]==c.datos2[MAX-2];
}

bool cola_llena(tcola c)
{
	return c.datos2[MAX-2]==ant(c.datos2[MAX-1]);
}

void agregar_cola(tcola &c,int nuevo)
{
	if(cola_llena(c)==true)
		cout<<"COLA LLENA"<<endl;
	else
	{
		c.datos2[MAX-1]=ant(c.datos2[MAX-1]);
		if(c.datos2[MAX-1]<MAX)
		{
			c.datos1[c.datos2[MAX-1]]=nuevo;
		}
		else
		{
			if(c.datos2[MAX-1]<MAX*2)
			{
				c.datos2[c.datos2[MAX-1]-MAX]=nuevo;
			}
			else
			{
				c.datos3[c.datos2[MAX-1]-2*MAX]=nuevo;
			}
		}
	}
}

int quitar_cola(tcola &c)
{
	int extraido;
	if(cola_vacia(c)==true)
		extraido=-99;
	else
	{
		c.datos2[MAX-2]=ant(c.datos2[MAX-2]);
		if(c.datos2[MAX-2]<MAX)
			extraido=c.datos1[c.datos2[MAX-2]];
		else
		{
			if(c.datos2[MAX-2]<MAX*2)
				extraido=c.datos2[c.datos2[MAX-2]-MAX];
			else
				extraido=c.datos3[c.datos2[MAX-2]-2*MAX];
		}
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
		if(c.datos2[MAX-2]<MAX)
			pri=c.datos1[ant(c.datos2[MAX-2])];
		else
		{
			if(c.datos2[MAX-2]<MAX*2)
				pri=c.datos2[ant(c.datos2[MAX-2])-MAX];
			else
				pri=c.datos3[ant(c.datos2[MAX-2])-MAX*2];
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
		if(c.datos2[MAX-1]<MAX)
			ult=c.datos1[c.datos2[MAX-1]];
		else
		{
			if(c.datos2[MAX-1]<MAX*2)
				ult=c.datos2[c.datos2[MAX-1]-MAX];
			else
				ult=c.datos3[c.datos2[MAX-1]-MAX*2];
		}
	}
	
	return ult;
}

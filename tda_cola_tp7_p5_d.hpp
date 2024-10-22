//Cola que prioriza espacio de almacenamiento

const int MAX=6;
typedef int tcontenedor[MAX];
typedef struct tcola{
	tcontenedor datos1;
	tcontenedor datos2;
	tcontenedor datos3;
};

//iniciar_cola, agregar_cola, anterior y cola_vacía

void iniciar_cola(tcola &c)
{
	c.datos2[MAX-2]=MAX-1; //FRENTE
	c.datos2[MAX-1]=MAX-1; //ULTIMO
}

void agregar_cola(tcola &c,int nuevo)
{
	if(cola_llena(c)==true)
		cout<<""<<endl;
	else
	{
		c.datos2[MAX-1]=ant(c.datos2[MAX-1]);
		if(c.datos2[MAX-1]<MAX)
			c.datos1[c.datos2[1]]=nuevo;
		else
		{
			if(c.datos2[MAX-1]<MAX*2)
				c.datos2[c.datos2[MAX-1]-MAX]=nuevo;
			else
			{
				c.datos3[c.datos2[MAX-1]-2*MAX]=nuevo;
			}
		}
	}
}

int anterior(int n)
{
	if(n==0)
		n=MAX-1;
	else
	{
		if(n==MAX*2-1 || n==MAX*2-2)
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

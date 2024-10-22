
//Cola que prioriza velocidad de proceso

const int MAX =10;

typedef char tcontenedor [MAX];
typedef struct tindicadores {
	int ind1;
	int ind2;
};
typedef struct tcola{
	tcontenedor dato;
	tindicadores indicador;
};

void iniciar_cola(tcola &c)
{
	c.indicador.ind1=MAX-1;
	c.indicador.ind2=MAX-1;
}

void agregar_cola(tcola &c,char nuevo)
{
	if(cola_llena(c)==true)
		cout<<"COLA LLENA"<<endl;
	else
	{
		c.indicador.ind1 = ant(c.indicador.ind1);
		c.dato[c.indicador.ind1]=nuevo;
	}
}

int anterior(int n)
{
	if(n==0)
		n=MAX-1;
	else
	{
		n--;
	}
}

bool cola_vacia(tcola c)
{
	return c.indicador.ind1 == c.indicador.ind2;
}


//Cola que prioriza velocidad de proceso
	
const int MAX = 5;
typedef int tcontenedor [MAX];
typedef int tindicadores [2];
typedef struct tcola{
	tcontenedor datos1;
	tcontenedor datos2;
	tindicadores indice;
};

//iniciar_cola, agregar_cola, anterior y cola_vacía
	
void iniciar_cola(tcola &c)
{
	c.indice[0]=0;//frente
	c.indice[1]=0;//ultimo
}

void agregar_cola(tcola &c,int nuevo)
{
	if(cola_llena(c)==true)
		cout<<"COLA LLENA"<<endl;
	else
	{
		c.indice[1]=ant(c.indice[1]);
		if(c.indice[1]<m)
			c.datos1[c.indice[1]]=nuevo;
		else
			c.datos2[c.indice[1]-m]=nuevo;
	}
}

int anterior(int n)
{
	if(n==0)
		n=MAX-1;
	else
		n--;
}

bool cola_vacia(tcola c)
{
	return c.indice[0]==c.indice[1];
}

const int maxc=20;
typedef int telementos[maxc];

typedef struct tconjunto{
	telemtos elemen;
	int ocup;
};

void crear_conjunto(tconjunto c)
{
	for(i=0;i<=maxc-1;i++)
	{
		cout<<"Ingrese numero del conjunto: ";
		cin>>c.elemen[i];
	}
}


void diferencia_simetrica(tconjunto a,tconjunto b,tconjunto &c)
{
	crear_vacio(c);
	int i=0;
	while(i<=a.ocup)
	{
		if(pertenece(b,a.elemen[i])!=true)
		{
			agregar_element(c,a.elem[i]);
		}
		i++;
	}
	i=0;
	while(i<=b.ocup)
	{
		if(pertenece(a,b.elemen[i])!=true)
		{
			agregar_element(c,b.elem[i]);
		}
		i++;
	}
	
}

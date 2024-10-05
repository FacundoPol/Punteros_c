const int MAX=5;
typedef float conjunto[MAX];
typedef struct tconjunto{
	conjunto a;
	conjunto b;
};


bool inclusion(tconjunto c)
{
	bool pertenece=true;
	for(i=0;i<=ocupb && pertenece==true;i++)
	{
		if(pertenencia(c.a,c.b[i])==true)
		{
			pertenece=true;
		}
		else
		{
			pertenece=false;
		}
	}
	
	return pertenece;
}

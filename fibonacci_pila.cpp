

int fibo(int termino)
{
	tpila p;
	int f,a;
	if(termino==1||termino==2)
		f=1;
	else
	{
		iniciar_pila(p);
		agregar_pila(p,1);
		agrega_pila(p,1);
		
		while(termino>3)
		{
			a=quitar_pila(p);
			f=quitar_pila(p)+a;
			agregar_pila(p,a);
			agregar_pila(p.f);
		}
		f=quitar(p)+quitar(p);
	}
	
	return f;
}

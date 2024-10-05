

void posfija(tcad interfija)
{
	tcad posfija;
	tpila pila;
	iniciar_pila(p);
	int i=0;
	while(i<strlen(interfija))
	{
		if(interfija[i]<'0'||interfija>'9')
		{
			if(pila_vacia==true)
			{
				agregar_pila(p,interfija[i]);
			}
			else
			{
				if(prioridad(intefija[i],tope_pila(p))==true)
				{
					agregar_pila(p,intefija[i]);
				}
				else
				{
					posfija[i]=quitar_pila(p);
					agregar_pila(p,intefija[i]);
				}
			}
		}
		else
		{
			posfija[i]=intefija[i];
		}
		
		i++;
	}
	
	while(pila_vacia(p)!=true)
	{
		posfija=posfija+quitar_pila(p);
	}
	
	for(k=0;k<strlen(posfija);k++)
		cout<<posfija[k];
}



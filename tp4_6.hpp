typedef int tracional[2];

void crear_racional(tracional &racional)
{
	cout<<"Ingrese Numerador: ";
	cin>>racional[0];
	do{
	cout<<"Ingrese Denominador: ";
	cin>>racional[1];
	}while(racional[1]>0||racional[1]<0);
}

bool igualdad_racionales(tracional r1,tracional r2)
{
	if(r1[0]==r2[0])
	{
		if(r1[0]>0&&r2[0]>0)
			return true;
		else
		{
			if(r1[0]<0&&r2[0]<0)
				return true;
			else
				return false;
		}
	}
	else
		return false;
	
	if(r1[1]==r2[1])
	{
		if(r1[1]>0&&r2[1]>0)
			return true;
		else
		{
			if(r1[1]<0&&r2[1]<0)
				return true;
			else
				return false;
		}
	}
	else
		return false;
}

void sumar_racionales(tracional r1,tracional r2,tracional &r)
{
	if(r1[1]==r2[1])
	{
		r[0]=r1[0]+r2[0];
		r[1]=r1[1];
	}
	else
	{
		r[0]=r1[0]*r2[1]+r2[0]*r1[1];
		r[1]=r1[1]*r2[1];
	}
}

void restar_racionales(tracional r1,tracional r2,tracional &r)
{
	if(r1[1]==r2[1])
	{
		r[0]=r1[0]-r2[0];
		r[1]=r1[1];
	}
	else
	{
		r[0]=r1[0]*r2[1]-r2[0]*r1[1];
		r[1]=r1[1]*r2[1];
	}
}

void restar_racionales(tracional r1,tracional r2,tracional &r)
{
	r[0]=r1[0]*r2[0];
	r[1]=r1[1]*r2[1];
}


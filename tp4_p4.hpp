typedef int vhora [3];

void crear_hora(vhora &hora)
{
	cout<<"Ingrese hora: ";
	cin>>hora[0];
	cout<<"Ingrese minutos: ";
	cin>>hora[1];
	cout<<"Ingrese segundos: ";
	cin>>hora[2];
}

bool validar(vhora hora)
{
	if((hora[0]>24||hora[0]<0)&&(hora[1]>59||hora[1]<0)&&(hora[2]>59||hora[2]<0))
		return false;
	else
		return true;
}

int devolver_m(vhora hora)
{
	m=hora[0]*60;
	m=m+hora[1];
	
	return m;
}

int devolver_s(vhora hora)
{
	s=hora[0]*3600;
	s=s+hora[1]*60;
	s=s+hora[2];
	
	return s;
}

void comparar_h(vhora hora)
{
	vhora hora2;
	crear_hora(hora2);
	if(validar(hora2)==true)
	{
		if(hora[0]>hora2[0])
			cout<<"LA PRIMERA HORA ES MAYOR"<<endl;
		else
		{
			if(hora[0]<hora2[0])
				cout<<"LA SEGUNDA HORA ES MAYOR"<<endl;
			else
			{
				if(hora[1]>hora2[1])
					cout<<"LA PRIMERA HORA ES MAYOR"<<endl;
				else
				{
					if(hora[1]<hora2[1])
						cout<<"LA SEGUNDA HORA ES MAYOR"<<endl;
					else
					{
						if(hora[2]>hora2[2])
							cout<<"LA PRIMERA HORA ES MAYOR"<<endl;
						else
						{
							if(hora[2]<hora2[2])
								cout<<"LA SEGUNDA HORA ES MAYOR"<<endl;
							else
								cout<<"LA DOS HORAS SON IGUALES"<<endl;
						}
					}
				}
			}
		}
	}
	else
	   cout<<"HORA NO VALIDA"<<endl;
}

void sumar_segundo(vhora &hora)
{
	int seg,h,m,s;
	cout<<"Ingrese los segundos a sumar: ";
	cin>>seg;
	if(seg>=3600)
	{
		h=seg/3600;
		seg=seg%3600;
		h=hora[0]+h;
		if(h>23)
			hora[0]=h-24;
		else
			hora[0]=h;
	}
	else
	{
		if(seg>=60)
		{
			m=seg/60;
			seg=seg%60;
			m=hora[1]+m;
			if(m>59)
			{
				hora[1]=m-60;
				hora[0]=hora[0]+1;
				if(hora[0]>23)
					hora[0]=hora[0]-24;
				else
					hora[0]=hora[0];
			}
			else
				hora[1]=m;
		}
		else
		{
			s=seg;
			s=hora[2]+s;
			
			if(s>59)
			{
				hora[1]=hora[1]+1;
				s=s-60;
				if(hora[1]>59)
				{
					hora[0]=hora[0]+1;
					hora[1]=hora[1]-60;
					if(hora[0]>24)
					{
						hora[1]=hora[1]-24;
					}
				}
				
			}
			
			hora[2]=s;
		}
	}
	
}

typedef int vhora [3];

void crear_hora(vhora &hora)
{
	cout<<"Ingrese hora: ";
	cin>>hora.[0];
	cout<<"Ingrese minutos: ";
	cin>>hora.[1];
	cout<<"Ingrese segundos: ";
	cin>>hora.[2];
}

bool validar(vhora hora)
{
	if((hora.[0]>24||hora.[0]<0)&&(hora.[1]>59||hora.[1]<0)&&(hora.[2]>59||hora.[2]<0))
		return false;
	else
		return true;
}

int devolver_m(vhora hora)
{
	m=hora.[0]*60;
	m=m+hora.[1];
	
	return m;
}

int devolver_s(vhora hora)
{
	s=hora.[0]*3600;
	s=s+hora.[1]*60;
	s=s+hora.[2];
	
	return s;
}

void comparar_h(vhora hora)
{
	
}

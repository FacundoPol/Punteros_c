
typedef char tcad [10];

const float pi=3.14f;

typedef struct tangulo{
	int grados;
	int min;
	int seg;
};

void crear_angulo(tangulo &ang);
bool validar_angulo(tangulo ang);
void tipo_angulo(tangulo &ang);
float radianes(tangulo ang);

void crear_angulo(tangulo &ang)
{
	do{
	cout<<"Ingrese grados de angulo: ";
	cin>>ang.grados;
	cout<<"Ingrese minutos de angulo: ";
	cin>>ang.min;
	cout<<"Ingrese segundos de angulo: ";
	cin>>ang.seg;
	}while(validar_angulo(ang)!=true);
}

bool validar_angulo(tangulo ang)
{
	if(ang.grados<0&&ang.grados>360)
		return false;
	else
	{
		if(ang.min<0&&ang.min>60)
			return false;
		else
		{
			if(ang.seg<0&&ang.seg>60)
				return false;
			else
				return true;
		}
	}
}

void tipo_angulo(tangulo &ang)
{
	if(ang.grados<90)
		cout<<"agudo"<<endl;
	else
	{
		if(ang.grados==90&&ang.min==0&&ang.seg==0)
			cout<<"recto"<<endl;
		else
		{
			if(ang.grados>90&&ang.min>0&&ang.seg>0&&ang.grados<180)
				cout<<"obtuso"<<endl;
			else
			{
				cout<<"completos"<<endl;
			}
		}
	}	
}

float radianes(tangulo ang)
{
	return ang.grados*pi/180;
}

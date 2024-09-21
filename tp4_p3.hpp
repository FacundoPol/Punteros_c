#include <math.h>

typedef struct ttriangulo{
	float l1;
	float l2;
	float l3;
};

float potencia(float base,int exponente);
bool rectangulo(ttriangulo tri);
void tipo(ttriangulo tri);
bool validar(ttriangulo tri);
void crear_tringulo(ttriangulo &tri);

void crear_tringulo(ttriangulo &tri)
{
	cout<<"INGRESE PRIMER LADO: ";
	cin>>tri.l1;
	cout<<"INGRESE SEGUNDO LADO: ";
	cin>>tri.l2;
	cout<<"INGRESE TERCER LADO: ";
	cin>>tri.l3;
}

bool validar(ttriangulo tri)
{
	if((tri.l1+tri.l2)>tri.l3)
		return true;
	else
		return false;
}

void tipo(ttriangulo tri)
{
	if(tri.l1>tri.l2&&tri.l2>tri.l3)
		cout<<"TRINGULO ESCALENO"<<endl;
	else
	{
		if(tri.l1==tri.l2&&tri.l2==tri.l3)
			cout<<"TRINGULO EQUILATERO"<<endl;
		else
			cout<<"TRINGULO ISOCELES"<<endl;
	}
}

bool rectangulo(ttriangulo tri)
{
	bool igual;
	if(tri.l1!=tri.l2||tri.l2!=tri.l3||tri.l1!=tri.l3)
	{
		if(tri.l1>tri.l2&&tri.l1>tri.l3)
		{
			igual=potencia(tri.l1,2)==potencia(tri.l2,2)+potencia(tri.l3,2);
		}
		else
		{
			if(tri.l2>tri.l1&&tri.l2>tri.l3)
				igual=potencia(tri.l2,2)==potencia(tri.l1,2)+potencia(tri.l3,2);
			else
				igual=potencia(tri.l3,2)==potencia(tri.l1,2)+potencia(tri.l2,2);
		}
	}
	else
	{
		igual=false;
	}
	return igual;
}

float potencia(float base,int exponente)
{
	int i;
	float pot=1;
	for(i=0;i<exponente;i++)
	{
		pot=pot*base;
	}
	
	return pot;
}

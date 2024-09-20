
const float pi=3.14f;

typedef struct tcilindro{
	float radio;
	float altura;
	float base;
	float volumen;
	float area;
};

void crear_cilindro(tcilindro &cilindro);
void caclular_area(tcilindro &cilindro);
void calcular_radio(tcilindro &cilindro);
int potencia(int base,int exponente);
void calcular_volumen(tcilindro &cilindro);
void mostrar_cilindro(tcilindro cilindro);

void crear_cilindro(tcilindro &cilindro)
{
	do{
		cout<<"INGRESE ALTURA DEL CILINDRO: ";
		cin>>cilindro.altura;
		cout<<"INGRESE BASE DEL CILINDRO: ";
		cin>>cilindro.base;
	} while(cilindro.altura<=0&&cilindro.base<=0);
}

void caclular_area(tcilindro &cilindro)
{
	calcular_radio(cilindro);
	cilindro.area= 2*pi*cilindro.radio*cilindro.altura+2*pi*potencia(cilindro.radio,2);
}

void calcular_radio(tcilindro &cilindro)
{
	cilindro.radio=cilindro.base/2;
}

int potencia(int base,int exponente)
{
	int i,pot;
	for(i=0;i<exponente;i++)
	{
		pot=pot*base;
	}
	
	return pot;
}

void calcular_volumen(tcilindro &cilindro)
{	
	calcular_radio(cilindro);
	cilindro.volumen=pi*potencia(cilindro.radio,2)*cilindro.altura;
}

void mostrar_cilindro(tcilindro cilindro)
{
	cout<<"Base: "<<cilindro.base<<endl;
	cout<<"Altura: "<<cilindro.altura<<endl;
	cout<<"Radio: "<<cilindro.radio<<endl;
	cout<<"Area: "<<cilindro.area<<endl;
	cout<<"Volumen: "<<cilindro.volumen<<endl;
}

typedef struct tpolinomio{
	int a;
	int b;
	int c;
};

void crear_polinomio(tpolinomio &p)
{
	cout<<"Ingrese termino cuadratico: ";
	cin>>a;
	cout<<"Ingrese termino lineal: ";
	cin>>b;
	cout<<"Ingrese termino independiente: ";
	cin>>c;
}

void sumar_polinomio(tpolinomio p1,tpolinomio p2,tpolinomio &pr)
{
	pr.a=p1.a+p2.a;
	pr.b=p1.b+p2.b;
	pr.c=p1.c+p2.c;
}

void restar_polinomio(tpolinomio p1,tpolinomio p2,tpolinomio &pr)
{
	pr.a=p1.a-p2.a;
	pr.b=p1.b-p2.b;
	pr.c=p1.c-p2.c;
}

void producto_escalar_polinomio(tpolinomio p1,tpolinomio p2,tpolinomio &pr,int escalar)
{
	pr.a=p1.a*p2.a*escalar;
	pr.b=p1.b*p2.b*escalar;
	pr.c=p1.c*p2.c*escalar;
}

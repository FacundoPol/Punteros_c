#include <iostream>

using namespace std;

typedef int *puntero;//se crea el tipo puntero para que se guarde un dato de tipo entero en la direccion que va a ser de tipo puntero


main()
{
	int num;
	puntero pnum;//se le asigna el tipo de dato puntero a una variable de tipo puntero
	cout<<"Ingrese numero: ";
	cin>>num;
	
	cout<<"Direccion donde se guarda: "<<&num<<endl; // con & muestra la direccion de memoria donde se guarda la variabale
	
	//pnum=&num; //se le asigna a la variable de tipo puntero la direccion de la variable ingresada
	
	//cout<<"EL NUMERO ES: "<<*pnum<<endl;//el * permite que la direccion donde se guardo la variable muestre la variable que esta en esa direccion
	
	pnum = new int;//el new permite solicitar al so una direccion de memoria de tipo entero en este caso por el int
	
	if(pnum==NULL)//se debe preguntar si el so otorgo una direccion de memmoria o no en el caso que sea igual a NULL no se otorgo
	{
		cout<<"No se otorgo una direccion de memoria"<<endl;
	}
	else
	{
		cout<<"La nueva direccion de memoria es: "<<&pnum<<endl;
		cout<<"Ingrese un numero: ";
		cin>>*pnum;
		cout<<endl;
		cout<<"EL NUMERO EN LA NUEVA DIRECCION ES: "<<*pnum<<endl;
	}
	cout<<endl;
	cout<<"La suma de los dos numeros es: "<<num + *pnum<<endl;
	cout<<endl;
	
	delete(pnum);//se usa para decirle al so que quite el permiso de uso de la posicion de memoria ocupada pone en nulo el puntero
	cout<<"Programa Finalizado"<<endl;
}

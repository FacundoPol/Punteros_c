typedef struct tpixel{
	int r;
	int g;
	int b;
};

void crear_pixel(tpixel &pixel)
{
	cout<<"Ingrese numero para R: ";
	cin>>pixel.r;
	cout<<"Ingrese numero para G: ";
	cin>>pixel.g;
	cout<<"Ingrese numero para B: ";
	cin>>pixel.b;
}

bool validar_pixel(tpixel pixel)
{
	if(pixel.r<=255&&pixel.r>=0)
	{
		if(pixel.g<=255&&pixel.g>=0)
		{
			if(pixel.b<=255&&pixel.b>=0)
				return true;
			else
				return false;
		}
		else
		   return false;
	}
	else
		return false;
}

void mostrar_pixel(tpixel pixel)
{
	cout<<"RGB: ("<<pixel.r<<","<<pixel.g<<","<<pixel.b<<")"<<endl;
}

void crear_blanco(tpixel &pixel)
{
	pixel.r=255;
	pixel.g=255;
	pixel.b=255;
	cout<<"RGB: ("<<pixel.r<<","<<pixel.g<<","<<pixel.b<<")"<<endl;
}

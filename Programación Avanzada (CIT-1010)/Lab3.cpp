/*

Nota: En el enunciado no queda claro con qué condiciones un animal cae en la categoría de híbrido,
por lo que asumí que si puede volar automáticamente se convierte en una especie híbrida.
Las especies se clasifican en anfibio y mamífero siguiendo las siguientes condiciones:

-Si puede respirar bajo el agua, no tiene pelo y no vuela -> ANFIBIO
-Si no puede respirar bajo el agua, tiene pelo y no vuela -> MAMIFERO

Todas las demás combinaciones se tomaron como ESPECIE HIBRIDA

*/

#include<iostream>
#include<vector>

using namespace std;

class Animal
{
	
protected:
	
	string nombre;
	int edad;
	
public:
	
	Animal(string nombre, int edad)
	{
		this->nombre = nombre;
		this->edad = edad;
	}
	
	virtual void mostrar()
	{
		cout << "ANIMAL" << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Edad: " << edad << endl;
	}
};

class Anfibio : public Animal
{
	
protected:
	
	bool puedeRespirarBajoElAgua;
	
public:
	
	Anfibio(string nombre, int edad, bool puedeRespirarBajoElAgua)
	: Animal(nombre, edad)
	{
		this->puedeRespirarBajoElAgua = puedeRespirarBajoElAgua;
	}
	
	void mostrar()
	{
		cout << "ANFIBIO" << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Edad: " << edad << endl;
		if(puedeRespirarBajoElAgua)
		{
			cout << "Puede respirar bajo el agua." << endl;			
		}
	}
	
};

class Mamifero : public Animal
{
	
protected:
	
	bool tienePelo;
	
public:
	
	Mamifero(string nombre, int edad, bool tienePelo)
	: Animal(nombre, edad)
	{
		this->tienePelo = tienePelo;	
	}
	
	void mostrar()
	{		
		cout << "ANFIBIO" << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Edad: " << edad << endl;
		if(tienePelo)
		{
			cout << "Tiene pelo" << endl;			
		}
	}
	
};

class EspecieHibrida : public Anfibio, public Mamifero
{
	
protected:

	bool puedeVolar;
	
public:

	EspecieHibrida(string nombre, int edad, bool puedeRespirarBajoElAgua,
	bool tienePelo, bool puedeVolar)
	 : Anfibio(nombre, edad, puedeRespirarBajoElAgua)
	 , Mamifero(nombre, edad, tienePelo)
	{
		this->puedeVolar = puedeVolar;
	}
	
	void mostrar(){
		
		if(Mamifero::tienePelo == true && Anfibio::puedeRespirarBajoElAgua == false && puedeVolar == false)
		{
			cout << "MAMIFERO" << endl;
		}
		else if(Mamifero::tienePelo == false && Anfibio::puedeRespirarBajoElAgua == true && puedeVolar == false)
		{
			cout << "ANFIBIO" << endl;
		}
		else
		{
			cout << "ESPECIE HIBRIDA" << endl;
		}
		
		cout << "Nombre: " << Anfibio::nombre << endl;
		cout << "Edad: " << Anfibio::edad << endl;
		
		if(Anfibio::puedeRespirarBajoElAgua)
		{
			cout << "Puede respirar bajo el agua." << endl;
		}
		if(Mamifero::tienePelo)
		{
			cout << "Tiene Pelo." << endl;
		}
		if(puedeVolar)
		{
			cout << "Puede volar." << endl;
		}
	}
};

int main()
{
	string nombre;
	int edad;
	bool puedeRespirarBajoElAgua, tienePelo, puedeVolar;
	char opcion;
	
	vector<EspecieHibrida*> v;

	
	while(opcion != '3')
	{
		cout << "1. Anadir especie." << endl;
		cout << "2. Mostrar especies." << endl;
		cout << "3. Salir." << endl;
	
		cin >> opcion;
	
		if(opcion == '1')
		{
			
			cout << endl;
			
			cout << "Ingrese nombre: " << endl;
			cin >> nombre;
			cout << "Ingrese edad: " << endl;
			cin >> edad;
			cout << "¿Puede respirar bajo el agua? (1. Si, 0. No)" << endl;
			cin >> puedeRespirarBajoElAgua;
			cout << "¿Tiene pelo? (1. Si, 0. No)" << endl;
			cin >> tienePelo;
			cout << "¿Puede volar? (1. Si, 0. No)" << endl;
			cin >> puedeVolar;
			
			EspecieHibrida* e = new EspecieHibrida(nombre, edad, puedeRespirarBajoElAgua, tienePelo, puedeVolar);
			
			v.push_back(e);
			
			cout << "Especie anadida correctamente." << endl;
			
		}
		else if(opcion == '2')
		{
			
			if(v.empty())
			{
				cout << "Error: No hay especies." << endl;
				continue;
			}
			else
			{
				
				for(int i=0; i<v.size(); i++)
				{
					
					v[i]->mostrar();
					cout << endl;
					
				}
				
			}
			
		}
		else if(opcion == '3')
		{
			break;
		}
	}
}

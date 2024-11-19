/*

Una compañía de Seguros dispone de 3 tipos de seguros: Hogar, Automotriz, Vida.
Todo seguro tiene un número de póliza, un cliente asociado (nombre y rut) y el monto
asegurado.
Los seguros Hogar pueden proteger contra incendio, terremoto e inundación (puede ser
una combinación de estos). En el caso del seguro Hogar existe un tipo especial que es el
seguro Parcela que tiene como información adicional los m 2 de terreno y el porcentaje
de dicho terreno que tiene plantaciones de árboles nativos.
El seguro Automotriz tiene asociado la patente y año del vehículo.
El seguro de Vida tiene asociado el nombre del beneficiario en caso de deceso del
asegurado.
En base a lo anterior se pide:
a) Determine la jerarquía de clases considerando herencia y una Súper clase
base llamada Seguro.
b)  Escriba el código de cada clase incluyendo:
dos constructores para cada una.
 un método imprimir, que muestra en pantalla el detalle completo de cada
seguro, es decir, todos sus datos.

Suponga que tiene una clase llamada seguros que tiene como atributo un vector de objetos de tipo seguros

Programe el método agregarSeguro(Seguro *s)

Programe el método imprimirSeguros()

No es necesario implementar los métodos set’s y get’s asociados.

*/

#include<iostream>
#include<vector>

using namespace std;

class Seguro
{

protected:

    int poliza, monto;
    string nombre, rut;

public:

    Seguro() { }

    Seguro(int poliza, int monto, string nombre, string rut)
    {
        this->poliza = poliza;
        this->monto = monto;
        this->nombre = nombre;
        this->rut = rut;
    }

    virtual void imprimir()
    {
        cout << "Poliza: " << poliza << endl;
        cout << "Monto: " << monto << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Rut: " << rut << endl;
    }

};

class Hogar : public Seguro
{

protected:

    int incendio, terremoto, inundacion;

public:

    Hogar() { }

    Hogar(int poliza, int monto, string nombre, string rut, int incendio, 
        int terremoto, int inundacion) : Seguro(poliza, monto, nombre, rut)
    {
    this->incendio = incendio;
    this->inundacion = inundacion;
    this->terremoto = terremoto;
    }

    void imprimir() override
    {
        cout << "PARCELA" << poliza << " " << rut << " " << nombre << " " << monto << " "
        << incendio << " " << terremoto << " " << inundacion << endl;
    }

};

class Parcela : public Hogar
{

protected:

    int m2;
    float pav;

public:

    Parcela() { }

    Parcela(int poliza, int monto, string nombre, string rut, int incendio,
            int terremoto, int inundacion, int m2, float pav)
    : Hogar(poliza, monto, nombre, rut, incendio, terremoto, inundacion)
    {
    this->m2 = m2;
    this->pav = pav;
    }

    void imprimir() override
    {
        cout << "PARCELA" << poliza << " " << rut << " " << nombre << " " << monto << " "
        << incendio << " " << terremoto << " " << inundacion << " " << m2 << " " << pav << endl;
    }

};

class Automotriz : public Seguro
{

protected:

    string patente;
    int ano;

public:

    Automotriz() { }

    Automotriz(int poliza, int monto, string nombre, string rut, string patente, int ano)
    : Seguro(poliza, monto, nombre, rut)
    {
        this->patente = patente;
        this->ano = ano;
    }

    void imprimir() override
    {
        cout << "AUTO" << poliza << " " << rut << " " << nombre << " " << monto << " "
            << patente << " " << ano << endl;
    }

};

class Vida : public Seguro
{

protected:

    string beneficiario;

public:

    Vida() { }

    Vida(int poliza, int monto, string nombre, string rut, string beneficiario)
    : Seguro(poliza, monto, nombre, rut)
    {
        this->beneficiario = beneficiario;
    }

    void imprimir() override
    {
        cout << "VIDA" << poliza << " " << rut << " " << nombre << " " << monto << " "
                << beneficiario << endl;
    }

};

class Seguros
{

private:

    vector<Seguro*> lista;

public:

    void agregarSeguro(Seguro* s)
    {
        lista.push_back(s);
    }

    void imprimirSeguros()
    {
        for(int i=0; i<lista.size(); i++)
        {
            lista[i]->imprimir();
        }
    }
};

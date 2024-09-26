/*
La clase Venta tiene dos atributos, fechaventa (AAAAMMDD) y 
monto.

Considere que la clase VentasDelDia tiene como parámetro un arreglo de 31 objetos de tipo venta (una celda por día).  
Considere que la clase Venta está lista son sus constructores y métodos set's y get's.
Programa en la clase VentasDelDia, lo siguiente:
- Constructor
- void agregarVenta(Venta *v), que recibe como parámetro
  un objeto tipo venta y acumula la información en la celda   
  respectiva
*/

#include<iostream>

using namespace std;

class Venta{

private:

    string fechaventa;
    int monto;

public:

    string getFechaVenta(){

        return fechaventa;

    }

    int getMonto(){

        return monto;

    }

    void setFechaVenta(string fechaventa){

        this->fechaventa = fechaventa;

    }

    void setMonto(int monto){

        this->monto = monto;

    }

};

class VentasDelDia{

private:

    Venta *ventas[31];

public:

    VentasDelDia(){

        for(int i=0; i<31; i++){

            ventas[i] = NULL;

        }

    }

    void agregarVenta(Venta *v){

        bool encontro = false;

        for(int i=0; i<31; i++){

            if(ventas[i] == NULL){

                ventas[i] = v;
                break;

                encontro = true;

            }

        }

        if(encontro == false){

            cout << "Error: Mes lleno" << endl;

        }

    }

};

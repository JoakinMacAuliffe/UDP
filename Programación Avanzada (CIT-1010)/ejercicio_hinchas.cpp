/*
Por disposición de Estadio Seguro todos los hinchas deben estar registrados para ir al estadio, además
todos las entradas al momento de venderse son numeradas.

Se le pide construir una aplicación en C++ con orientación a objetos que permita controlar el acceso al estadio, para ello se le piden 2 clases:

- Hincha que tiene 4 atributos: rut - nombrecompleto - equipoHincha - nroasiento

- Estadio que tiene un arreglo de 40.000 objetos tipo Hincha, en cada posición del arreglo se almacena un Hincha y 
el índice del arreglo representa el asiento.

Se pide:
Construya la clase Hincha con un constructor con parámetros, un método imprimir y los métodos get's

Construya la clase Estadio de manera que el constructor deje disponibles todos los asientos y programe los 
siguientes métodos:

- void registrarAsistencia(Hincha *h) que registra la asistencia de un hincha y lo almacena en el asiento respectivo
- int hinchasAsistentes() que devuelve la cantidad de hinchas que se ha registrado y asistido
- float porcentjaeOcupacion() que devuelve el porcentaje de ocupación del estadio
- Asumiendo que en el partido juegan los blancos contra los azules, imprima qué porcentaje de hinchas de cada equipo hay
en el estadio. Use para ellos el método void imprimirHinchada().
*/

#include<iostream>

using namespace std;

class Hincha{

private:

    string rut;
    string nombreCompleto;
    string equipoHincha;
    int nroAsiento;

public:

    Hincha(string rut, string nombreCompleto, string equipoHincha, int nroAsiento){

        this->rut = rut;
        this->nombreCompleto = nombreCompleto;
        this->equipoHincha = equipoHincha;
        this-> nroAsiento = nroAsiento;

    }

    string getRut(){

        return rut;

    }

    string getNombreCompleto(){

        return nombreCompleto;

    }

    string getEquipoHincha(){

        return equipoHincha;

    }

    int getNroAsiento(){

        return nroAsiento;

    }

    void imprimir(){

        cout << "Nombre Completo: " << nombreCompleto << "\nRut: " << rut << "\nEquipo Hincha: " << equipoHincha;
        cout << "\nNumero Asiento: " << nroAsiento << endl;

    }

};

class Estadio{

private:

    Hincha* asientos[40000];

public:

    Estadio(){

        for(int i=0; i<40000; i++){

            asientos[i] = NULL;

        }

    }

    void registrarAsistencia(Hincha *h){

        bool encontro = false;

        for(int i=0; i<40000; i++){

            if(asientos[i] != NULL){

                asientos[i] = h;

                encontro = true;

                break;

            }

        }

        if(encontro == false){

            cout << "Error: Estadio lleno.";

        }

    }

    int hinchasAsistentes(){

        int cantidad;

        for(int i=0; i<40000; i++){

            if(asientos[i] != NULL){

                cantidad++;

            }

        }

        return cantidad;

    }

    float porcentajeOcupacion(){

        return (hinchasAsistentes()*100)/40000;

    }

    void imprimirHinchada(){

        int blancos, azules;
        
        for(int i=0; i<40000; i++){

            if(asientos[i]->getEquipoHincha() == "azules"  || asientos[i]->getEquipoHincha() == "Azules"){

                azules++;

            }else if(asientos[i]->getEquipoHincha() == "blancos" || asientos[i]->getEquipoHincha() == "Blancos"){

                blancos++;

            }

            cout << "Porcentaje de azules: " << (azules*100)/40000 << endl;
            cout << "Porcentaje de blancos: " << (blancos*100)/40000 << endl;

        }

    }

};

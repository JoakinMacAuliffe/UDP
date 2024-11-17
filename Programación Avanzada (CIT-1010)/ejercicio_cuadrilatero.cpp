/*
La clase cuadrilátero tiene 2 atributos largo y ancho.

Considere que el constructor recibe dos parámetros: área y perímetro y que a partir de dichos datos asigna el valor de
largo y ancho, considerando dos opciones: cuadrado o rectángulo.

Programe el método string getTipo(), que en base a dichos 
datos devuelve si es un Cuadrado o un Rectángulo
*/

#include<iostream>
#include<cmath>

using namespace std;

class Cuadrilatero{

private:

    int largo, ancho;
    string tipo;

public:

    Cuadrilatero(int area, int perimetro){

        if(perimetro/4 == sqrt(area)){

            largo = sqrt(area);
            ancho = sqrt(area);
            tipo = "Cuadrado";

        }else{

            tipo = "Rectangulo";

            float det, a, b, c;

            a = 1;
            b = perimetro/2;
            c = area;

            det = pow(b, 2) - 4*a*c;

            if(det < 0){

                cout << "Error: No hay solucion real.";

            }else{

                if((b*-1 + sqrt(det))/2*a < 0){

                    ancho = (b*-1 - sqrt(det))/2*a;
                    largo = abs(area/ancho);

                }else{

                    ancho = (b*-1 + sqrt(det))/2*a;
                    largo = abs(area/ancho);

                }

            }

        }

    }

    string getTipo(){

        return tipo;

    }

    int getLargo(){

        return largo;

    }

    int getAncho(){

        return ancho;

    }

};

int main(){

    Cuadrilatero *cuadrado = new Cuadrilatero(36, 24);
    Cuadrilatero *rectangulo = new Cuadrilatero(24, 20);

    cout << cuadrado->getTipo();
    cout << " " << cuadrado->getLargo() << ", " << cuadrado->getAncho() << endl;

    cout << rectangulo->getTipo();
    cout << " " << rectangulo->getLargo() << ", " << cuadrado->getAncho() << endl;

}

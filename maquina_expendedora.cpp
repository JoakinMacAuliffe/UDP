/*
Una oficina puso a disposición de sus funcionarios una máquina expendedora de golosinas.

La máquina almacena 3 tipos de golosinas distintas: super8, negrita, KitKat.

Cuando llega la máquina a la oficina viene con una carga inicial, de 10 productos de cada uno.

El tope de la máquina es de 15 productos por tipo.

La máquina tiene 3 botones por cada producto, cuando el funcionario presiona un botón sale el producto
correspondiente, obviamente siempre y cuando haya stock.

Diariamente la secretaria añade stock a la máquina (no siempre la deja completamente cargada).

En base a lo anterior se pide:

Cree la clase Dispensadora con los atributos y métodos que sean necesarios para que dicha máquina pueda funcionar de acuerdo al enunciado.

*/

#include<iostream>

using namespace std;

class Dispensadora{

    private: 

        int super8, negrita, kitkat;

    public: 

        Dispensadora(){

            super8 = 10;
            negrita = 10;
            kitkat = 10;

        }

        void dispensarSuper8(int cantidad){

            if(super8 <= 0){

                cout << "Error: No hay stock." << endl;

            }else{

                super8 -= cantidad;

            }

        }

        void dispensarNegrita(int cantidad){

            if(negrita <= 0){

                cout << "Error: No hay stock." << endl;

            }else{

                negrita -= cantidad;

            }

        }

        void dispensarKitkat(int cantidad){

            if(kitkat <= 0){

                cout << "Error: No hay stock." << endl;

            }else{

                kitkat -= cantidad;

            }

        }

        void llenarStock(){

            int producto, cantidad;

            cout << "Ingrese producto para rellenar stock: ";
            cin >> producto;

            cout << "Ingrese cuanto quiere agregar: ";
            cin >> cantidad;

            if(producto == 1){

                if((super8 + cantidad) > 15){

                    cout << "Error: No hay espacio suficiente." << endl;

                }else{

                    super8 += cantidad;

                }

            }else if(producto == 2){

                if((negrita + cantidad) > 15){

                    cout << "Error: No hay espacio suficiente." << endl;

                }else{

                    negrita += cantidad;

                }

            }else if(producto == 3){

                if((kitkat + cantidad) > 15){

                    cout << "Error: No hay espacio suficiente." << endl;

                }else{

                    kitkat += cantidad;

                }

            }else{

                cout << "Producto invalido, intente de nuevo." << endl;

                llenarStock();

            }

        }

        void verStock(){

            cout << endl;
            cout << "Super8: " << super8 << endl;
            cout << "Negrita: " << negrita << endl;
            cout << "KitKat: " << kitkat << endl;

        }

};

int main(){

    char opcion = '0';
    int cantidad;

    Dispensadora *d = new Dispensadora();

    while(opcion != '5'){

        cout << "1. Dispensar Super8." << endl;
        cout << "2. Dispensar Negrita." << endl;
        cout << "3. Dispensar Kitkat." << endl;
        cout << "4. Llenar stock." << endl;
        cout << "5. Salir." << endl << endl;

        d-> verStock();

        cin >> opcion;

        if(opcion == '1'){

            cout << "Ingrese cantidad para dispensar: ";
            cin >> cantidad;

            d-> dispensarSuper8(cantidad);

        }else if(opcion == '2'){

            cout << "Ingrese cantidad para dispensar: ";
            cin >> cantidad;

            d-> dispensarNegrita(cantidad);

        }else if(opcion == '3'){

            cout << "Ingrese cantidad para dispensar: ";
            cin >> cantidad;

            d-> dispensarKitkat(cantidad);

        }else if(opcion == '4'){

            d-> llenarStock();
            
        }else if(opcion == '5'){

            break;

        }else{

            cout << "Error: Opcion invalida." << endl;
            continue;

        }

    }

}

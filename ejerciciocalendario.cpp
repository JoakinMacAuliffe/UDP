#include<iostream>

using namespace std;

int getDiasDelMes(int mes){

    if(mes == 2){

        if(mes%4 == 0){

            return 29; //Bisiesto

        }else{

            return 28;

        }

    }else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){

        return 30;

    }else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){

        return 31;

    }else{

        return 0;

    }

}

class Calendario{

	private:

		int dd, mm, aa, hh, min, ss;

	public:

		Calendario(int dd, int mm, int aa, int hh, int min, int ss){
			
            this->dd = dd;
            this->mm = mm;
            this->aa = aa;
            this->hh = hh;
            this->min = min;
            this->ss = ss;


		}

		void verFecha(){

			cout << dd << "/" << mm << "/" << aa;
            cout << " " << hh << ":" << min << ":" << ss << endl;

		}

        void sumarSegundo(int segundo){

            for(int i=0; i<segundo; i++){

                ss++;

                if(ss == 60){

                    ss = 0;
                    min++;

                    if(min == 60){

                        min = 0;
                        hh++;

                        if(hh == 24){

                            hh = 0;
                            dd++;

                            if(dd == getDiasDelMes(mm)){

                                dd = 0;
                                mm++;

                                if(mm == 12){

                                    mm = 0;
                                    aa++;

                                }

                            }

                        }

                    }

                }

            }

        }

        void sumarMinuto(int minuto){

            for(int i=0; i<minuto; i++){

                min++;

                if(min == 60){

                    min = 0;
                    hh++;

                    if(hh == 24){

                        hh = 0;
                        dd++;

                        if(dd == getDiasDelMes(mm)){

                            dd = 0;
                            mm++;

                            if(mm == 12){

                                mm = 0;
                                aa++;

                            }

                        }

                    }

                }

            }

        }

        void sumarHora(int hora){

            for(int i=0; i<hora; i++){

                hh++;

                if(hh == 24){

                    hh = 0;
                    dd++;

                    if(dd == getDiasDelMes(mm)){

                        dd = 0;
                        mm++;

                        if(mm == 12){

                            mm = 0;
                            aa++;

                        }

                    }

                }

            }

        }

        void sumarDia(int dia){

            for(int i=0; i<dia; i++){

            dd++;

            if(dd == getDiasDelMes(mm)){

                dd = 0;
                mm++;

                if(mm == 12){

                    mm = 0;
                    aa++;

                }

            }

        }

    }

        void sumarMes(int mes){

            for(int i=0; i<mes; i++){

                mm++;

                if(mm == 12){

                    mm = 0;
                    aa++;

                }

            }

        }

        void sumarAno(int ano){

            aa++;

        }

		//Programar método sumar dia
		//Programar un reloj
};

int main(){

Calendario *c = new Calendario(20, 8, 2023, 15, 34, 34);

char opcion = '0';
int cantidad;


while(opcion != '7'){

    cout << "Ingrese cantidad de tiempo para sumar: ";
    cin >> cantidad;

    cout << "1. Sumar segundos." << endl;
    cout << "2. Sumar minutos." << endl;
    cout << "3. Sumar horas." << endl;
    cout << "4. Sumar dias." << endl;
    cout << "5. Sumar meses." << endl;
    cout << "6. Sumar años." << endl;
    cout << "7. Salir" << endl;

    cin >> opcion;

    if(opcion == '1'){

        c -> sumarSegundo(cantidad);

    }else if(opcion == '2'){

        c -> sumarMinuto(cantidad);

    }else if(opcion == '3'){

        c -> sumarHora(cantidad);

    }else if(opcion == '4'){

        c -> sumarDia(cantidad);

    }else if(opcion == '5'){

        c -> sumarMes(cantidad);

    }else if(opcion == '6'){

        c -> sumarAno(cantidad);

    }else if(opcion == '7'){

        break;

    }else{

        cout << "Opcion invalida." << endl;

    }

}

}

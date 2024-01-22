// el director de una escula esta organizando un viaje de estudios, y requiere determinar cuànto debe cobrar a cada alumno y cuànto debe pagar a la compañia de viajes por el servicio. la form,a de cobrar es la siguiente: si son 100 alumnos o mas, el costo por cada alumno es de $65.00; de 50 a 99 alumnos, el costo es de 
// $70.00, de 30 a 49, de $95.00, y si son menos de 30, el costode la renta del autobus es de 4000.00, sin imporar el numero de alumnos. realice un algoritmo qie permita determinar pago a la compañia de autobuses y lo que debe pagar cada alumno por el viaje.
// al realizar un analisis del problema, se puede deducir que las variables que se requiern como datos son el numero de alumnos (NA), con lo qie se puede calcular el pago por alumno(PA) y el costo total del vaije (TOT)

#include <iostream>
#include<stdlib.h>
using namespace std;

int main() {
    int alumnos;
    float costo_por_alumno, costo_total;
    cout << "Ingrese el número de alumnos: ";
    cin >> alumnos;
    if(alumnos >= 100){
        costo_por_alumno = 65.00;
    } else if(alumnos >= 50){
        costo_por_alumno = 70.00;
    } else if(alumnos >= 30){
        costo_por_alumno = 95.00;
    } else{
        costo_por_alumno = 4000.00 / alumnos;
    }
    costo_total = alumnos * costo_por_alumno;
    cout << "El costo por alumno es: " << costo_por_alumno << endl;
    cout << "El costo total del viaje es: " << costo_total << endl;
    system("pause");
    return 0;
}
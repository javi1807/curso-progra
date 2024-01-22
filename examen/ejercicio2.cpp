// 2.elabora un programa que permita calcular el puntaje de un equipo de futbol lueho de 20 partidos,por cadapartido
//  ganado el puntaje se incrementara en 3 puntos y por cada partido empatado 1 puntos y por cada partido perdido 0 puntos...
#include <iostream>
#include<stdlib.h>
using namespace std;

int main() {
    int ganados = 0, empatados = 0, perdidos = 0, total = 0;
    char resultado;
    for(int i = 0; i < 20; i++){
        cout << "Ingrese el resultado del partido " << i+1 << " (g para ganado, e para empatado, p para perdido): ";
        cin >> resultado;
        switch(resultado){
            case 'g':
                ganados++;
                break;
            case 'e':
                empatados++;
                break;
            case 'p':
                perdidos++;
                break;
        }
    }
    total = (ganados * 3) + empatados;
    cout << "El puntaje total del equipo es: " << total << endl;
    system("pause");
    return 0;
}
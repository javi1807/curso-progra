// elaboarr un programa que el incentivo que recibira un operativo a lo largo de su semana laboarar  (luunes a sabado),se conoce que la producccion minimo es de 100 unidades
#include <iostream>
#include<stdlib.h>
using namespace std;

int main() {
    int produccion, incentivo = 0;
    for(int i = 0; i < 6; i++){
        cout << "Ingrese la producción del día " << i+1 << ": ";
        cin >> produccion;
        if(produccion >= 100){
            incentivo += produccion; // Asume que el incentivo es igual a la producción
        }
    }
    cout << "El incentivo del operativo es: " << incentivo << endl;
    system("pause");
    return 0;
}
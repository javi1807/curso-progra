

#include <iostream>
using namespace std;

// Función para calcular el sueldo semanal
double calcularSueldo(int horas) {
    double sueldo;

    if(horas <= 40) {
        sueldo = horas * 20;
    } else {
        sueldo = 40 * 20 + (horas - 40) * 25;
    }

    return sueldo;
}

int main() {
    int horas;

    // El usuario introduce las horas trabajadas
    cout << "Por favor, introduce las horas trabajadas en la semana: ";
    cin >> horas;

    // Calcula el sueldo semanal
    double sueldo = calcularSueldo(horas);

    cout << "Tu sueldo semanal es: $" << sueldo << endl;

    return 0;
}
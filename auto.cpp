#include <iostream>
using namespace std;

int main()
{

    float velocidad_kmh, velocidad_mps;

    cout << "Ingrese la velocidad del automóvil en kilómetros por hora: ";
    cin >> velocidad_kmh;

    // Conversión de kilómetros por hora a metros por segundo
    velocidad_mps = velocidad_kmh * 1000 / 3600;

    cout << "La velocidad en metros por segundo es: " << velocidad_mps << " m/s" << endl;

    return 0;
}

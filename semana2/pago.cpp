#include <iostream>
using namespace std;
float tarifa;
float horas;
float pago;
int main()
{
    cout << "escribe tu tarifa" << endl;
    cin >> tarifa;
    cout << "escribe tus horas" << endl;
    cin >> horas;

    if (horas <= 40)
        pago = tarifa * horas;
    else
        pago = tarifa * (40 + (horas - 40) * 1.5);
    cout << "el pago es:" << endl
         << pago;
}
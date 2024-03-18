#include <iostream>
#include <string>
using namespace std;
int main()
{
    int notas[5];
    int *puntero;
    puntero = notas;
    float suma = 0;
    cout << "ingrese las notas" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << " nota" << i + 1 << endl;
        cin >> *(puntero + i);
        suma += *(puntero + i);
    }
    cout << endl;
    cout << "el promedio es" << suma / 10 << endl;

    return 0;
}

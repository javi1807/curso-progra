#include <iostream>
using namespace std;
int main()
{
    int numero[8], mayor = 0;
    for (int i = 0; i < 8; i++)
    {
        cout << "digite las numeros del arreglo: " << endl;
        cin >> numero[i];
        if (numero[i] > mayor)
        {
            mayor = numero[i];
        }
    }

    cout << "el mayor numero es: " << mayor << endl;
    return 0;
}
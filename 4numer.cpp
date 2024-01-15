#include <iostream>
using namespace std;

int main()
{
    int numeros[4];

    for (int i = 0; i < 4; ++i)
    {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> numeros[i];
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3 - i; ++j)
        {
            if (numeros[j] > numeros[j + 1])
            {
                float temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }

    cout << "Números ordenados de menor a mayor: ";
    for (int i = 0; i < 4; ++i)
    {
        cout << numeros[i] << " ";
    }

    return 0;
}

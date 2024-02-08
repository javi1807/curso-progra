#include <iostream>
using namespace std;
int main()
{
    int numero[5] = {9, 15, 50, -100, 2};
    int mayor = 0;
    for (int i = 0; i < 5; i++)
    {
        if (numero[i] > mayor)
        {
            mayor = numero[i];
        }
    }
    cout << "el numero mayor es: " << mayor << endl;
    return 0;
}
/*hacer un programa que lea 5 numeros en un arreglo, los cpie a otro arreglo multiplicados por 2 y muestre el segundo arreglo*/
#include <iostream>
using namespace std;
int main()
{
    int numero1[5], numero2[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "digite los numeros para el primer arreglo" << endl;
        cin >> numero1[i];
    }
    for (int i = 0; i < 5; i++)
    {
        numero2[i] = numero1[i] * 2;
    }
    cout << "el numevo arreglo es: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << numero2[i] << endl;
    }
    return 0;
}
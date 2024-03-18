#include <iostream>
#include <string>
using namespace std;
int main()
{
    int arreglo[5] = {1, 2, 3, 4, 5};
    int *puntero;
    puntero = arreglo;
    cout << "imprimientod los valores del arreglo" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *(puntero + i) << "  ";
    }
    cout << endl;
    return 0;
}

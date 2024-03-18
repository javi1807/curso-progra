#include <iostream>
#include <string>
using namespace std;
int main()
{
    int numero = 10;
    int *puntero;
    puntero = &numero;
    cout << puntero << endl;
    cout << *puntero << endl;
    *puntero = 45;
    cout << puntero << endl;
    cout << *puntero << endl;
    cout << numero << endl;
    return 0;
}
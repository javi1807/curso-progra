#include <iostream>
using namespace std;
int main()
{
    float a, b, resultado = 0; // declara la variable y le asigna un valor
    cout <<“Digite el valor de a :”;
    cin >> a;
    cout <<“Digite el valor de b :”;
    cin >> b;
    resultado = (a / b) + 1;
    cout <<“El resultado es :” << resultado;
    return 0;
}

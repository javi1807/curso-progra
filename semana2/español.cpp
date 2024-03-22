#include <iostream>
using namespace std;
int Cuadrado(int);
int Cubo(int);
int main()
{
    cout << "El cuadrado de 27 es " << Cuadrado(27) << endl;
    cout << "y el cubo de 27 es " << Cubo(27) << endl;
    return 0;
}
int Cuadrado(int n)
{
    return n * n;
}
int Cubo(int n)
{
    return n * n * n;
}
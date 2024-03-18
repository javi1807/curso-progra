#include <iostream>
#include <string>
using namespace std;
int suma(int n1, int n2);
void ingreso_valores();

int main()
{
    cout << "ingrese los valores a suma" << endl;
    ingreso_valores();

    suma(num1, num2);
    return 0;
}
int suma(int n1, int n2)
{
    //return n1 + n2;
    cout<<"la suma es: "<< n1 + n2<<endl;
}
void ingreso_valores()
{
    int num1, num2;
    cout << "Introduce un numero: ";
    cin >> num1;
    cout << "Introduce otro numero: ";
    cin >> num2;
}
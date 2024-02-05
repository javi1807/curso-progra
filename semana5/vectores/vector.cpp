/*escriba un programa que defina un vector de número
y calcule la suma de sus elementos*/
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int numero[5] = {2, 6, 8, 7, 9};
    int suma = 0;
    for (int i = 0; i < 5; i++)
    {
        suma = suma + numero[i];
    }
    cout << "La suma de los numeros es: " << suma << endl;
    getch();
    return 0;
}
<<<<<<< HEAD
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    int n, dato, contador = 0;
    srand(time(NULL));
    dato = 1 + rand() % (100);
    cout << "Ingrese un numero: ";
    cin >> n;

    while (n != dato)
    {

        if (n > dato)
        {
            cout << "ingrese un numero menor: ";
        }
        else
        {
            cout << "ingrese un numero mayor: ";
        }
        contador++;
    }
    cout << "felicidades adivinaste el numero" << endl;
    cout << "numero de intentos: " << contador << endl;
    return 0;
=======
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    int n, dato, contador = 0;
    srand(time(NULL));
    dato = 1 + rand() % (100);
    cout << "Ingrese un numero: ";
    cin >> n;

    while (n != dato)
    {

        if (n > dato)
        {
            cout << "ingrese un numero menor: ";
        }
        else
        {
            cout << "ingrese un numero mayor: ";
        }
        contador++;
    }
    cout << "felicidades adivinaste el numero" << endl;
    cout << "numero de intentos: " << contador << endl;
    return 0;
>>>>>>> 8707b5c52440e91b588dffa2c913b719bf1d0324
}
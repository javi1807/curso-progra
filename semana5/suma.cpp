<<<<<<< HEAD
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, suma = 0, elevacion = 0;
    cout << "ingrese un numero" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        elevacion = pow(2, i);
        suma += elevacion;
    }
    cout << "la suma es " << suma << endl;
    return 0;
=======
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, suma = 0, elevacion = 0;
    cout << "ingrese un numero" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        elevacion = pow(2, i);
        suma += elevacion;
    }
    cout << "la suma es " << suma << endl;
    return 0;
>>>>>>> 8707b5c52440e91b588dffa2c913b719bf1d0324
}
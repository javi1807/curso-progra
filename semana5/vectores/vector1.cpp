/*escribe un programa que lea de la entrada estándar un vector de números y muestre en la salida estándar los numero del vecotr con su indices asociados*/
#include <iostream>
using namespace std;
int main()
{
    int numer[100], n;
    cout << "digite el numero de elementos que va a tener el arreglo: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "digite un numero: ";
        cin >> numer[i]; // guardando los elemtos del vector
    }
    // ahora, vamos mostrar los elemntos con su indices asociados
    for (int i = 0; i < n; i++)
    {
        cout << i << " ->" << numer[i] << endl;
    }

    return 0;
}
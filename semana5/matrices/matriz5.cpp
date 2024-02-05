/*realize un programa que lea una matriz de 3x3 y crre su matriz traspuesta.
la matriz traspuesta es aquilla en la que la columna i era la fila 8 de la matriz
original.
/1 2 3/     /1 4 7/
/4 5 6/ --> /2 5 8/
/7 8 9/     /3 6 9/
*/
#include <iostream>
using namespace std;
int main()
{
    int matriz[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "ingrese el numero[" << i << "][" << j << "] es: " << endl;
            cin >> matriz[i][j]; // Imprime el número en la posición [i][j] de la matriz
        }
    }
    cout << "la matriz original: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << "la matriz transpuesta: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            cout << matriz[j][i] << "  ";
        }
        cout << endl;
    }

    return 0;
}
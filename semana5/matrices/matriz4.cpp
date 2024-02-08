/*hacer una matriz lpreguntando al usuario el numero de filas y columnas, llenarla de números aleagorios, copiar el contenido
a otra matriz y por ultimo mostrarla en pantalla*/
#include <iostream>
#include <time.h>
using namespace std;
int main()
{
    int filas, columnas, dato = 0;
    cout << "Ingrese el numero de filas: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;
    srand(time(NULL));
    int matriz[filas][columnas], matriz2[filas][columnas];
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            dato = 1 + rand() % 9;

            matriz[i][j] = dato;
        }
    }
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz2[i][j] = matriz[i][j];
        }
    }
    cout << "la matriz 2 es: " << endl;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout << matriz2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
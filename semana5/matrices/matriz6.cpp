/*realice un programa eu calcule la suma de dos matrices cuadradas de 3x 3*/
#include <iostream>
using namespace std;

int main()
{
    // Declaración de dos matrices de 3x3
    int matriz1[3][3], matriz2[3][3];

    // Solicitar al usuario que ingrese los números para la primera matriz
    cout << "digite los numeros para la primera matriz: " << endl;

    // Ciclo para ingresar los números en la primera matriz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Solicitar al usuario que ingrese un número específico
            cout << "ingresar el numero [" << i << "][" << j << "]:" << endl;
            // Leer el número ingresado por el usuario y almacenarlo en la primera matriz
            cin >> matriz1[i][j];
        }
    }

    // Solicitar al usuario que ingrese los números para la segunda matriz
    cout << "digite los numeros para la segunda matriz: " << endl;

    // Ciclo para ingresar los números en la segunda matriz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Solicitar al usuario que ingrese un número específico
            cout << "ingresar el numero [" << i << "][" << j << "]:" << endl;
            // Leer el número ingresado por el usuario y almacenarlo en la segunda matriz
            cin >> matriz2[i][j];
        }
    }

    // Mostrar la primera matriz
    cout << "matriz1: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Mostrar el elemento de la primera matriz en la posición [i][j]
            cout << matriz1[i][j] << " ";
        }
        // Salto de línea para pasar a la siguiente fila
        cout << endl;
    }

    // Mostrar la segunda matriz
    cout << "matriz2: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Mostrar el elemento de la segunda matriz en la posición [i][j]
            cout << matriz2[i][j] << " ";
        }
        // Salto de línea para pasar a la siguiente fila
        cout << endl;
    }

    // Mostrar la suma de las matrices
    cout << "la suma de las matrices son: " << endl;
    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Mostrar la suma de los elementos de las mismas posiciones en ambas matrices
            cout << matriz2[i][j] * matriz1[i][j] << "  ";
        }
        // Salto de línea para pasar a la siguiente fila
        cout << endl;
    }

    return 0;
}

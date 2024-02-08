/*realice un programa que calcule el producto de dos matrices cuadradas de 3x3*/
#include <iostream> // Incluye la biblioteca estándar para entrada/salida de datos.
using namespace std; // Usa el espacio de nombres estándar de C++.

int main()
{
    // Declaración de dos matrices de 3x3
    int matriz1[3][3], matriz2[3][3], matriz3[3][3];

    // Solicitar al usuario que ingrese los números para la primera matriz
    cout << "Digite los numeros para la primera matriz: " << endl;

    // Ciclo para ingresar los números en la primera matriz
    for (int i = 0; i < 3; i++) // Recorre las filas de la primera matriz
    {
        for (int j = 0; j < 3; j++) // Recorre las columnas de la primera matriz
        {
            cout << "Ingrese el numero [" << i << "][" << j << "]: "; // Pide al usuario que ingrese un número específico
            cin >> matriz1[i][j]; // Almacena el número ingresado en la posición [i][j] de la primera matriz
        }
    }

    // Solicitar al usuario que ingrese los números para la segunda matriz
    cout << "Digite los numeros para la segunda matriz: " << endl;

    // Ciclo para ingresar los números en la segunda matriz
    for (int i = 0; i < 3; i++) // Recorre las filas de la segunda matriz
    {
        for (int j = 0; j < 3; j++) // Recorre las columnas de la segunda matriz
        {
            cout << "Ingrese el numero [" << i << "][" << j << "]: "; // Pide al usuario que ingrese un número específico
            cin >> matriz2[i][j]; // Almacena el número ingresado en la posición [i][j] de la segunda matriz
        }
    }

    // Mostrar la primera matriz
    cout << "Matriz 1: " << endl;
    for (int i = 0; i < 3; i++) // Recorre las filas de la primera matriz
    {
        for (int j = 0; j < 3; j++) // Recorre las columnas de la primera matriz
        {
            cout << matriz1[i][j] << " "; // Muestra el elemento en la posición [i][j] de la primera matriz
        }
        cout << endl; // Salto de línea para pasar a la siguiente fila
    }

    // Mostrar la segunda matriz
    cout << "Matriz 2: " << endl;
    for (int i = 0; i < 3; i++) // Recorre las filas de la segunda matriz
    {
        for (int j = 0; j < 3; j++) // Recorre las columnas de la segunda matriz
        {
            cout << matriz2[i][j] << " "; // Muestra el elemento en la posición [i][j] de la segunda matriz
        }
        cout << endl; // Salto de línea para pasar a la siguiente fila
    }

    // Multiplicación de matrices
    cout << "La multiplicacion de las matrices es:" << endl;
    for (int i = 0; i < 3; i++) // Recorre las filas de la matriz resultante
    {
        for (int j = 0; j < 3; j++) // Recorre las columnas de la matriz resultante
        {
            matriz3[i][j] = 0; // Inicializa cada elemento de la matriz resultante en 0
            for (int k = 0; k < 3; k++) // Recorre las filas/columnas para realizar la multiplicación
            {
                matriz3[i][j] += matriz1[i][k] * matriz2[k][j]; // Calcula el producto de los elementos correspondientes y lo suma a la posición [i][j] de la matriz resultante
            }
            cout << matriz3[i][j] << " "; // Muestra el elemento en la posición [i][j] de la matriz resultante
        }
        cout << endl; // Salto de línea para pasar a la siguiente fila
    }

    return 0; // Indica que el programa finalizó correctamente
}


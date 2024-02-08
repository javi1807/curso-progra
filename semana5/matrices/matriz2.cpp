/*realize un programa que defina una matriz de 3x 3 y escriba un ciclo para que meustre la diagonal principal de la matriz*/

#include <iostream> // Inclusión de la biblioteca estándar de C++ para entrada y salida
using namespace std; // Usando el espacio de nombres estándar para evitar tener que escribir "std::"

int main() { // Función principal del programa
    int numeros[3][3]; // Declaración de una matriz de 3x3 para almacenar los números

    // Solicitar al usuario que ingrese los elementos de la matriz
    for (int i = 0; i < 3; i++) { // Bucle externo para iterar sobre las filas de la matriz
        for (int j = 0; j < 3; j++) { // Bucle interno para iterar sobre las columnas de la matriz
            cout << "Ingrese el numero [" << i << "][" << j << "]: "; // Imprime un mensaje solicitando al usuario que ingrese el elemento en la posición [i][j] de la matriz
            cin >> numeros[i][j]; // Lee el número ingresado por el usuario y lo almacena en la posición correspondiente de la matriz
        }
    }

    // Mostrar todos los elementos de la matriz
    for (int i = 0; i < 3; i++) { // Bucle externo para iterar sobre las filas de la matriz
        for (int j = 0; j < 3; j++) { // Bucle interno para iterar sobre las columnas de la matriz
            cout << "El numero [" << i << "][" << j << "] es: " << numeros[i][j] << endl; // Imprime el número en la posición [i][j] de la matriz
        }
    }

    // Mostrar la diagonal principal de la matriz
    for (int i = 0; i < 3; i++) { // Bucle para iterar sobre las filas de la matriz
        for (int j = 0; j < 3; j++) { // Bucle para iterar sobre las columnas de la matriz
            if (i == j) { // Comprueba si el índice de la fila es igual al índice de la columna (condición para la diagonal principal)
                cout << numeros[i][j] << endl; // Imprime el elemento de la diagonal principal
            }
        }
    }

    return 0; // Indica que la función main ha finalizado correctamente
}

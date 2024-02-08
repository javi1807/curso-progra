/*hacer un programa para rellenar un amatriz pidiendo al usiario el
número de filas y columnas, posteriormente mostrar la matriz en pantalla*/
#include <iostream>  // Inclusión de la biblioteca estándar de C++ para entrada y salida
using namespace std; // Usando el espacio de nombres estándar para evitar tener que escribir "std::"

int main()
{                        // Función principal del programa
    int filas, columnas; // Declaración de variables para almacenar el número de filas y columnas de la matriz

    cout << "Ingrese el numero de filas: "; // Imprime un mensaje para solicitar al usuario el número de filas
    cin >> filas;                           // Lee el número de filas ingresado por el usuario desde la entrada estándar

    cout << "Ingrese el numero de columnas: "; // Imprime un mensaje para solicitar al usuario el número de columnas
    cin >> columnas;                           // Lee el número de columnas ingresado por el usuario desde la entrada estándar

    int numeros[filas][columnas]; // Declaración de una matriz con tamaño dinámico basado en el número de filas y columnas proporcionadas por el usuario

    // Almacenamiento de elementos en la matriz
    for (int i = 0; i < filas; i++)
    { // Bucle externo para iterar sobre las filas de la matriz
        for (int j = 0; j < columnas; j++)
        {                                                             // Bucle interno para iterar sobre las columnas de la matriz
            cout << "Ingrese el numero [" << i << "][" << j << "]: "; // Imprime un mensaje solicitando al usuario que ingrese el elemento en la posición [i][j] de la matriz
            cin >> numeros[i][j];                                     // Lee el elemento ingresado por el usuario y lo almacena en la posición correspondiente de la matriz
        }
    }

    // Mostrando la matriz
    cout << "La matriz ingresada es:\n"; // Imprime un mensaje para indicar que se mostrará la matriz
    for (int i = 0; i < filas; i++)
    { // Bucle externo para iterar sobre las filas de la matriz
        for (int j = 0; j < columnas; j++)
        {                                 // Bucle interno para iterar sobre las columnas de la matriz
            cout << numeros[i][j] << " "; // Imprime el elemento en la posición [i][j] de la matriz, seguido de un espacio en blanco
        }
        cout << endl; // Imprime un salto de línea después de imprimir todos los elementos de una fila, para pasar a la siguiente fila
    }

    return 0; // Indica que la función main ha finalizado correctamente
}

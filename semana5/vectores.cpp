/*elaborar un programa que solicite las notas de 10 estudiantes, el programa debe validar que las notas sean [0,20], se pide lo siguiente
A)devolver la nota maxima
B)calcular el promedio
C)realizar la sumatoria de todas notas
D)ordenar las notas de mayor a menor*/
#include <iostream>
using namespace std;

int main()
{
    int notas[10];
    int max = 0;
    float promedio = 0;
    int suma = 0;

    for (int i = 0; i < 10; i++)
    {
        do
        {
            cout << "Ingrese la nota del estudiante " << i + 1 << ": ";
            cin >> notas[i];

            if (notas[i] < 0 || notas[i] > 20)
            {
                cout << "Error: La nota debe estar en el rango [0, 20]. Inténtelo de nuevo." << endl;
            }

        } while (notas[i] < 0 || notas[i] > 20);

        if (notas[i] > max)
        {
            max = notas[i];
        }

        suma += notas[i];
    }

    promedio = static_cast<float>(suma) / 10;

    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - 1 - i; j++)
        {
            if (notas[j] < notas[j + 1])
            {

                int temp = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = temp;
            }
        }
    }

    cout << "La nota máxima es: " << max << endl;
    cout << "El promedio es: " << promedio << endl;
    cout << "La suma de las notas es: " << suma << endl;
    cout << "Notas ordenadas de mayor a menor: ";
    for (int i = 0; i < 10; i++)
    {
        cout << notas[i] << " ";
    }
    cout << endl;

    return 0;
}

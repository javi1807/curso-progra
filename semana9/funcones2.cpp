#include <iostream>
#include <string>
using namespace std;

struct alumno
{
    string nombre;
    int edad;
    float nota[3];
    float promedio;
};

float calcular_promedio(float notas[3])
{
    float suma = 0;
    for (int i = 0; i < 3; i++)
    {
        suma += notas[i];
    }
    return suma / 3;
}

void determinar_aprobacion(float promedio)
{
    if (promedio >= 10.5)
    {
        cout << "Aprobo" << endl;
    }
    else
    {
        cout << "No aprobo" << endl;
    }
}

int main()
{
    alumno estudiante;

    cout << "Ingrese el nombre del estudiante: ";
    cin >> estudiante.nombre;

    cout << "Ingrese la edad del estudiante: ";
    cin >> estudiante.edad;

    cout << "Ingrese las 3 notas del estudiante: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> estudiante.nota[i];
    }

    estudiante.promedio = calcular_promedio(estudiante.nota);

    cout << "El promedio del estudiante es: " << estudiante.promedio << endl;

    cout << "El estudiante ";
    if (estudiante.edad >= 18)
    {
        cout << "es mayor de edad y ";
    }
    else
    {
        cout << "no es mayor de edad y ";
    }
    determinar_aprobacion(estudiante.promedio);

    alumno estudiante2;

    cout << "Ingrese el nombre del estudiante: ";
    cin >> estudiante2.nombre;

    cout << "Ingrese la edad del estudiante: ";
    cin >> estudiante2.edad;

    cout << "Ingrese las 3 notas del estudiante: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> estudiante2.nota[i];
    }

    estudiante.promedio = calcular_promedio(estudiante2.nota);

    cout << "El promedio del estudiante es: " << estudiante.promedio << endl;

    cout << "El estudiante ";
    if (estudiante2.edad >= 18)
    {
        cout << "es mayor de edad y ";
    }
    else
    {
        cout << "no es mayor de edad y ";
    }
    determinar_aprobacion(estudiante2.promedio);

    return 0;
}

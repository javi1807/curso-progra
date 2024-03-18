/*elabore un programa que registre 10 personas y que pida su año de nacimiento*/
#include <iostream>
#include <string>

using namespace std;

struct Persona
{
    string nombre;
    string apellido;
    int nacimiento;
};

void ingresarPersonas(Persona personas[], int cantidad);

void calcularEdad(Persona personas[], int cantidad);
int encontrarMayorEdad(Persona personas[], int cantidad);

int main()
{
    int cantidadPersonas = 2;
    Persona personas[cantidadPersonas];

    ingresarPersonas(personas, cantidadPersonas);
    calcularEdad(personas, cantidadPersonas);
    encontrarMayorEdad(personas, cantidadPersonas);

    return 0;
}
void ingresarPersonas(Persona personas[], int cantidad)
{
    cout << "Ingrese los datos de las personas:" << endl;
    for (int i = 0; i < cantidad; ++i)
    {
        cout << "Persona " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin >> personas[i].nombre;
        cout << "Apellido: ";
        cin >> personas[i].apellido;
        cout << "Ao de nacimiento: ";
        cin >> personas[i].nacimiento;
    }
}
void calcularEdad(Persona personas[], int cantidad)
{
    cout << "Edad de las personas y si son mayores de edad:" << endl;
    for (int i = 0; i < cantidad; ++i)
    {
        int edad = 2024 - personas[i].nacimiento;
        cout << personas[i].nombre << " " << personas[i].apellido << ": " << edad << " anos";
        if (edad >= 18)
        {
            cout << " es mayor de edad " << endl;
        }
        else
        {
            cout << " es menor de edad " << endl;
        }
    }
}
int encontrarMayorEdad(Persona personas[], int cantidad)
{
    int mayorEdadIndex = 0;
    for (int i = 1; i < cantidad; ++i)
    {
        if (2024 - personas[i].nacimiento > 2024 - personas[mayorEdadIndex].nacimiento)
        {
            mayorEdadIndex = i;
        }
    }
    return mayorEdadIndex;
}
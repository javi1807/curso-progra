#include <iostream>
#include <string>

using namespace std;

// Definición de la estructura Automovil
struct Automovil
{
    string marca;
    string modelo;
    string color;
    int velocidadMaxima;
    int cantidadPasajeros;
};

// Función para registrar los automóviles
void registrarAutomoviles(Automovil autos[], int cantidad)
{
    for (int i = 0; i < cantidad; ++i)
    {
        cout << "Ingrese la marca del automovil " << i + 1 << ": ";
        cin >> autos[i].marca;
        cout << "Ingrese el modelo del automovil " << i + 1 << ": ";
        cin >> autos[i].modelo;
        cout << "Ingrese el color del automovil " << i + 1 << ": ";
        cin >> autos[i].color;
        cout << "Ingrese la velocidad maxima del automovil " << i + 1 << ": ";
        cin >> autos[i].velocidadMaxima;
        cout << "Ingrese la cantidad de pasajeros del automovil " << i + 1 << ": ";
        cin >> autos[i].cantidadPasajeros;
    }
}

// Función para mostrar los automóviles registrados
void mostrarAutomoviles(const Automovil autos[], int cantidad)
{
    cout << "\nAutomoviles registrados:\n";
    for (int i = 0; i < cantidad; ++i)
    {
        cout << "Automovil " << i + 1 << ":\n";
        cout << "Marca: " << autos[i].marca << endl;
        cout << "Modelo: " << autos[i].modelo << endl;
        cout << "Color: " << autos[i].color << endl;
        cout << "Velocidad Maxima: " << autos[i].velocidadMaxima << " km/h" << endl;
        cout << "Cantidad de Pasajeros: " << autos[i].cantidadPasajeros << endl
             << endl;
    }
}

// Función para obtener el índice del automóvil a modificar
int obtenerIndiceAutomovil(int cantidad)
{
    int indice;
    cout << "Ingrese el índice del automóvil al que desea cambiar las características (1-" << cantidad << "): ";
    cin >> indice;
    return indice;
}

// Función para cambiar las características de un automóvil
void cambiarCaracteristicas(Automovil &autoRef)
{
    cout << "Ingrese el nuevo color: ";
    cin >> autoRef.color;
    cout << "Ingrese la nueva velocidad maxima: ";
    cin >> autoRef.velocidadMaxima;
    cout << "Ingrese la nueva cantidad de pasajeros: ";
    cin >> autoRef.cantidadPasajeros;
}

int main()
{
    const int cantidadAutomoviles = 2;
    Automovil autos[cantidadAutomoviles]; // Array de los automóviles

    registrarAutomoviles(autos, cantidadAutomoviles);
    mostrarAutomoviles(autos, cantidadAutomoviles);

    // Cambiar características de un automóvil
    int indice = obtenerIndiceAutomovil(cantidadAutomoviles);

    // Verificar si el índice es válido
    if (indice >= 1 && indice <= cantidadAutomoviles)
    {
        cambiarCaracteristicas(autos[indice - 1]); // Pasar el automóvil por referencia
        cout << "\nCaracterísticas actualizadas del automóvil " << indice << ":\n";
        cout << "Color: " << autos[indice - 1].color << endl;
        cout << "Velocidad Máxima: " << autos[indice - 1].velocidadMaxima << " km/h" << endl;
        cout << "Cantidad de Pasajeros: " << autos[indice - 1].cantidadPasajeros << endl;
    }
    else
    {
        cout << "Índice de automóvil no válido.\n";
    }

    return 0;
}

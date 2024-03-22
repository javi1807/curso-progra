#include <iostream>
#include <string>
using namespace std;

// Definición de la estructura Persona
struct Persona {
    string nombre;
    int edad;
    float altura;
};

// Función para imprimir los datos de una Persona
void imprimirPersona(Persona p) {
    cout << "Nombre: " << p.nombre << ", Edad: " << p.edad << ", Altura: " << p.altura << endl;
}

int main() {
    // Declaración de una variable de tipo Persona
    Persona persona1;

    // Asignación de valores a los miembros de la estructura Persona
    persona1.nombre = "Juan";
    persona1.edad = 25;
    persona1.altura = 1.75;

    // Llamada a la función para imprimir los datos de persona1
    imprimirPersona(persona1);

    // Declaración e inicialización de otra variable de tipo Persona
    Persona persona2 = {"María", 30, 1.60};

    // Llamada a la función para imprimir los datos de persona2
    imprimirPersona(persona2);

    return 0;
}

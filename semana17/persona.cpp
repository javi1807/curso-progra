#include <iostream>
#include <string>
using namespace std;
class Persona{
    private: 
    int codigo; 
    string nombre; 
    string apellido;
    string direccion; 
    public:
    Persona();
    Persona(int _codigo, string _nombre, string _apellido, string _direccion){
        codigo = _codigo;
        nombre = _nombre;
        apellido = _apellido;
        direccion = _direccion;
    }

};
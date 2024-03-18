#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Facultad
{
private:
    /* data */
    string codigo;
    string nombre;
    string siglas;

public:
    Facultad(){
        
    }
    
    Facultad(string _codigo, string _nombre, string _siglas)
    {
        codigo = _codigo;
        nombre = _nombre;
        siglas = _siglas;
    }

    string GetCodigo() const
    {
        return codigo;
    }

    void SetCodigo(string codigo)
    {
        codigo = codigo;
    }

    string GetNombre() const
    {
        return nombre;
    }

    void SetNombre(string nombre)
    {
        nombre = nombre;
    }

    string GetSiglas() const
    {
        return siglas;
    }

    void SetSiglas(string siglas)
    {
        siglas = siglas;
    }

    string to_string(){
        return " " + nombre + " - " + siglas;
    }
};

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Persona
{
private:
    /* data */
    int codigo_persona;
    string apellidos;
    string nombres;
    string dni;
    string direccion;
    string correo;
    int edad;
    string sexo;
    time_t fecha_nacimiento;

public:
    Persona(/* args */);

    Persona(int _codigo, string _apellidos, string _nombre, int _edad){
        codigo_persona = _codigo;
        apellidos = _apellidos;
        nombres = _nombre;
        edad = _edad;
    }

    int GetCodigo_persona() const
    {
        return codigo_persona;
    }

    void SetCodigo_persona(int codigo_persona)
    {
        codigo_persona = codigo_persona;
    }

    string GetApellidos() const
    {
        return apellidos;
    }

    void SetApellidos(string apellidos)
    {
        apellidos = apellidos;
    }

    string GetNombres() const
    {
        return nombres;
    }

    void SetNombres(string nombres)
    {
        nombres = nombres;
    }

    string GetDni() const
    {
        return dni;
    }

    void SetDni(string dni)
    {
        dni = dni;
    }

    string GetDireccion() const
    {
        return direccion;
    }

    void SetDireccion(string direccion)
    {
        direccion = direccion;
    }

    string GetCorreo() const
    {
        return correo;
    }

    void SetCorreo(string correo)
    {
        correo = correo;
    }

    int GetEdad() const
    {
        return edad;
    }

    void SetEdad(int edad)
    {
        edad = edad;
    }

    string GetSexo() const
    {
        return sexo;
    }

    void SetSexo(string sexo)
    {
        sexo = sexo;
    }

    time_t GetFecha_nacimiento() const
    {
        return fecha_nacimiento;
    }

    void SetFecha_nacimiento(time_t fecha_nacimiento)
    {
        fecha_nacimiento = fecha_nacimiento;
    }
};


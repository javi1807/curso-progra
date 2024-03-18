#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Departamento
{
private:
    string nombre;

public:
    Departamento();
    Departamento(string _nombre)
    {
        nombre = _nombre;
    }
    string getNombre() const
    {
        return nombre;
    }
    void setNombre(string _nombre)
    {
        nombre = _nombre;
    }
};

class Persona
{
private:
    int codigo;
    string nombre;
    string apellido;
    string direccion;

public:
    Persona();
    Persona(int _codigo, string _nombre, string _apellido, string _direccion)
    {
        codigo = _codigo;
        nombre = _nombre;
        apellido = _apellido;
        direccion = _direccion;
    }
    int GetCodigo() const
    {
        return codigo;
    }

    void SetCodigo(int codigo)
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

    string GetApellido() const
    {
        return apellido;
    }

    void SetApellido(string apellido)
    {
        apellido = apellido;
    }

    string GetDireccion() const
    {
        return direccion;
    }

    void SetDireccion(string direccion)
    {
        direccion = direccion;
    }
};

class Empleado : public Persona
{
private:
    string codigo;
    float costo_hh;
    Departamento departamento;
    int horas_laboradas;

    double salario;

public:
    Empleado();
    Empleado(int _codigo, string _nombre, string _apellido, string _direccion, string _codigo_empleado, float _costo_hh, Departamento _departamento, int _horas_extras) : Persona(_codigo, _nombre, _apellido, _direccion)
    {
        codigo = _codigo_empleado;
        costo_hh = _costo_hh;
        departamento = _departamento;
        horas_laboradas = _horas_extras;
    }

    string GetCodigo() const
    {
        return codigo;
    }

    void SetCodigo(string codigo)
    {
        codigo = codigo;
    }

    float GetCosto_hh() const
    {
        return costo_hh;
    }

    void SetCosto_hh(float costo_hh)
    {
        costo_hh = costo_hh;
    }

    Departamento GetDepartamento() const
    {
        return departamento;
    }

    void SetDepartamento(Departamento departamento)
    {
        departamento = departamento;
    }

    int GetHoras_laboradas() const
    {
        return horas_laboradas;
    }

    void SetHoras_laboradas(int horas_laboradas)
    {
        horas_laboradas = horas_laboradas;
    }

    int calcularSalario(int horas_laboradas)
    {
        salario = horas_laboradas * costo_hh;
        return salario;
    }

    void asignarRol()
    {
    }

    void CambiarArea()
    {
        // Implementación de CambiarArea
    }
};

int main()
{

    return 0;
}

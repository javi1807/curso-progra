#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Departamento
{
private:
    string nombre;

public:
    Departamento() {}
    Departamento(string _nombre) : nombre(_nombre) {}

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
    Persona() {}
    Persona(int _codigo, string _nombre, string _apellido, string _direccion) : codigo(_codigo), nombre(_nombre), apellido(_apellido), direccion(_direccion) {}

    int getCodigo() const
    {
        return codigo;
    }

    void setCodigo(int _codigo)
    {
        codigo = _codigo;
    }

    string getNombre() const
    {
        return nombre;
    }

    void setNombre(string _nombre)
    {
        nombre = _nombre;
    }

    string getApellido() const
    {
        return apellido;
    }

    void setApellido(string _apellido)
    {
        apellido = _apellido;
    }

    string getDireccion() const
    {
        return direccion;
    }

    void setDireccion(string _direccion)
    {
        direccion = _direccion;
    }
};

class Empleado : public Persona
{
private:
    string codigo_empleado;
    float costo_hh;
    Departamento departamento;
    int horas_laboradas;
    double salario;

public:
    Empleado() {}
    Empleado(int _codigo, string _nombre, string _apellido, string _direccion, string _codigo_empleado, float _costo_hh, Departamento _departamento, int _horas_laboradas) : Persona(_codigo, _nombre, _apellido, _direccion), codigo_empleado(_codigo_empleado), costo_hh(_costo_hh), departamento(_departamento), horas_laboradas(_horas_laboradas) {}

    string getCodigoEmpleado() const
    {
        return codigo_empleado;
    }

    void setCodigoEmpleado(string _codigo_empleado)
    {
        codigo_empleado = _codigo_empleado;
    }

    float getCostoHora() const
    {
        return costo_hh;
    }

    void setCostoHora(float _costo_hh)
    {
        costo_hh = _costo_hh;
    }

    Departamento getDepartamento() const
    {
        return departamento;
    }

    void setDepartamento(Departamento _departamento)
    {
        departamento = _departamento;
    }

    int getHorasLaboradas() const
    {
        return horas_laboradas;
    }

    void setHorasLaboradas(int _horas_laboradas)
    {
        horas_laboradas = _horas_laboradas;
    }

    double calcularSalario()
    {
        salario = horas_laboradas * costo_hh;
        return salario;
    }

    void asignarRol()
    {
        // Implementación de asignarRol
    }

    void cambiarArea()
    {
        // Implementación de cambiarArea
    }
};

int main()
{
    // Creación de un Departamento
    Departamento departamento("Recursos Humanos");

    // Creación de un Empleado
    Empleado empleado(1, "Juan", "Perez", "123 Calle Principal", "EMP001", 15.0, departamento, 40);

    // Mostrar información del empleado
    cout << "Información del empleado:" << endl;
    cout << "Código: " << empleado.getCodigo() << endl;
    cout << "Nombre: " << empleado.getNombre() << endl;
    cout << "Apellido: " << empleado.getApellido() << endl;
    cout << "Dirección: " << empleado.getDireccion() << endl;
    cout << "Código de empleado: " << empleado.getCodigoEmpleado() << endl;
    cout << "Costo por hora: $" << empleado.getCostoHora() << endl;
    cout << "Departamento: " << empleado.getDepartamento().getNombre() << endl;
    cout << "Horas laboradas: " << empleado.getHorasLaboradas() << endl;
    cout << "Salario: $" << empleado.calcularSalario() << endl;

    return 0;
}

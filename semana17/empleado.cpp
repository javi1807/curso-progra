#include <iostream>
#include "persona.cpp"
#include "departamento.cpp"
#include <vector>
#include <string>
using namespace std; 
class Empleado : public Persona{
    private: 
    vector<Empleado> empleado;
     string codigo;
    float costo_hh;
    Departamento departamento;
    int horas_laboradas; 
    bool gerente=true;
    double salario;
    

    public: 
    Empleado();
    Empleado(int _codigo, string _nombre, string _apellido, string _direccion, string _codigo_empleado, float _costo_hh, Departamento _departamento, int _horas_extras): Persona(_codigo,_nombre,_apellido, _direccion){
        codigo = _codigo_empleado;
        costo_hh = _costo_hh;
        departamento = _departamento;
        horas_laboradas = _horas_extras;
    }
    string GetCodigo() const {
return codigo;
}

void SetCodigo(string codigo) {
codigo = codigo;
}

    float GetCosto_hh() const {
        return costo_hh;
    }

    void SetCosto_hh(float costo_hh) {
        costo_hh = costo_hh;
    }

    Departamento GetDepartamento() const {
        return departamento;
    }

    void SetDepartamento(Departamento departamento) {
        departamento = departamento;
    }

    int GetHoras_laboradas() const {
        return horas_laboradas;
    }

    void SetHoras_laboradas(int horas_laboradas) {
        horas_laboradas = horas_laboradas;
    }
    int calcularSalario(int horas_laboradas){
        salario = horas_laboradas * costo_hh;
        return salario;

    }
    void asignarRol(){
        for(int i=0; i<8; i++){
            
        }

    }
    void CambiarArea(){

    }

};
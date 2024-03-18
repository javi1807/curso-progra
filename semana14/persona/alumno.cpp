#include <iostream>
#include <string>
#include <ctime>
#include "persona.cpp"
#include "facultad.cpp"
#include "curso.cpp"

using namespace std;

class Alumno : public Persona
{
private:
    /* data */
    string codigo;
    int año_ingreso;
    Facultad facultad;
    // agregar una arreglo de objeto curso [3]
    Curso cursos[3];
    int numCurso = 0;

public:
    Alumno(/* args */)
    {
    }

    Alumno(string _codigo_alumno, int _año, int _codigo, string _apellidos, string _nombre, int _edad) : Persona(_codigo, _apellidos, _nombre, _edad)
    {
        codigo = _codigo_alumno;
        año_ingreso = _año;
        // facultad = _facultad;
    }

    string GetCodigo() const
    {
        return codigo;
    }

    void SetCodigo(string codigo)
    {
        codigo = codigo;
    }

    int GetAño_ingreso() const
    {
        return año_ingreso;
    }

    void SetAño_ingreso(int año_ingreso)
    {
        año_ingreso = año_ingreso;
    }

    Facultad GetFacultad() const
    {
        return facultad;
    }

    void SetFacultad(Facultad facultad)
    {
        facultad = facultad;
    }

    Curso getCurso(int posicion)
    {
        return cursos[posicion];
    }

    void agregarCurso(Curso curso)
    {
        if (numCurso < 3)
        {
            cursos[numCurso] = curso;
            numCurso++;
        }
        else
        {
            cout << "El estudiante completo el numero de cursos";
            cout << "\n";
        }
    }

    void mostrarCursos()
    {
        cout << "Cursos del estudiante :" << GetApellidos() << " " << GetNombres();
        cout << "\n";
        int size = sizeof(cursos) / sizeof(cursos[0]);
        // cout << size;
        if (size != 0)
        {
            for (int i = 0; i < size; i++)
            {
                if (cursos[i].GetCodigo_curso() != "")
                {
                    cout << i + 1 << " .- " << cursos[i].toString() << "\n";
                }
            }
        }
        else
        {
            cout << "No se registraron cursos para el estudiante ...........";
            cout << "\n";
        }
    }

    void ingresar_notas(string _codigo_curso, float nota1, float nota2, float nota3)
    {
        // buscamos el curso por codigo
        int size = sizeof(cursos) / sizeof(cursos[0]);
        if (size > 0)
        {
            for (int i = 0; i < size; i++)
            {
                if (cursos[i].GetCodigo_curso() == _codigo_curso)
                {
                    // cout<<"curso encontrado";
                    cursos[i].setNota(1, nota1);
                    cursos[i].setNota(2, nota2);
                    cursos[i].setNota(3, nota3);
                }
            }
        }
    }

    
};

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Curso
{
private:
    /* data */
    string codigo_curso;
    string nombre_curso;
    int creditaje;
    float notas[3] = {0,0,0};
    float promedio_final;

public:
    Curso()
    {
    }
    Curso(string _codigo, string _nombre, int _credito)
    {
        codigo_curso = _codigo;
        nombre_curso = _nombre;
        creditaje = _credito;
    }

    string GetCodigo_curso() const
    {
        return codigo_curso;
    }

    void SetCodigo_curso(string codigo_curso)
    {
        codigo_curso = codigo_curso;
    }

    string GetNombre_curso() const
    {
        return nombre_curso;
    }

    void SetNombre_curso(string nombre_curso)
    {
        nombre_curso = nombre_curso;
    }

    int GetCreditaje() const
    {
        return creditaje;
    }

    void SetCreditaje(int creditaje)
    {
        creditaje = creditaje;
    }
    float GetPromedio_final() const
    {
        return promedio_final;
    }

    void SetPromedio_final(float promedio_final)
    {
        promedio_final = promedio_final;
    }

    void setNota(int posicion, float nota)
    {
        if (posicion <= 3)
        {
            notas[posicion - 1] = nota;
        }
    }

    void calcular_promedio()
    {
        float suma = 0;
        int size = sizeof(notas) / sizeof(notas[0]);
        if (size == 3)
        {
            for (int i = 0; i < size; i++)
            {
                //cout << "nota... " + i << notas[i] << endl;
                suma = suma + notas[i];
            }
            promedio_final = suma / 3;
        }
    }

    string toString()
    {
        calcular_promedio();
        string resumen = "Curso: " + nombre_curso + " --> Credito:  " + to_string(creditaje) + " --> Promedio: " + to_string(promedio_final);
        return resumen;
    }

       string datos_curso()
    {
        //calcular_promedio();
        string resumen = "Curso: " + nombre_curso + " --> Credito:  " + to_string(creditaje) + " \n";
        return resumen;
    }
};

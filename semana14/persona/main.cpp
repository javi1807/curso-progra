#include <iostream>
#include <string>
#include "alumno.cpp"

using namespace std;

int main(){
    Facultad facultad_1("001", "Facultad de Ingenieria Informatica y Sistema", "FIIS");
    Facultad facultad_2("002", "Facultad de Zootecnia", "ZOO");

    Curso curso_01("001","Lenguaje de Programación Basica", 5);
    Curso curso_02("002","Diseño de Base de Datos", 4);
    Curso curso_03("003","Patrones de Arquitectura de SW", 4);

    Alumno alumno_1("2024-0001",2024,1,"Rodriguez", "Josefo", 18);
    Alumno alumno_2("2024-0002",2019,2,"Mendoza", "Inocencio", 24);

    alumno_1.SetFacultad(facultad_1);

    alumno_1.agregarCurso(curso_01);
    alumno_1.agregarCurso(curso_02);
    alumno_1.agregarCurso(curso_03);


    alumno_1.mostrarCursos();
    alumno_1.ingresar_notas("001", 13.45, 13.56, 5);
    alumno_1.mostrarCursos();
    
}
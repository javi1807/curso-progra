#include <iostream>
#include <string>
#include "alumno.cpp"
#include <fstream>

using namespace std;

int main()
{
    Facultad facultad_1("001", "Facultad de Ingenieria Informatica y Sistema", "FIIS");
    Facultad facultad_2("002", "Facultad de Zootecnia", "ZOO");

    Curso curso_01("001", "Lenguaje de Programación Basica", 5);
    Curso curso_02("002", "Diseño de Base de Datos", 4);
    Curso curso_03("003", "Patrones de Arquitectura de SW", 4);

    Alumno alumno_1("2024-0001", 2024, 1, "Rodriguez", "Josefo", 18);
    Alumno alumno_2("2024-0002", 2019, 2, "Mendoza", "Inocencio", 24);

    // creamos el fichero para cursos
    ofstream archivo_curso("C:\\FIIS 2023-2\\Lenguaje de programacion\\proyectos c++\\lenguaje_programacion_2023_2\\sesion_14\\persona\\ficheros\\cursos.txt");

    // verificamos si el archivo se abrio correctamente
    if (!archivo_curso.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }
    // realizamos el registro en el fichero
    archivo_curso << "******Datos de registros de Curso 2024****** \n";
    archivo_curso << facultad_1.to_string() << "\n";
    archivo_curso << curso_01.datos_curso();
    archivo_curso << curso_02.datos_curso();
    archivo_curso << curso_03.datos_curso();
    archivo_curso << "********************************************";
    cout << "se registraron los documentos";
    archivo_curso.close();

    ifstream archivo_mostrar("C:\\FIIS 2023-2\\Lenguaje de programacion\\proyectos c++\\lenguaje_programacion_2023_2\\sesion_14\\persona\\ficheros\\cursos.txt");

    if (!archivo_mostrar.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }
    ofstream archivo_alumno("");
    if (!archivo_alumno.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }
    archivo_alumno << "******Datos de registros de Alumno 2024****** \n";
    archivo_alumno << alumno_1.to_string() << "\n";
    archivo_alumno << alumno_2.to_string();
    archivo_alumno << "********************************************";
    cout << "se registraron los documentos";
    archivo_mostrar.close();
    ifstream archivo_mostrar("");
    if (!archivo_mostrar.is_open())
    {
        cout<<"error al abrir el archivo"<<endl;
        return 1;
    }
    cout << "Imprimiendo" << endl;
    string linea;
    while (getline(archivo_mostrar, linea))
    {

        cout << linea << endl;
    }

    archivo_mostrar.close();
    return 0;
}
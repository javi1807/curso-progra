/*
elabore un programa que solicite un arreglo de 10 estudiantes y que cada estudiante cuente con 3 notas, se solicita clacular el promedio
de las notas del estudiante*/
#include <iostream>
#include <string>

using namespace std;
struct estudiante
{
    string nombre;
    string apellido;
    int edad;
    float nota[3];
    float promedio;
};
estudiante estud[3];
void promedio(estudiante estudiante);
void ingresar_estudiante();
void mostra_promedio(estudiante estudiante[]);
int main()
{
    cout << "registro de estudiantes: " << endl;
    ingresar_estudiante();
    promedio(estudiante estudiante[3]);

    return 0;
}
void ingresar_estudiante()
{
    cout << "ingrese los estudiantes a registrar " << endl;
    estudiante estud[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "ingrese el nombre del estudiante: " << endl;
        getline(cin, estud[i].nombre);
        cout << "ingrese el apellido del estudiante: " << endl;
        getline(cin, estud[i].apellido);
        cout << "ingrese la edad del estudiante: " << endl;
        cin >> estud[i].edad;
        cout << endl;
        cout << "ingrese las notas del estudiante: " << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << "ingrese la nota " << j << endl;
            cin >> estud[i].nota[j];
        }
    }
}
void promedio(estudiante estudiante[3])
{
    
    for (int i = 0; i < 3; i++)
    {
        float suma = 0;
        for (int j = 0; j < 3; j++)
        {
            suma += estudiante[i].nota[j];
        }
        estudiante[i].promedio = suma / 3;
    }
}
void mostrar_promedio(estudiante estudiante[3]){
    for ( int i=0; i<3; i++){
        cout<<"el promedio del estudiante: "<<endl;
        cout<<estudiante[i].apellido<<"  "<<estudiante[i].nombre<<" es :"<<endl;
        cout<<estudiante[i].promedio<<endl;
    }
}

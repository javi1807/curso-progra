#include <iostream>
using namespace std;

int main()
{
    // arreglo de notas de 10
    int notas[10];
    int cont = 0;
    int nota_maxima = 0;
    int nota = 0;
    int suma_notas=0;
    //cout << "ingrese las notas de los estudiantes 0 - 20"<<endl;
    //cin >> nota;
    for (int i = 0; i < 5; i++)
    {
        cout << "ingrese las notas de los estudiantes 0 - 20"<<endl;
        cin >> nota;
        while (nota < 0 || nota > 20)
        {
            cout << "ingrese nuevamente la nota de los estudiante 0 - 20" << endl;
            cin >> nota;
        }
        notas[i] = nota;
        if (nota > nota_maxima)
        {
            nota_maxima = nota;
        }

        suma_notas =  nota + suma_notas;
    }
    float promedio = suma_notas/10;

    
    return 0;
}
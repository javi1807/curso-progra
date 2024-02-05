#include <iostream>

using namespace std;

int main(void)
{
    int contador_aprbados = 0, contador_jalados = 0;
    int NumAl, nota;
    cout << "ingresar numero de alumnos";
    cin >> NumAl;
    for (int contador = 1; contador <= NumAl; contador++)
    {
        cout << "ingresar la nota";
        cin >> nota;
        if (nota >= 10.5)
            contador_aprbados++;
        else
        {
            contador_jalados++;
        }
    }
    cout << "numero de alumnos aprbados " << contador_aprbados << endl;
    cout << "numero de alumnos jalados " << contador_jalados << endl;
    return 0;
}
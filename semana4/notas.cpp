#include <iostream>

int main()
{
    using namespace std;

    char nota;

    cout << "Ingrese la nota alfanumérica: ";
    cin >> nota;

    switch (nota)
    {
    case 'A':
        cout << "Rango de notas: 19 - 18" << endl;
        break;
    case 'B':
        cout << "Rango de notas: 17 - 14" << endl;
        break;
    case 'C':
        cout << "Rango de notas: 14 - 11" << endl;
        break;
    case 'D':
        cout << "Rango de notas: 10 - 5" << endl;
        break;
    case 'E':
        cout << "Rango de notas: 5 - 0" << endl;
        break;
    default:
        cout << "Nota no válida." << endl;
    }

    return 0;
}

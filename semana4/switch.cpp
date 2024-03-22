#include <iostream>
using namespace std;

int main () {
    int opcion;

    cout << "Seleccione una opción (1-3): ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "Ha seleccionado la opción 1" << endl;
            break;
        case 2:
            cout << "Ha seleccionado la opción 2" << endl;
            break;
        case 3:
            cout << "Ha seleccionado la opción 3" << endl;
            break;
        default:
            cout << "Opción inválida" << endl;
    }

    return 0;
}

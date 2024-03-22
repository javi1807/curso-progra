#include <iostream>
using namespace std;

int main () {
    int edad = 20;
    char genero = 'M';

    if (edad >= 18) {
        if (genero == 'M') {
            cout << "Eres un hombre adulto." << endl;
        } else {
            cout << "Eres una mujer adulta." << endl;
        }
    }

    return 0;
}

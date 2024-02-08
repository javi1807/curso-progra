/*realice un programa que lea una cadena de caracteres de la entrada estandar y
muestre en la salida estandar cuantos ocurrencias de cada ocal existen en la cadena*/
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
    char frase[1000];
    int vocales[5] = {0}; // Contador para las 5 vocales: a, e, i, o, u

    cout << "Ingrese una cadena de caracteres: ";
    cin.getline(frase, 1000, '\n');

    // Convertir la cadena a minúsculas para simplificar la comparación
    for (int i = 0; i < strlen(frase); i++) {
        frase[i] = tolower(frase[i]);
    }

    // Contar ocurrencias de vocales
    for (int i = 0; i < strlen(frase); i++) {
        switch (frase[i]) {
            case 'a':
                vocales[0]++;
                break;
            case 'e':
                vocales[1]++;
                break;
            case 'i':
                vocales[2]++;
                break;
            case 'o':
                vocales[3]++;
                break;
            case 'u':
                vocales[4]++;
                break;
        }
    }

    // Mostrar resultados
    cout << "Ocurrencias de cada vocal en la cadena:" << endl;
    cout << "a: " << vocales[0] << endl;
    cout << "e: " << vocales[1] << endl;
    cout << "i: " << vocales[2] << endl;
    cout << "o: " << vocales[3] << endl;
    cout << "u: " << vocales[4] << endl;

    return 0;
}

/*1. escriba un programa que simule el juego de adivinar un numer. El programa debera generaar 
un numero aleatorio entre 1 y 100 y pedirle al usuario que adivine cual es. si el usuario ingresa
un numero incorrectop, el programa debera indicarle si el numero a adivinar es mayor o menor al que ingreo. el juego terminara 
cuando el usuario adivine el numero correcto. se debe almacenar los intentos y el numero maximo de intentos y el numero maximo de intentos es 5.
 cuando el usuario exceda los intentos el aplicativo debe mostrar una alerta y terminar el programa  */
 #include <iostream>
#include <iostream>
#include <ctime>
#include<stdlib.h>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0)); // Semilla para números aleatorios basada en el tiempo actual
    int numeroSecreto = rand() % 100 + 1; // Genera un número aleatorio entre 1 y 100
    int intentos = 0;
    int maxIntentos = 5;
    int numeroUsuario;

    cout << "Bienvenido al juego de adivinación. Tienes 5 intentos para adivinar un número entre 1 y 100." << endl;

    do {
        cout << "Por favor, introduce un número: ";
        cin >> numeroUsuario;

        if(numeroUsuario < numeroSecreto) {
            cout << "El número secreto es mayor. Intenta de nuevo." << endl;
        } else if(numeroUsuario > numeroSecreto) {
            cout << "El número secreto es menor. Intenta de nuevo." << endl;
        }

        intentos++;
        if(intentos >= maxIntentos && numeroUsuario != numeroSecreto) {
            cout << "Has excedido el número máximo de intentos. El juego ha terminado."  << "\n el nùmero ganador era " << numeroSecreto << endl;
            return 0;
        }
    } while(numeroUsuario != numeroSecreto);

    cout << "¡Felicidades! Has adivinado el número secreto en " << intentos << " intentos."  << endl;

    system ("pause") ;
    return 0;
}
    
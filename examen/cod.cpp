// elabora un programa que solicite el nunmero de respuestas de un postulante, por cada respuesta correcta
//  se incrememta su puntaje en 4, por cada respuesta incorrecta -2 y por cada respuesta em banco 0, se pide calcular el puntaje total del postulante de una prueva de 20 preguntas

#include <iostream>
#include<stdlib.h>
using namespace std;

int main() {
    int correctas = 0, incorrectas = 0, en_blanco = 0, total = 0;
    char respuesta;
    for(int i = 0; i < 20; i++){
        cout << "Ingrese la respuesta a la pregunta " << i+1 << " (c para correcta, i para incorrecta, b para blanco): ";
        cin >> respuesta;
        switch(respuesta){
            case 'c':
                correctas++;
                break;
            case 'i':
                incorrectas++;
                break;
            case 'b':
                en_blanco++;
                break;
        }
    }
    total = (correctas * 4) + (incorrectas * -2);
    cout << "El puntaje total del postulante es: " << total << endl;
    system("pause");
    return 0;
}

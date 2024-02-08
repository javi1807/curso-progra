#include <iostream>
#include <string>
using namespace std;
int val_01 = 0;
int val_02 = 0;

int suma(int valor_01, int valor_02)
{
    int result = valor_01 + valor_02;
    return result;
}
int resta(int valor_01, int valor_02)
{
    int result = valor_01 - valor_02;
    return result;
}
int multiplicacion(int valor_01, int valor_02)
{
    int result = valor_01 * valor_02;
    return result;
}
float division(int valor_01, int valor_02)
{
    float result = 0;
    if (valor_02 != 0)
    {
        float result = valor_01 / valor_02;
    }
    return result;
}
void mensaje()
{
    cout << "*****calculadora*****";
    cout << endl;
}
void ingreso_parametro()
{
    cout << "*****ingrese el valor para el primer parametro*****";
    cin >> val_01;
    cout << "*****ingrese el valor para el segundo parametro*****";
    cin >> val_02;
}

int main()
{
    int opcion;
    mensaje();
    cout << "ingrese las ocpciones de la calculadora" << endl;
    cout << "1.suma ; 2.restar; 3.multiplicar; 4.dividir";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        ingreso_parametro();
        cout << suma(val_01, val_02);
        break;
    case 2:
        ingreso_parametro();
        cout << resta(val_01, val_02);
        break;
    case 3:
        ingreso_parametro();
        cout << multiplicacion(val_01, val_02);
        break;
    case 4:
        ingreso_parametro();
        cout << division(val_01, val_02);
        break;
    }
    /* do{
         cout<<"funciones"<<endl;


     }while(opcion !=5);*/
    return 0;
}
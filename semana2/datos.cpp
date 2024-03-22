#include <iostream>
#include <string>
#define const ;
using namespace std;

string frase1;
string frase2;
string frase3;
string frase4;
string cadena;

int main()
{
    frase1 = "Mi nombre es Javier, ";
    frase2 = "mi apellido es Tarrillo Cachique  ";
    frase3 = "mi edad es 19 y ";
    frase4 = "vivo en Tingo Maria";

    cadena = frase1 + frase2 + frase3 + frase4;
    cout << "El texto es" << endl
         << cadena;
}
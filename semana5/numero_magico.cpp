<<<<<<< HEAD
/*realice un programa que solicite a lusuario que piense
un numero entero 
entre el 1 y el 100. El progrmaa debe general un numero aleagorio en ese mismo
ranto[1-100], e indicarle al usuario si el numero que digito es menor o mayor al numero aleatorio, 
asi hasta que lo adivine. y por ultimo mostrarle el numero de intentos que le lelva. 

variable=limite_inferior+rand()%(limite_superior +1 - liimiete_inferior)*/
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    int n, dato, contador = 0;
    srand(time(NULL));
    dato = 1 + rand() % (100);
    do
    {
        cout << "Ingrese un numero: ";
        cin >> n;
        if (n > dato)
        {
            cout << "ingrese un numero menor: ";
        }
        if (n < dato)
        {
            cout << "ingrese un numero mayor: ";
        }
        contador++;
    } while (n != dato);
    cout << "felicidades adivinaste el numero" << endl;
    cout << "numero de intentos: " << contador << endl;
    return 0;
=======
/*realice un programa que solicite a lusuario que piense
un numero entero 
entre el 1 y el 100. El progrmaa debe general un numero aleagorio en ese mismo
ranto[1-100], e indicarle al usuario si el numero que digito es menor o mayor al numero aleatorio, 
asi hasta que lo adivine. y por ultimo mostrarle el numero de intentos que le lelva. 

variable=limite_inferior+rand()%(limite_superior +1 - liimiete_inferior)*/
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    int n, dato, contador = 0;
    srand(time(NULL));
    dato = 1 + rand() % (100);
    do
    {
        cout << "Ingrese un numero: ";
        cin >> n;
        if (n > dato)
        {
            cout << "ingrese un numero menor: ";
        }
        if (n < dato)
        {
            cout << "ingrese un numero mayor: ";
        }
        contador++;
    } while (n != dato);
    cout << "felicidades adivinaste el numero" << endl;
    cout << "numero de intentos: " << contador << endl;
    return 0;
>>>>>>> 8707b5c52440e91b588dffa2c913b719bf1d0324
}
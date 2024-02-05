#include <iostream>

int main()
{
    int numero, contador = 0;
    std::cout << "Ingrese un número entero positivo: ";
    std::cin >> numero;

    while (numero != 0)
    {
        numero /= 10; // Dividir el número por 10 elimina el último dígito
        contador++;
    }

    std::cout << "El número ingresado tiene " << contador << " dígitos." << std::endl;

    return 0;
}
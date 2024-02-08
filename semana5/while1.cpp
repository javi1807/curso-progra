<<<<<<< HEAD
/*Escribe un programa que solicite al usuario ingresar un número entero positivo n y luego calcule la
suma de todos los números pares desde 1 hasta n*/
#include <iostream>

int main()
{
    int n, suma = 0;
    std::cout << "Ingrese un número entero positivo: ";
    std::cin >> n;

    int i = 2; // Empezamos desde el primer número par
    while (i <= n)
    {
        suma += i;
        i += 2; // Incrementamos en 2 para obtener el siguiente número par
    }

    std::cout << "La suma de los números pares desde 1 hasta " << n << " es: " << suma << std::endl;

    return 0;
=======
/*Escribe un programa que solicite al usuario ingresar un número entero positivo n y luego calcule la
suma de todos los números pares desde 1 hasta n*/
#include <iostream>

int main()
{
    int n, suma = 0;
    std::cout << "Ingrese un número entero positivo: ";
    std::cin >> n;

    int i = 2; // Empezamos desde el primer número par
    while (i <= n)
    {
        suma += i;
        i += 2; // Incrementamos en 2 para obtener el siguiente número par
    }

    std::cout << "La suma de los números pares desde 1 hasta " << n << " es: " << suma << std::endl;

    return 0;
>>>>>>> 8707b5c52440e91b588dffa2c913b719bf1d0324
}
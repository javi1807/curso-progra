#include <iostream>

using namespace std;

int primo(int num)
{
    if (num <= 1)
        return 0;
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

void guardarPrimo(int num, int *arreglo, int *&ptr_indice)
{
    if (primo(num) && *ptr_indice < 10)
    {
        arreglo[*ptr_indice] = num;
        (*ptr_indice)++;
    }
}

int main()
{
    int arreglo[10];
    int indice = 0;
    int *ptr_indice = &indice;
    int numero;

    for (int i = 0; i < 10; ++i)
    {
        cout << "Introduce un numero: ";
        cin >> numero;
        guardarPrimo(numero, arreglo, ptr_indice);
    }

    cout << "Los numeros primos guardados en el arreglo son: ";
    for (int i = 0; i < indice; ++i)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    return 0;
}

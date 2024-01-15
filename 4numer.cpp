#include <iostream>

int main()
{
    float numeros[4];

    for (int i = 0; i < 4; ++i)
    {
        std::cout << "Ingrese el número " << i + 1 << ": ";
        std::cin >> numeros[i];
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3 - i; ++j)
        {
            if (numeros[j] > numeros[j + 1])
            {
                float temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }

    std::cout << "Números ordenados de menor a mayor: ";
    for (int i = 0; i < 4; ++i)
    {
        std::cout << numeros[i] << " ";
    }

    return 0;
}

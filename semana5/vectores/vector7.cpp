/*realize un programa que defina dos vectores de  caracteres y despues almacene el
contenido de ambos vectores, situando en primer lugar los elementos
del nuevo vector en la salida estandar*/
#include <iostream>
using namespace std;
int main()
{
    char letra1[] = {'a', 'b', 'c', 'd', 'e'}, letra2[] = {'f', 'g', 'h', 'i', 'j'}, letra3[10];
    for (int i = 0; i < 5; i++)
    {
        letra3[i] = letra1[i];
    }
    for (int i = 5; i < 10; i++)
    {
        letra3[i] = letra2[i - 5];
    }
    for (int i = 0; i < 10; i++)
    {
        cout << letra3[i] << endl;
    }

    return 0;
    
}
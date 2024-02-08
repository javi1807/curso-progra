/*hacer una matri de tipo entero de 2*2, llenarlo de numeros y luego
copiar todo su contenido hacia otra matriz*/
#include <iostream>
using namespace std;
int main()
{
    // rellenar la primera matriz primera
    int matriz[2][2], matriz2[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "digite los digitos de la matriz [" << i << "][" << j << "]: ";

            cin >> matriz[i][j];
        }
    }
    // pasando la matriz primera a la matriz segunda
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matriz2[i][j] = matriz[i][j];
        }
    }
    cout << endl;
    cout << "matriz segunda: " << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << matriz2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
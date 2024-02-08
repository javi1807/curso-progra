<<<<<<< HEAD
#include <iostream>
#include <stack>

using namespace std;

char convertir_a_letra(int nota)
{
    if (nota >= 18.5)
    {
        return 'A';
    }
    else if (nota >= 16.5)
    {
        return 'B';
    }
    else if (nota >= 14.5)
    {
        return 'C';
    }
    else if (nota >= 12.5)
    {
        return 'D';
    }
    else if (nota >= 10.5)
    {
        return 'E';
    }
    else
    {
        return 'F';
    }
}

int main()
{
    int notas[6];
    stack<char> pilas[6];

    cout << "Ingrese las 6 notas (en el rango de 0 a 20):" << endl;
    for (int i = 0; i < 6; ++i)
    {
        cout << "Nota " << i + 1 << ": ";
        cin >> notas[i];
    }

    for (int i = 0; i < 6; ++i)
    {
        char letra = convertir_a_letra(notas[i]);
        pilas[letra - 'A'].push(letra);
    }

    for (int i = 0; i < 6; ++i)
    {
        char letra = 'A' + i;
        cout << "Pila " << letra << ": ";
        while (!pilas[i].empty())
        {
            cout << pilas[i].top() << " ";
            pilas[i].pop();
        }
        cout << endl;
    }

    return 0;
}
=======
#include <iostream>
#include <stack>

using namespace std;

char convertir_a_letra(int nota)
{
    if (nota >= 18.5)
    {
        return 'A';
    }
    else if (nota >= 16.5)
    {
        return 'B';
    }
    else if (nota >= 14.5)
    {
        return 'C';
    }
    else if (nota >= 12.5)
    {
        return 'D';
    }
    else if (nota >= 10.5)
    {
        return 'E';
    }
    else
    {
        return 'F';
    }
}

int main()
{
    int notas[6];
    stack<char> pilas[6];

    cout << "Ingrese las 6 notas (en el rango de 0 a 20):" << endl;
    for (int i = 0; i < 6; ++i)
    {
        cout << "Nota " << i + 1 << ": ";
        cin >> notas[i];
    }

    for (int i = 0; i < 6; ++i)
    {
        char letra = convertir_a_letra(notas[i]);
        pilas[letra - 'A'].push(letra);
    }

    for (int i = 0; i < 6; ++i)
    {
        char letra = 'A' + i;
        cout << "Pila " << letra << ": ";
        while (!pilas[i].empty())
        {
            cout << pilas[i].top() << " ";
            pilas[i].pop();
        }
        cout << endl;
    }

    return 0;
}
>>>>>>> 8707b5c52440e91b588dffa2c913b719bf1d0324

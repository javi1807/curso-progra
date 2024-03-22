#include <iostream>
using namespace std;

int main()
{

    int N;

    cout << "Ingrese un valor entero positivo N: ";
    cin >> N;

    if (N <= 1)
    {
        cout << N << " no es primo." << endl;
    }
    else
    {
        bool es_primo = true;
        for (int i = 2; i * i <= N; ++i)
        {
            if (N % i == 0)
            {
                es_primo = false;
                break;
            }
        }

        if (es_primo)
        {
            cout << N << " es primo." << endl;
        }
        else
        {
            cout << N << " no es primo." << endl;
        }
    }

    return 0;
}

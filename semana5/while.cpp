#include <iostream>
using namespace std;

int main()
{
    int n, mayor;
    mayor = 0;
    while (n != 0)
    {
        cin >> n;
        if (n > mayor)
        {
            mayor = n;
        }
    }
    cout << "el numero mayor es: " << mayor << endl;
    return 0;
}
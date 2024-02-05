#include <iostream>
using namespace std;
int main()
{
    int numero[100], n;
    cout << "digite el numero de elementos del arreglo: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "digite un numero: " << endl;
        cin >> numero[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        cout << numero[i] << endl;
    }
    return 0;
}
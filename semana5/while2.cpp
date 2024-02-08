#include <iostream>

using namespace std;

int main()
{
    int n, factorial = 1, i = 1;
    cout << "digite el numero para calcular su factorial: " << endl;
    cin >> n;
    while (i <= n)
    {
        factorial *= i;
        i++;
    }
    cout << "el factorial de " << n << " es: " << factorial << endl;
    return 0;
}
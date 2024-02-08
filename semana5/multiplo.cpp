<<<<<<< HEAD
/*desarrollar un programa que guarde los 20 primeros numeros multiplos  de 9*/
#include <iostream>

using namespace std;

int main()
{
    int i, j, num;

    for (i = 1; i <= 20; i++)
    {
        num = i;
        for (j = 1; j <= 9; j++)
        {
            if (num % j == 0)
            {
                break;
            }
        }
        if (j > 9)
        {
            cout << num << endl;
        }
    }

    return 0;
=======
/*desarrollar un programa que guarde los 20 primeros numeros multiplos  de 9*/
#include <iostream>

using namespace std;

int main()
{
    int i, j, num;

    for (i = 1; i <= 20; i++)
    {
        num = i;
        for (j = 1; j <= 9; j++)
        {
            if (num % j == 0)
            {
                break;
            }
        }
        if (j > 9)
        {
            cout << num << endl;
        }
    }

    return 0;
>>>>>>> 8707b5c52440e91b588dffa2c913b719bf1d0324
}
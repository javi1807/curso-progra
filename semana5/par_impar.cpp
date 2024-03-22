<<<<<<< HEAD
#include <iostream>
using namespace std;

int main()
{
    /* we will count the numbers here */
    int Evens = 0, Odds = 0;

    /* we will store the incoming numbers here */
    int Number;

    /* read first number */
    cin >> Number;

    /* 0 terminates execution */
    while (Number != 0)
    {
        /* check if the number is odd */
        if (Number % 2 == 1)
            /* increase "odd" counter */
            Odds++;
        else
            /* increase "even" counter */
            Evens++;
        /* read next number */
        cin >> Number;
    }
    /* print results */
    cout << "Even numbers: " << Evens << endl;
    cout << "Odd numbers: " << Odds << endl;
    return 0;
=======
#include <iostream>
using namespace std;

int main()
{
    /* we will count the numbers here */
    int Evens = 0, Odds = 0;

    /* we will store the incoming numbers here */
    int Number;

    /* read first number */
    cin >> Number;

    /* 0 terminates execution */
    while (Number != 0)
    {
        /* check if the number is odd */
        if (Number % 2 == 1)
            /* increase "odd" counter */
            Odds++;
        else
            /* increase "even" counter */
            Evens++;
        /* read next number */
        cin >> Number;
    }
    /* print results */
    cout << "Even numbers: " << Evens << endl;
    cout << "Odd numbers: " << Odds << endl;
    return 0;
>>>>>>> 8707b5c52440e91b588dffa2c913b719bf1d0324
}
#include <iostream>
using namespace std;

int main()
{
    int numbers[5];
    int auxiliary;
    for (int i = 0; i < 5; i++)
    {
        numbers[i] = i + 1;
    }
    int numbers2[] = {1, 2, 3, 4, 5};

    /* swap elements #1 and #5 */
    auxiliary = numbers[0];  // 1
    numbers[0] = numbers[4]; // 5
    numbers[4] = auxiliary;  // 1
    cout << numbers[4] << endl;

    /* swap elements #2 and #4 */
    auxiliary = numbers[1];  // 2
    numbers[1] = numbers[3]; // 4
    numbers[3] = auxiliary;  // 2
    cout << numbers[3] << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << numbers[i];
    }

    for (int i = 0; i < 2; i++)
    {
        int n = 4 -i;
        auxiliary = numbers2[i];
        numbers2[i] = numbers2[n];
        numbers2[n] = auxiliary;
    }
    cout << endl<<"2da forma"<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout << numbers2[i];
    }
    return 0;
}
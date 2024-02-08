#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> pares;
    vector<int> impares;

    for(int i = 1; i <= 20; i++) {
        if(i % 2 == 0) {
            pares.push_back(i);
        } else {
            impares.push_back(i);
        }
    }

    cout << "Números pares: ";
    for(int i = 0; i < pares.size(); i++) {
        cout << pares[i] << " ";
    }
    cout << endl;

    cout << "Números impares: ";
    for(int i = 0; i < impares.size(); i++) {
        cout << impares[i] << " ";
    }
    cout << endl;

    return 0;
}
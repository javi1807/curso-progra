// elabora un programa que calcule el area de un triangulo conociendo sus 3 lados e identifique que tipo de triangulo es...

#include <iostream>
#include <cmath>
#include<stdlib.h>
using namespace std;

int main() {
    float a, b, c, s, area;
    cout << "Ingrese el primer lado: ";
    cin >> a;
    cout << "Ingrese el segundo lado: ";
    cin >> b;
    cout << "Ingrese el tercer lado: ";
    cin >> c;
    s = (a + b + c) / 2;
    area = sqrt(s * (s - a) * (s - b) * (s - c));
    cout << "El área del triángulo es: " << area << endl;
    if(a == b && b == c){
        cout << "Es un triángulo equilátero" << endl;
    } else if(a == b || b == c || a == c){
        cout << "Es un triángulo isósceles" << endl;
    } else{
        cout << "Es un triángulo escaleno" << endl;
    }
    system("pause");
    return 0;
}
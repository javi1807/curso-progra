#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    
    std::cout << "Ingrese el valor de a: ";
    std::cin >> a;
    
    std::cout << "Ingrese el valor de b: ";
    std::cin >> b;
    
    std::cout << "Ingrese el valor de c: ";
    std::cin >> c;
    
    // Calcula el discriminante
    double discriminante = b * b - 4 * a * c;
    
    // Comprueba si el discriminante es positivo, negativo o cero
    if (discriminante > 0) {
        double x1 = (-b + sqrt(discriminante)) / (2 * a);
        double x2 = (-b - sqrt(discriminante)) / (2 * a);
        std::cout << "Las soluciones son x1 = " << x1 << " y x2 = " << x2 << std::endl;
    } else if (discriminante == 0) {
        double x1 = -b / (2 * a);
        std::cout << "La solución doble es x = " << x1 << std::endl;
    } else {
        std::cout << "La ecuación no tiene soluciones reales." << std::endl;
    }
    
    return 0;
}
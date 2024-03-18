#include <iostream>
#include <cmath> 
#include <string>
using namespace std;

class Triangulo 
{
private: 
    float lado1; 
    float lado2; 
    float lado3;
    
public: 
    // Constructores
    Triangulo(float l1, float l2, float l3){
        lado1 = l1; 
        lado2 = l2; 
        lado3 = l3;
    }
    
    Triangulo(){ }
    
    // Getter y Setter
    float getLado1(){
        return lado1; 
    }
    
    void setLado1(float l){
        lado1 = l;
    }
    
    float getLado2(){
        return lado2;
    }
    
    void setLado2(float l2){
        lado2 = l2;
    }
    
    float getLado3(){
        return lado3;
    }
    
    void setLado3(float l3){
        lado3 = l3;
    }
    
    // metodos del triángulo
    string tipo_triangulo(){
        if(lado1 == lado2 && lado2 == lado3)
            return "Equilatero";
        else if(lado1 == lado2 || lado1 == lado3 || lado2 == lado3)
            return "Isosceles";
        else
            return "Escaleno";
    }
    
    float area(){
        float s = (lado1 + lado2 + lado3) / 2;
        return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    }
    
    float perimetro(){
        return lado1 + lado2 + lado3;
    }
};

int main() {
    Triangulo t(4, 5, 6);
    
    cout << "tipo de triangulo: " << t.tipo_triangulo() << endl;
    cout << "area del triangulo: " << t.area() << endl;
    cout << "perimetro del triangulo: " << t.perimetro() << endl;
    
    return 0;
}
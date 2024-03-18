#include <iostream>
using namespace std;

class Rectangulo
{
private:
    float longitud;
    float ancho;

public:
    // constructor
    Rectangulo(float l, float a)
    {
        longitud = l;
        ancho = a;
    }
    Rectangulo() {  }

    // getter ans setter --> para manipular variables
    float getLongitud()
    {
        return longitud;
    }
    void setLongitud(float l)
    {
        longitud = l;
    }
    float getAncho()
    {
        return ancho;
    }
    void setAncho(float a)
    {
        ancho = a;
    }
    // metodos de rectangulo
    float calcular_area()
    {
        return longitud * ancho;
    }

    float calcular_area(float l, float a)
    {
        return l * a;
    }

    float perimetro()
    {
        return 2 * (longitud + ancho);
    }
};

int main()
{
    Rectangulo rect(5.0, 2.5);
    Rectangulo rect_02;
    rect_02.setLongitud(5.0);
    rect_02.setAncho(2.5);

    cout<<"el valor de la longitud del rectangulo 2 es: ";
    cout<<rect_02.getLongitud()<<endl;
    cout<<rect_02.getAncho()<<endl;


}
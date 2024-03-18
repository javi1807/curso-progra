#include <iostream>
#include <string>
using namespace std;

class Carro
{
protected:
    /* data */
    int id;
    string modelo;
    int año_fabricacion;
    // int nro_acientos;
    string color;
    string marca;
    float velocidad;
    bool encedido;
    // string cilindrada;
    // string motor;
public:
    Carro(int _id, string _modelo, int _año_fabricacion, string _color, string _marca)
    {
        id = _id;
        modelo = _modelo;
        año_fabricacion = _año_fabricacion;
        color = _color;
        marca = _marca;
        velocidad = 0;
        encedido = false;
    }

    /*Getter and Setter*/
    int getId()
    {
        return id;
    }
    void setId(int _id)
    {
        id = _id;
    }

    string getModelo()
    {
        return modelo;
    }

    void setModelo(string _modelo)
    {
        modelo = _modelo;
    }

    int getAñoFabricacion()
    {
        return año_fabricacion;
    }

    void setAñoFabricacion(int _año)
    {
        año_fabricacion = _año;
    }
    string getColor()
    {
        return color;
    }
    void setColor(string _color)
    {
        color = _color;
    }
    string getMarca()
    {
        return marca;
    }
    void setMarca(string _marca)
    {
        marca = _marca;
    }

    float getVelocidad()
    {
        return velocidad;
    }
    void setVelocidad(float _velocidad)
    {
        velocidad = _velocidad;
    }

    /*metodos para acciones*/
    void acelerar(float _velocidad)
    {
        if (encedido != false)
        {
            velocidad = velocidad + _velocidad;
        }
    }

    void frenar(float _velocidad)
    {
        if (velocidad != 0 && _velocidad < velocidad)
        {
            velocidad = velocidad - _velocidad;
        }
        else
        {
            cout << "El vehiculo se encuenta detenido" << endl;
        }
    }

    void encender()
    {
        encedido = true;
    }

    void apagar()
    {
        encedido = false;
    }
};
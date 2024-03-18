#include <iostream>
using namespace std;
class Carro
{
private:
    int id;
    string modelo;
    int año_fabricacion;
    int nro_asientos;
    string color;
    string marca;
    float velocidad;
    bool encendido;
    // string cilindrada;
    // string motor;
public:
    Carro(int _id, string _modelo, int _año_fabricacion, int _nro_asientos, string _color, string _marca)
    {
        id = _id;
        modelo = _modelo;
        año_fabricacion = _año_fabricacion;
        nro_asientos = _nro_asientos;
        color = _color;
        marca = _marca;
        velocidad = 0;
        encendido = false;
    }
    Carro()
    {
    }
    // getter and setter
    int getId()
    {
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
    int getAño_fabricacion()
    {
        return año_fabricacion;
    }
    void setAño_fabricacion(int _año_fabricacion)
    {
        año_fabricacion = _año_fabricacion;
    }
    int getNro_asientos()
    {
        return nro_asientos;
    }
    void setNro_asientos(int _nro_asientos)
    {
        nro_asientos = _nro_asientos;
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
    // metodos
    void acelerar(float _velocidad)
    {
        if (encendido != false)
        {
            velocidad = velocidad + _velocidad;
        }
    }
    float frenar(float _velocidad)
    {
        if (velocidad != 0 && _velocidad < velocidad)
        {
            velocidad = velocidad - _velocidad;
        }
    }
    void encender()
    {
        

    }
    void apagar()
    {
    }
};
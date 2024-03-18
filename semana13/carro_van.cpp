#include <iostream>
#include <string>
#include "carro.cpp"
using namespace std;

class CarroVan : public Carro
{
private:
    /* data */
    int id_van;
    int nro_acientos;
    string cilindrada;
    string motor;

public:
    CarroVan(int _idVan = 0, int nro_aciento = 0, string _cilindrad = " ", string _motor = " ", int idCarro = 0, string _modelo = " ", int _año_fabricacion = 0, string _color = " ", string _marca = " ") : Carro(idCarro, _modelo, _año_fabricacion, _color, _marca)
    {
        id_van = _idVan;
        nro_acientos = nro_aciento;
        cilindrada = _cilindrad;
        motor = _motor;

    }

    int GetId_van() const
    {
        return id_van;
    }

    void SetId_van(int id_van)
    {
        id_van = id_van;
    }

    int GetNro_acientos() const
    {
        return nro_acientos;
    }

    void SetNro_acientos(int nro_acientos)
    {
        nro_acientos = nro_acientos;
    }

    string GetCilindrada() const
    {
        return cilindrada;
    }

    void SetCilindrada(string cilindrada)
    {
        cilindrada = cilindrada;
    }

    string GetMotor() const
    {
        return motor;
    }

    void SetMotor(string motor)
    {
        motor = motor;
    }

    string getModeloVan()
    {
        return getModelo();
    }
};
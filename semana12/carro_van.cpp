#include <iostream>
#include <string>
#include "carro.cpp"
using namespace std;
class CarroVan : Carro
{
    private:
    int id_van;
    int nro_asientos;
    string cilindrado;
    string motor;

    public:

    CarroVan() : Carro(){

    }
    CarroVan(int _idVan, int _nro_asientos, string _cilindrado, string _motor){
        id_van = _idVan;
        nro_asientos = _nro_asientos;
        cilindrado = _cilindrado;
        motor = _motor;
    }
    //getter and setter
};
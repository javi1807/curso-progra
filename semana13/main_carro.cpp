#include <iostream>
#include <string>
#include "carro_van.cpp"
using namespace std;

int main(){

    CarroVan carro_van(1,16,"1500 cc","2.0 petrolero",1,"Van",2024,"Rosa","Hyundai");
    cout<<carro_van.getModelo();
    
    return 0;
}


#include <iostream>
using namespace std;

struct Cliente {
    int tipoTarjeta;
    double limiteCredito;
    double saldoActual;
    bool tieneDeuda;
};

int main() {
    Cliente cliente;
    cout << "\n BIENVENIDOS A TINGOBAKN \n";
    // El usuario introduce la información del cliente
    cout << "Por favor, introduce el tipo de tarjeta: ";
    cin >> cliente.tipoTarjeta;

    cout << "Por favor, introduce tu límite de crédito actual: ";
    cin >> cliente.limiteCredito;

    cout << "Por favor, introduce tu saldo actual: ";
    cin >> cliente.saldoActual;

    cout << "¿Tienes deudas? (1 para sí, 0 para no): ";
    cin >> cliente.tieneDeuda;

    // Calcula el nuevo límite de crédito
    double aumento = 0;

    if(cliente.tipoTarjeta == 1) {
        aumento = cliente.tieneDeuda ? 0.125 : 0.25;
    } else if(cliente.tipoTarjeta == 2) {
        aumento = cliente.tieneDeuda ? 0.175 : 0.35;
    } else if(cliente.tipoTarjeta == 3) {
        aumento = 0.4;
    } else {
        aumento = 0.5;
    }

    cliente.limiteCredito += cliente.limiteCredito * aumento;
    cout<<" \n \n";
    cout<< "GRACIAS POR CONFIAR EN TINGOBAKN " << " \n ESTA ES TU INFORMACION"<< endl;
    cout << "Tu nuevo límite de crédito es: " << cliente.limiteCredito << endl;
    cout << "Tu saldo actual es: " << cliente.saldoActual << endl;

    return 0;
}
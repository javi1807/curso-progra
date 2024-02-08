#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> // Para la función rand()
#include <ctime>   // Para la función time()

using namespace std;

const int MAX_CLIENTES = 50;
const int MAX_PRODUCTOS = 50;

struct Cliente
{
    string nombre;
    int id;
    int telefono;
};

struct Producto
{
    string nombre;
    int codigo;
    int cantidad;
    float precio;
};

void menu()
{
    cout << "\n****************************TIENDA VIRTUAL****************************";
    cout << "\n1. Crear cliente nuevo.";
    cout << "\n2. Ver clientes ingresados.";
    cout << "\n3. Crear inventario.";
    cout << "\n4. Ver inventario";
    cout << "\n5. Vender un producto.";
    cout << "\n6. Salir.";
    cout << "\nIngrese su opcion: ";
}

int generarIdUnico(int idsUtilizados[], int numClientes)
{
    int id;
    bool esUnico;

    do
    {
        id = rand() % 10000 + 1; // Genera un número aleatorio entre 1 y 10000

        esUnico = true;
        for (int i = 0; i < numClientes; i++)
        {
            if (idsUtilizados[i] == id)
            {
                esUnico = false;
                break;
            }
        }
    } while (!esUnico);

    return id;
}

int main()
{
    int opcion, opc2;
    int numClientes = 0, numProductos = 0;

    Cliente clientes[MAX_CLIENTES];
    Producto productos[MAX_PRODUCTOS];
    int idsUtilizados[MAX_CLIENTES] = {0}; // Array para almacenar los IDs ya utilizados

    // Inicializamos la semilla para la generación de números aleatorios
    srand(time(nullptr));

    do
    {
        menu();
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            if (numClientes < MAX_CLIENTES)
            {
                cout << "\nIngrese el nombre del cliente nuevo: ";
                cin >> clientes[numClientes].nombre;
                cout << "Ingrese el numero de telefono del cliente nuevo (Sin espacios ni guiones): ";
                cin >> clientes[numClientes].telefono;

                // Generamos un ID único
                clientes[numClientes].id = generarIdUnico(idsUtilizados, numClientes);
                idsUtilizados[numClientes] = clientes[numClientes].id;

                numClientes++;
            }
            else
            {
                cout << "Limite de clientes alcanzado." << endl;
            }
            break;

        case 2:
            for (int i = 0; i < numClientes; i++)
            {
                cout << "\nNombre de cliente: " << clientes[i].nombre << endl;
                cout << "Numero de ID de cliente: " << clientes[i].id << endl;
                cout << "Numero de telefono de cliente: " << clientes[i].telefono << endl;
            }
            break;

        case 3:
            if (numProductos < MAX_PRODUCTOS)
            {
                cout << "\nIngrese el nombre del producto: ";
                cin >> productos[numProductos].nombre;
                cout << "Ingrese el codigo del producto: ";
                cin >> productos[numProductos].codigo;
                cout << "Ingrese el precio del producto: ";
                cin >> productos[numProductos].precio;
                cout << "Ingrese la cantidad de productos: ";
                cin >> productos[numProductos].cantidad;
                numProductos++;
            }
            else
            {
                cout << "Limite de productos alcanzado." << endl;
            }
            break;

        case 4:
            for (int i = 0; i < numProductos; i++)
            {
                cout << "\nNombre del producto: " << productos[i].nombre << endl;
                cout << "Codigo del producto: " << productos[i].codigo << endl;
                cout << "Precio del producto: " << productos[i].precio << endl;
                cout << "Cantidad en inventario: " << productos[i].cantidad << endl;
            }
            break;

        case 5:
            if (numProductos == 0)
            {
                cout << "No hay productos en el inventario para vender." << endl;
            }
            else
            {
                int cod_producto;
                cout << "\nIngrese el codigo del producto a vender: ";
                cin >> cod_producto;
                int indice_producto = -1;
                for (int i = 0; i < numProductos; i++)
                {
                    if (productos[i].codigo == cod_producto)
                    {
                        indice_producto = i;
                        break;
                    }
                }
                if (indice_producto == -1)
                {
                    cout << "El producto con el codigo ingresado no existe en el inventario." << endl;
                }
                else
                {
                    int cantidad;
                    cout << "Ingrese la cantidad a vender: ";
                    cin >> cantidad;
                    if (cantidad <= 0)
                    {
                        cout << "La cantidad ingresada no es válida." << endl;
                    }
                    else if (cantidad <= productos[indice_producto].cantidad)
                    {
                        cout << "Venta realizada con éxito." << endl;
                        productos[indice_producto].cantidad -= cantidad;
                    }
                    else
                    {
                        cout << "La cantidad ingresada supera el stock disponible." << endl;
                    }
                }
            }
            break;

        case 6:
            cout << "Saliendo del programa." << endl;
            return 0;

        default:
            cout << "Ha elegido una opcion invalida." << endl;
        }

        cout << "\nIngrese 1 para volver al menu y 0 para salir: ";
        cin >> opc2;
    } while (opc2 == 1);

    return 0;
}

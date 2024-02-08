<<<<<<< HEAD
#include <iostream> // Incluye la biblioteca estándar de entrada y salida.
#include <string>   // Incluye la biblioteca estándar para trabajar con cadenas de caracteres.
#include <iomanip>  // Incluye la biblioteca estándar para manipulación de formato de salida.

using namespace std; // Utiliza el espacio de nombres estándar.

const int MAX_CLIENTES = 50;  // Define la cantidad máxima de clientes.
const int MAX_PRODUCTOS = 50; // Define la cantidad máxima de productos.

// Función para mostrar el menú de opciones.
void menu()
{
    cout << "\n****************************TIENDA VIRTUAL****************************"; // Imprime el encabezado del menú.
    cout << "\n1. Crear cliente nuevo.";                                                // Imprime la opción para crear un nuevo cliente.
    cout << "\n2. Ver clientes ingresados.";                                            // Imprime la opción para ver los clientes registrados.
    cout << "\n3. Crear inventario.";                                                   // Imprime la opción para crear un nuevo producto en el inventario.
    cout << "\n4. Ver inventario";                                                      // Imprime la opción para ver los productos en el inventario.
    cout << "\n5. Vender un producto.";                                                 // Imprime la opción para vender un producto.
    cout << "\n6. Salir.";                                                              // Imprime la opción para salir del programa.
    cout << "\nIngrese su opcion: ";                                                    // Solicita al usuario que ingrese su elección.
}

int main()
{
    int opcion, opc2;                      // Variables para almacenar la opción seleccionada por el usuario y la opción para continuar en el menú.
    int numClientes = 0, numProductos = 0; // Contadores para el número de clientes y productos.

    // Arreglos para almacenar la información de los clientes.
    string nombre_cliente[MAX_CLIENTES]; // Arreglo de nombres de clientes.
    int id[MAX_CLIENTES];                // Arreglo de identificaciones de clientes.
    int tel[MAX_CLIENTES];               // Arreglo de números de teléfono de clientes.

    // Arreglos para almacenar la información de los productos.
    string nombre_producto[MAX_PRODUCTOS]; // Arreglo de nombres de productos.
    int codigo[MAX_PRODUCTOS];             // Arreglo de códigos de productos.
    int cantidad_producto[MAX_PRODUCTOS];  // Arreglo de cantidades de productos en inventario.
    float precio_producto[MAX_PRODUCTOS];  // Arreglo de precios de productos.

    // Bucle principal que muestra el menú y procesa las opciones del usuario.
    do
    {
        menu();        // Llama a la función menu() para mostrar el menú.
        cin >> opcion; // Lee la opción seleccionada por el usuario.

        switch (opcion) // Evalúa la opción seleccionada por el usuario.
        {
        case 1:                             // Opción para crear un nuevo cliente.
            if (numClientes < MAX_CLIENTES) // Verifica si hay espacio disponible para agregar un nuevo cliente.
            {
                // Solicita y lee la información del nuevo cliente.
                cout << "\nIngrese el nombre del cliente nuevo: ";
                cin >> nombre_cliente[numClientes];
                cout << "Ingrese el numero de ID del cliente nuevo (Sin espacios ni guiones): ";
                cin >> id[numClientes];
                cout << "Ingrese el numero de telefono del cliente nuevo (Sin espacios ni guiones): ";
                cin >> tel[numClientes];
                numClientes++; // Incrementa el contador de clientes.
            }
            else
            {
                cout << "Limite de clientes alcanzado." << endl; // Indica al usuario que se ha alcanzado el límite de clientes.
            }
            break;
        case 2: // Opción para ver los clientes ingresados.
            // Itera sobre los clientes registrados y muestra su información.
            for (int i = 0; i < numClientes; i++)
            {
                cout << "\nNombre de cliente: " << nombre_cliente[i] << endl;
                cout << "Numero de ID de cliente: " << id[i] << endl;
                cout << "Numero de telefono de cliente: " << tel[i] << endl;
            }
            break;

        case 3:                               // Opción para crear un nuevo producto en el inventario.
            if (numProductos < MAX_PRODUCTOS) // Verifica si hay espacio disponible para agregar un nuevo producto.
            {
                // Solicita y lee la información del nuevo producto.
                cout << "\nIngrese el nombre del producto: ";
                cin >> nombre_producto[numProductos];
                cout << "Ingrese el codigo del producto: ";
                cin >> codigo[numProductos];
                cout << "Ingrese el precio del producto: ";
                cin >> precio_producto[numProductos];
                cout << "Ingrese la cantidad de productos: ";
                cin >> cantidad_producto[numProductos];
                numProductos++; // Incrementa el contador de productos.
            }
            else
            {
                cout << "Limite de productos alcanzado." << endl; // Indica al usuario que se ha alcanzado el límite de productos.
            }
            break;

        case 4: // Opción para ver el inventario de productos.
            // Itera sobre los productos registrados y muestra su información.
            for (int i = 0; i < numProductos; i++)
            {
                cout << "\nNombre del producto: " << nombre_producto[i] << endl;
                cout << "Codigo del producto: " << codigo[i] << endl;
                cout << "Precio del producto: " << precio_producto[i] << endl;
                cout << "Cantidad en inventario: " << cantidad_producto[i] << endl;
            }
            break;

        case 5: // Opción para vender un producto.
            // Verifica si hay productos en el inventario para vender.
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
                // Busca el producto en el inventario por su código.
                for (int i = 0; i < numProductos; i++)
                {
                    if (codigo[i] == cod_producto)
                    {
                        indice_producto = i;
                        break;
                    }
                }
                // Verifica si el producto existe en el inventario.
                if (indice_producto == -1)
                {
                    cout << "El producto con el codigo ingresado no existe en el inventario." << endl;
                }
                else
                {
                    int cantidad;
                    cout << "Ingrese la cantidad a vender: ";
                    cin >> cantidad;
                    // Verifica si la cantidad ingresada es válida y hay suficiente stock.
                    if (cantidad <= 0)
                    {
                        cout << "La cantidad ingresada no es válida." << endl;
                    }
                    else if (cantidad <= cantidad_producto[indice_producto])
                    {
                        cout << "Venta realizada con éxito." << endl;
                        // Reduce la cantidad vendida del inventario.
                        cantidad_producto[indice_producto] -= cantidad;
                    }
                    else
                    {
                        cout << "La cantidad ingresada supera el stock disponible." << endl;
                    }
                }
            }
            break;

        case 6: // Opción para salir del programa.
            cout << "Saliendo del programa." << endl;
            return 0; // Finaliza la ejecución del programa.

        default: // Opción por defecto para manejar entradas no válidas.
            cout << "Ha elegido una opcion invalida." << endl;
        }

        cout << "\nIngrese 1 para volver al menu y 0 para salir: ";
        cin >> opc2;     // Solicita al usuario que ingrese 1 para continuar en el menú o 0 para salir.
    } while (opc2 == 1); // Continúa mostrando el menú mientras el usuario seleccione 1.
    return 0;            // Finaliza la ejecución del programa.
}
=======
#include <iostream> // Incluye la biblioteca estándar de entrada y salida.
#include <string>   // Incluye la biblioteca estándar para trabajar con cadenas de caracteres.
#include <iomanip>  // Incluye la biblioteca estándar para manipulación de formato de salida.

using namespace std; // Utiliza el espacio de nombres estándar.

const int MAX_CLIENTES = 50;  // Define la cantidad máxima de clientes.
const int MAX_PRODUCTOS = 50; // Define la cantidad máxima de productos.

// Función para mostrar el menú de opciones.
void menu()
{
    cout << "\n****************************TIENDA VIRTUAL****************************"; // Imprime el encabezado del menú.
    cout << "\n1. Crear cliente nuevo.";                                                // Imprime la opción para crear un nuevo cliente.
    cout << "\n2. Ver clientes ingresados.";                                            // Imprime la opción para ver los clientes registrados.
    cout << "\n3. Crear inventario.";                                                   // Imprime la opción para crear un nuevo producto en el inventario.
    cout << "\n4. Ver inventario";                                                      // Imprime la opción para ver los productos en el inventario.
    cout << "\n5. Vender un producto.";                                                 // Imprime la opción para vender un producto.
    cout << "\n6. Salir.";                                                              // Imprime la opción para salir del programa.
    cout << "\nIngrese su opcion: ";                                                    // Solicita al usuario que ingrese su elección.
}

int main()
{
    int opcion, opc2;                      // Variables para almacenar la opción seleccionada por el usuario y la opción para continuar en el menú.
    int numClientes = 0, numProductos = 0; // Contadores para el número de clientes y productos.

    // Arreglos para almacenar la información de los clientes.
    string nombre_cliente[MAX_CLIENTES]; // Arreglo de nombres de clientes.
    int id[MAX_CLIENTES];                // Arreglo de identificaciones de clientes.
    int tel[MAX_CLIENTES];               // Arreglo de números de teléfono de clientes.

    // Arreglos para almacenar la información de los productos.
    string nombre_producto[MAX_PRODUCTOS]; // Arreglo de nombres de productos.
    int codigo[MAX_PRODUCTOS];             // Arreglo de códigos de productos.
    int cantidad_producto[MAX_PRODUCTOS];  // Arreglo de cantidades de productos en inventario.
    float precio_producto[MAX_PRODUCTOS];  // Arreglo de precios de productos.

    // Bucle principal que muestra el menú y procesa las opciones del usuario.
    do
    {
        menu();        // Llama a la función menu() para mostrar el menú.
        cin >> opcion; // Lee la opción seleccionada por el usuario.

        switch (opcion) // Evalúa la opción seleccionada por el usuario.
        {
        case 1:                             // Opción para crear un nuevo cliente.
            if (numClientes < MAX_CLIENTES) // Verifica si hay espacio disponible para agregar un nuevo cliente.
            {
                // Solicita y lee la información del nuevo cliente.
                cout << "\nIngrese el nombre del cliente nuevo: ";
                cin >> nombre_cliente[numClientes];
                cout << "Ingrese el numero de ID del cliente nuevo (Sin espacios ni guiones): ";
                cin >> id[numClientes];
                cout << "Ingrese el numero de telefono del cliente nuevo (Sin espacios ni guiones): ";
                cin >> tel[numClientes];
                numClientes++; // Incrementa el contador de clientes.
            }
            else
            {
                cout << "Limite de clientes alcanzado." << endl; // Indica al usuario que se ha alcanzado el límite de clientes.
            }
            break;
        case 2: // Opción para ver los clientes ingresados.
            // Itera sobre los clientes registrados y muestra su información.
            for (int i = 0; i < numClientes; i++)
            {
                cout << "\nNombre de cliente: " << nombre_cliente[i] << endl;
                cout << "Numero de ID de cliente: " << id[i] << endl;
                cout << "Numero de telefono de cliente: " << tel[i] << endl;
            }
            break;

        case 3:                               // Opción para crear un nuevo producto en el inventario.
            if (numProductos < MAX_PRODUCTOS) // Verifica si hay espacio disponible para agregar un nuevo producto.
            {
                // Solicita y lee la información del nuevo producto.
                cout << "\nIngrese el nombre del producto: ";
                cin >> nombre_producto[numProductos];
                cout << "Ingrese el codigo del producto: ";
                cin >> codigo[numProductos];
                cout << "Ingrese el precio del producto: ";
                cin >> precio_producto[numProductos];
                cout << "Ingrese la cantidad de productos: ";
                cin >> cantidad_producto[numProductos];
                numProductos++; // Incrementa el contador de productos.
            }
            else
            {
                cout << "Limite de productos alcanzado." << endl; // Indica al usuario que se ha alcanzado el límite de productos.
            }
            break;

        case 4: // Opción para ver el inventario de productos.
            // Itera sobre los productos registrados y muestra su información.
            for (int i = 0; i < numProductos; i++)
            {
                cout << "\nNombre del producto: " << nombre_producto[i] << endl;
                cout << "Codigo del producto: " << codigo[i] << endl;
                cout << "Precio del producto: " << precio_producto[i] << endl;
                cout << "Cantidad en inventario: " << cantidad_producto[i] << endl;
            }
            break;

        case 5: // Opción para vender un producto.
            // Verifica si hay productos en el inventario para vender.
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
                // Busca el producto en el inventario por su código.
                for (int i = 0; i < numProductos; i++)
                {
                    if (codigo[i] == cod_producto)
                    {
                        indice_producto = i;
                        break;
                    }
                }
                // Verifica si el producto existe en el inventario.
                if (indice_producto == -1)
                {
                    cout << "El producto con el codigo ingresado no existe en el inventario." << endl;
                }
                else
                {
                    int cantidad;
                    cout << "Ingrese la cantidad a vender: ";
                    cin >> cantidad;
                    // Verifica si la cantidad ingresada es válida y hay suficiente stock.
                    if (cantidad <= 0)
                    {
                        cout << "La cantidad ingresada no es válida." << endl;
                    }
                    else if (cantidad <= cantidad_producto[indice_producto])
                    {
                        cout << "Venta realizada con éxito." << endl;
                        // Reduce la cantidad vendida del inventario.
                        cantidad_producto[indice_producto] -= cantidad;
                    }
                    else
                    {
                        cout << "La cantidad ingresada supera el stock disponible." << endl;
                    }
                }
            }
            break;

        case 6: // Opción para salir del programa.
            cout << "Saliendo del programa." << endl;
            return 0; // Finaliza la ejecución del programa.

        default: // Opción por defecto para manejar entradas no válidas.
            cout << "Ha elegido una opcion invalida." << endl;
        }

        cout << "\nIngrese 1 para volver al menu y 0 para salir: ";
        cin >> opc2;     // Solicita al usuario que ingrese 1 para continuar en el menú o 0 para salir.
    } while (opc2 == 1); // Continúa mostrando el menú mientras el usuario seleccione 1.
    return 0;            // Finaliza la ejecución del programa.
}
>>>>>>> 8707b5c52440e91b588dffa2c913b719bf1d0324

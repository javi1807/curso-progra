/*7. Desarrollar un programa que determine si una matriz es simétrica o no. Una matriz
es simétrica si es cuadrada y si es igual a su matriz transpuesta.


|8 1 3|        |8 1 3|
|1 7 4|  -->   |1 7 4| 
|3 4 9|        |3 4 9|

*/

#include<iostream> // Librería estándar para entrada/salida de datos.
#include<conio.h> // Librería para utilizar la función getch().

using namespace std; // Uso del espacio de nombres estándar de C++.

int main(){
	int numeros[100][100],filas,columnas; // Declaración de una matriz de números, y variables para el número de filas y columnas.
	char band='F'; // Variable de tipo char para determinar si la matriz es simétrica o no.

	cout<<"Digite el numero de filas: "; cin>>filas; // Se solicita al usuario el número de filas.
	cout<<"Digite el numero de columnas: "; cin>>columnas; // Se solicita al usuario el número de columnas.
	
	//Rellenando matriz
	for(int i=0;i<filas;i++){ // Bucle para recorrer las filas de la matriz.
		for(int j=0;j<columnas;j++){ // Bucle para recorrer las columnas de la matriz.
			cout<<"Digite un numero ["<<i<<"]["<<j<<"]: "; // Se solicita al usuario que ingrese un número en la posición [i][j] de la matriz.
			cin>>numeros[i][j]; // Se guarda el número ingresado en la matriz.
		}
	}
	
	//Comprobemos si es simetrica
	if(filas==columnas){ // Se verifica si el número de filas es igual al número de columnas (la matriz es cuadrada).
		for(int i=0;i<filas;i++){ // Bucle para recorrer las filas de la matriz.
			for(int j=0;j<columnas;j++){ // Bucle para recorrer las columnas de la matriz.
				if(numeros[i][j] == numeros[j][i]){ // Se compara cada elemento de la matriz con su correspondiente elemento reflejado.
					band='V'; // Si la matriz es simétrica, se cambia el valor de la variable band a 'V'.
				}
			}
		}
	}

	if(band=='V'){ // Si la variable band es 'V', significa que la matriz es simétrica.
		cout<<"\nEs una matriz simetrica"; // Se imprime un mensaje indicando que la matriz es simétrica.
	}
	else{
		cout<<"\nNo es una matriz simetrica"; // Si la variable band es 'F', significa que la matriz no es simétrica.
	}
	
	getch(); // Espera a que el usuario presione una tecla antes de cerrar la consola.
	return 0; // Indica que el programa finalizó correctamente.
}

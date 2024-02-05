#include <iostream>
using namespace std;
int main(){
	int numero[8],suma=0,i;
	
	for (i=0;i<8;i++){
		cout<<"numeros para el arreglo: "<<endl;
		cin>>numero[i];
		
	}
	for(i=0;i<8;i++){
		suma += numero[i];
	}
	cout<<"la suma es: "<<suma<<endl;
	return 0;
}
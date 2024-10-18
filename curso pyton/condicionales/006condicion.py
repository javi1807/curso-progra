'''ejercicio 4:
construir un programa que simule el funcionameinto de una calculadora
que puede realizar las cuatro operaciones aritmeticas basica
(suma, resta, multiplicacion y division). el usuario debe 
especificar la operacion con el primer caracter del nombre de la  operacion'''
n1=float(input("digite el primero numero: "))
n2=float(input("digite el segundo numero: "))

operacion=input("digite la operacion que desea realizar: ").lower()

if operacion == 's':
    print("la suma es: ",n1+n2)

elif operacion == 'r':
    print("la resta es: ",n1-n2)
elif operacion == 'm':
    print("la multiplicacion es: ",n1*n2)
elif operacion =='d':
    if n2==0:
        print("no se puede dividir por cero")
    else:
        print("la division es: ",n1/n2)
    
else:
    print("la operacion no es valida")
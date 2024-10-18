'''Ejercicio2:
hacer un programa que pida 3 numeros y determine cual es el mayor'''
n1=int(input("digite el primer numero: "))
n2=int(input("digite el segundo numero: "))
n3=int(input("digite el tercer numero: "))
if n1>=n2 and n1>=n3:
    print("el numero mayor es: ",n1)
elif n2>=n1 and n2>=n3:
    print ("el numero mayor es: ",n2)
elif n3>=n1 and n3>=n2:
    print("el numero mayor es: ",n3)
else: 
    print ("los numeros son iguales")
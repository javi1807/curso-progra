'''
Ejercicio1:
hacer un programa que pida 2 numeros y se de cuenta cual de ellos es par,
o si ambos lo son'''
num1=int(input("digite un numero: "))
num2=int(input("digite un numero:"))
if num1%2==0 and num2%2==0:
    print("Ambos son pares")
elif num1%2==0 and num2%2!=0:
    print(f"{num1}  es par")
elif num1%2!=0 and num2%2==0:
    print(f"{num2} es par")
else:
    print(f"{num1} y {num2} son impares")
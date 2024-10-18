'''Ejercicio 3:
hacer un programa que pida un caracter e indique si es un vocal o no'''
caracter1 = input("digite una letra").lower()
if caracter1 =="a" or caracter1 == "e" or caracter1 == "i" or caracter1 == "o" or caracter1 == "u":
    print("la letra es vocal")
else: 
    print ("la letra no es una vocal")
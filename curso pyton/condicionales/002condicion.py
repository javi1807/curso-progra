#condicionales combinados
edad= int(input("dgite su edad: "))
if 0<edad<100:
    print("Edad correcta\n")
    if edad>=18:
        print("Es mayor de edad\n")
    
else:
    print("Edad incorrecta\n")
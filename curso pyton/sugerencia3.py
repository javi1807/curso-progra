import os

# Archivo para almacenar usuarios
USUARIOS_FILE = "usuarios.txt"
# Archivo para almacenar quejas y sugerencias
QUEJAS_SUGERENCIAS_FILE = "quejas_sugerencias.txt"

def registrar_usuario(usuario, contraseña):
    with open(USUARIOS_FILE, "a") as file:
        file.write(f"{usuario},{contraseña}\n")

def verificar_usuario(usuario, contraseña):
    if not os.path.exists(USUARIOS_FILE):
        return False
    with open(USUARIOS_FILE, "r") as file:
        for line in file:
            stored_usuario, stored_contraseña = line.strip().split(",")
            if stored_usuario == usuario and stored_contraseña == contraseña:
                return True
    return False

def agregar_queja_sugerencia(usuario, texto):
    with open(QUEJAS_SUGERENCIAS_FILE, "a") as file:
        file.write(f"{usuario}: {texto}\n")

def agregar_queja_sugerencia_anonima(texto):
    with open(QUEJAS_SUGERENCIAS_FILE, "a") as file:
        file.write(f"Anónimo: {texto}\n")

def main():
    print("Bienvenido al sistema de quejas y sugerencias del comedor universitario")
    
    while True:
        print("1. Registrarse")
        print("2. Iniciar sesión")
        opcion = input("Seleccione una opción (1 o 2): ")

        if opcion == "1":
            usuario = input("Ingrese un nombre de usuario: ")
            contraseña = input("Ingrese una contraseña: ")
            registrar_usuario(usuario, contraseña)
            print("Registro exitoso. Ahora puede iniciar sesión.")
        elif opcion == "2":
            usuario = input("Ingrese su nombre de usuario: ")
            contraseña = input("Ingrese su contraseña: ")
            if verificar_usuario(usuario, contraseña):
                print("Inicio de sesión exitoso.")
                while True:
                    print("1. Hacer una queja o sugerencia")
                    print("2. Hacer una queja o sugerencia anónima")
                    opcion_queja = input("Seleccione una opción (1 o 2): ")
                    if opcion_queja == "1":
                        queja_sugerencia = input("Ingrese su queja o sugerencia: ")
                        agregar_queja_sugerencia(usuario, queja_sugerencia)
                        print("Queja o sugerencia registrada exitosamente.")
                        break
                    elif opcion_queja == "2":
                        queja_sugerencia = input("Ingrese su queja o sugerencia anónima: ")
                        agregar_queja_sugerencia_anonima(queja_sugerencia)
                        print("Queja o sugerencia anónima registrada exitosamente.")
                        break
                    else:
                        print("Opción no válida. Intente nuevamente.")
            else:
                print("Usuario o contraseña incorrectos. Intente nuevamente.")
        else:
            print("Opción no válida. Intente nuevamente.")

if __name__ == "__main__":
    main()

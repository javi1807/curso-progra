import tkinter as tk
from tkinter import messagebox
from tkinter import PhotoImage
import sqlite3

def menu_pantalla():
    global pantalla
    pantalla = tk.Tk()
    pantalla.geometry("300x380")
    pantalla.title("Bienvenido")

    tk.Label(text="Acceso al Sistema", bg="slateblue1", fg="white", width="250", height="3", font=("Comic Sans", 15)).pack()
    tk.Label(text="").pack()

    tk.Button(text="Iniciar sesion", bg="deep sky blue", height="3", width="30", command=inicio_sesion).pack()
    tk.Label(text="").pack()
    tk.Button(text="Registrarse", bg="light grey", height="3", width="30", command=registrarse).pack()

    pantalla.mainloop()

def inicio_sesion():
    global pantalla1
    pantalla1 = tk.Toplevel(pantalla)
    pantalla1.geometry("350x250")
    pantalla1.title("Inicio de sesion")

    tk.Label(pantalla1, text="Ingrese su Usuario / Codigo y Contraseña", width="250", bg="slateblue1", fg="white").pack()
    tk.Label(pantalla1, text="")

    global codigo_verify
    global contrasena_verify

    codigo_verify = tk.StringVar()
    contrasena_verify = tk.StringVar()

    global codigo_entry
    global contrasena_entry

    tk.Label(pantalla1, text="Codigo").pack()
    codigo_entry = tk.Entry(pantalla1, textvariable=codigo_verify)
    codigo_entry.pack()
    tk.Label(pantalla1).pack()

    tk.Label(pantalla1, text="Contraseña").pack()
    contrasena_entry = tk.Entry(pantalla1, show="*", textvariable=contrasena_verify)
    contrasena_entry.pack()
    tk.Label(pantalla1).pack()

    tk.Button(pantalla1, text="Iniciar sesion", bg="deep sky blue", command=validar_inicio_sesion_sqlite).pack()

def registrarse():
    global pantalla2
    pantalla2 = tk.Toplevel(pantalla)
    pantalla2.geometry("300x350")
    pantalla2.title("Registrarse")

    tk.Label(pantalla2, text="Por favor complete la siguiente información", width="250", bg="slateblue1", fg="white").pack()
    tk.Label(pantalla2, text="")

    global nombreusuario_entry
    global codigousuario_entry
    global contrasena_entry
    global correousuario_entry
    global contrasenarepe_entry

    correousuario_entry = tk.StringVar()
    nombreusuario_entry = tk.StringVar()
    codigousuario_entry = tk.StringVar()
    contrasena_entry = tk.StringVar()
    contrasenarepe_entry = tk.StringVar()

    tk.Label(pantalla2, text="Correo").pack()
    tk.Entry(pantalla2, textvariable=correousuario_entry).pack()
    tk.Label(pantalla2).pack()

    tk.Label(pantalla2, text="Nombre de usuario").pack()
    tk.Entry(pantalla2, textvariable=nombreusuario_entry).pack()
    tk.Label(pantalla2).pack()

    tk.Label(pantalla2, text="Codigo").pack()
    tk.Entry(pantalla2, textvariable=codigousuario_entry).pack()
    tk.Label(pantalla2).pack()

    tk.Label(pantalla2, text="Contraseña").pack()
    tk.Entry(pantalla2, textvariable=contrasena_entry, show="*").pack()
    tk.Label(pantalla2).pack()

    tk.Label(pantalla2, text="Repita contraseña").pack()
    tk.Entry(pantalla2, textvariable=contrasenarepe_entry, show="*").pack()
    tk.Label(pantalla2).pack()

    tk.Button(pantalla2, text="Registrarse", bg="deep sky blue", command=insertar_datos_sqlite).pack()

def insertar_datos_sqlite():
    conexion = sqlite3.connect('usuarios.db')
    cursor = conexion.cursor()
    cursor.execute("SELECT usuario FROM usuarios WHERE usuario = ?", (nombreusuario_entry.get(),))
    if cursor.fetchone():
        messagebox.showinfo(message="El usuario ya está registrado en el sistema.", title="Aviso")
    else:
        if contrasena_entry.get() == contrasenarepe_entry.get():
            cursor.execute("INSERT INTO usuarios (usuario, codigo, correo, contraseña) VALUES (?, ?, ?, ?)", 
                           (nombreusuario_entry.get(), codigousuario_entry.get(), correousuario_entry.get(), contrasena_entry.get()))
            conexion.commit()
            messagebox.showinfo(message="Registro exitoso!", title="Aviso")
        else:
            messagebox.showinfo(message="Las contraseñas no coinciden", title="Aviso")
    conexion.close()

def validar_inicio_sesion_sqlite():
    conexion = sqlite3.connect('usuarios.db')
    cursor = conexion.cursor()
    cursor.execute("SELECT contraseña FROM usuarios WHERE codigo = ? AND contraseña = ?", (codigo_verify.get(), contrasena_verify.get()))
    if cursor.fetchone():
        messagebox.showinfo(title="Inicio de sesion correcto", message="Usuario y Contraseña correctos")
    else:
        messagebox.showinfo(title="Inicio de sesion incorrecto", message="Código o Contraseña incorrectos")
    conexion.close()

menu_pantalla()
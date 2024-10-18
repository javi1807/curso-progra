from tkinter import ttk
from tkinter import *
import sqlite3

# Función para verificar usuario
def verificar_usuario(codigo, contraseña):
    # Aquí iría la lógica para verificar el usuario en la base de datos
    # Para el ejemplo, retornamos True si el código y la contraseña son iguales
    return codigo == contraseña

# Función para agregar reclamo
def agregar_reclamo(codigo, texto_reclamo):
    # Aquí iría la lógica para agregar un reclamo a la base de datos
    print(f'Reclamo agregado: {codigo}, {texto_reclamo}')

# Función para agregar sugerencia
def agregar_sugerencia(codigo, texto_sugerencia):
    # Aquí iría la lógica para agregar una sugerencia a la base de datos
    print(f'Sugerencia agregada: {codigo}, {texto_sugerencia}')

# Clase para el menú principal
class MenuPrincipal:
    def __init__(self, window, codigo):
        self.wind = window
        self.wind.title('Menú Principal')
        self.codigo = codigo
        
        frame = LabelFrame(self.wind, text='Menú Principal')
        frame.grid(row=0, column=0, columnspan=3, pady=20)

        ttk.Button(frame, text='Hacer un Reclamo', command=self.abrir_reclamos).grid(row=1, column=0, sticky=W + E)
        ttk.Button(frame, text='Hacer una Sugerencia', command=self.abrir_sugerencias).grid(row=2, column=0, sticky=W + E)

    def abrir_reclamos(self):
        self.new_window = Toplevel(self.wind)
        self.app = Reclamos(self.new_window, self.codigo)

    def abrir_sugerencias(self):
        self.new_window = Toplevel(self.wind)
        self.app = Sugerecias(self.new_window, self.codigo)

# Clase para la ventana de reclamos
class Reclamos:
    db_name = 'databaseRECLAMOS.db'

    def __init__(self, window, codigo):
        self.wind = window
        self.wind.title('RECLAMOS')
        self.codigo = codigo
        
        frame = LabelFrame(self.wind, text='Hacer un Reclamo')
        frame.grid(row=0, column=0, columnspan=3, pady=20)

        Label(frame, text='Reclamo: ').grid(row=1, column=0)
        self.reclamo = Entry(frame)
        self.reclamo.grid(row=1, column=1)

        ttk.Button(frame, text='Guardar Reclamo', command=self.add_reclamo).grid(row=2, columnspan=2, sticky=W+E)

    def add_reclamo(self):
        agregar_reclamo(self.codigo, self.reclamo.get())
        self.reclamo.delete(0, END)
        print("Reclamo registrado exitosamente.")

# Clase para la ventana de sugerencias
class Sugerecias:
    db_name = 'databaseSUGERENCIAS.db'

    def __init__(self, window, codigo):
        self.wind = window
        self.wind.title('SUGERENCIAS')
        self.codigo = codigo

        frame = LabelFrame(self.wind, text='Hacer una Sugerencia')
        frame.grid(row=0, column=0, columnspan=3, pady=20)

        Label(frame, text='Sugerencia: ').grid(row=1, column=0)
        self.sugerencia = Entry(frame)
        self.sugerencia.grid(row=1, column=1)

        ttk.Button(frame, text='Guardar Sugerencia', command=self.add_sugerencia).grid(row=2, columnspan=2, sticky=W+E)

    def add_sugerencia(self):
        agregar_sugerencia(self.codigo, self.sugerencia.get())
        self.sugerencia.delete(0, END)
        print("Sugerencia registrada exitosamente.")

# Clase para la ventana de inicio de sesión
class Login:
    def __init__(self, window):
        self.wind = window
        self.wind.title('Inicio de Sesión')

        frame = LabelFrame(self.wind, text='Inicio de Sesión')
        frame.grid(row=0, column=0, columnspan=3, pady=20)

        Label(frame, text='Código: ').grid(row=1, column=0)
        self.codigo = Entry(frame)
        self.codigo.grid(row=1, column=1)

        Label(frame, text='Contraseña: ').grid(row=2, column=0)
        self.contrasena = Entry(frame, show='*')
        self.contrasena.grid(row=2, column=1)

        ttk.Button(frame, text='Iniciar Sesión', command=self.verificar).grid(row=3, columnspan=2, sticky=W+E)

    def verificar(self):
        if verificar_usuario(self.codigo.get(), self.contrasena.get()):
            self.wind.destroy()
            self.new_window = Tk()
            self.app = MenuPrincipal(self.new_window, self.codigo.get())
            self.new_window.mainloop()
        else:
            messagebox.showerror('Error', 'Codigo o contraseña incorrectos.')

if __name__ == '__main__':
    root = Tk()
    app = Login(root)
    root.mainloop()

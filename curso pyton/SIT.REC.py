import tkinter as tk
from tkinter import messagebox, PhotoImage, ttk
import sqlite3
from datetime import datetime

def menu_pantalla():
    global pantalla
    pantalla = tk.Tk()
    pantalla.geometry("300x380")
    pantalla.title("Bienvenido!")

    tk.Label(text="Acceso al Sistema", bg="slateblue1", fg="white", width="250", height="3", font=("Comic Sans", 15)).pack()
    tk.Label(text="").pack()


    tk.Button(text="Iniciar Sesión", bg="deep sky blue", height="3", width="30", command=inicio_sesion).pack()
    tk.Label(text="").pack()
    tk.Button(text="Registrarse", bg="light grey", height="3", width="30", command=registrarse).pack()

    pantalla.mainloop()

def inicio_sesion():
    global pantalla1
    pantalla1 = tk.Toplevel(pantalla)
    pantalla1.geometry("350x250")
    pantalla1.title("Inicio de Sesión")

    tk.Label(pantalla1, text="Ingrese su Usuario o Código y Contraseña", width="250", bg="slateblue1", fg="white").pack()
    tk.Label(pantalla1, text="").pack()

    global codigo_verify
    global contrasena_verify

    codigo_verify = tk.StringVar()
    contrasena_verify = tk.StringVar()

    global codigo_entry
    global contrasena_entry

    tk.Label(pantalla1, text="Código").pack()
    codigo_entry = tk.Entry(pantalla1, textvariable=codigo_verify)
    codigo_entry.pack()
    tk.Label(pantalla1).pack()

    tk.Label(pantalla1, text="Contraseña").pack()
    contrasena_entry = tk.Entry(pantalla1, show="*", textvariable=contrasena_verify)
    contrasena_entry.pack()
    tk.Label(pantalla1).pack()

    tk.Button(pantalla1, text="Iniciar Sesión", bg="deep sky blue", command=validar_inicio_sesion_sqlite).pack()

def registrarse():
    global pantalla2
    pantalla2 = tk.Toplevel(pantalla)
    pantalla2.geometry("300x400")
    pantalla2.title("Registrarse")

    tk.Label(pantalla2, text="Por favor complete la siguiente información", width="250", bg="slateblue1", fg="white").pack()
    tk.Label(pantalla2, text="").pack()

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

    tk.Label(pantalla2, text="Código").pack()
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
        messagebox.showinfo(title="Inicio de sesión correcto", message="Usuario y Contraseña correctos")
        abrir_menu_principal()
    else:
        messagebox.showinfo(title="Inicio de sesión incorrecto", message="Código o Contraseña incorrectos")
    conexion.close()

def abrir_menu_principal():
    global pantalla3
    pantalla3 = tk.Toplevel(pantalla)
    pantalla3.geometry("300x400")
    pantalla3.title("Menú Principal")

    tk.Label(pantalla3, text="Menú Principal", bg="slateblue1", fg="white", width="250", height="3", font=("Comic Sans", 15)).pack()
    tk.Label(pantalla3, text="").pack()

    tk.Button(pantalla3, text="Hacer Sugerencia", bg="deep sky blue", height="3", width="30", command=abrir_sugerencias).pack()
    tk.Label(pantalla3, text="").pack()
    tk.Button(pantalla3, text="Hacer Reclamo", bg="deep sky blue", height="3", width="30", command=abrir_reclamos).pack()
    tk.Label(pantalla3, text="").pack()
    tk.Button(pantalla3, text="Ver Sugerencias", bg="light grey", height="3", width="30", command=ver_sugerencias).pack()
    tk.Label(pantalla3, text="").pack()
    tk.Button(pantalla3, text="Ver Reclamos", bg="light grey", height="3", width="30", command=ver_reclamos).pack()

def abrir_sugerencias():
    Sugerencias(tk.Toplevel(pantalla3))

def abrir_reclamos():
    Reclamos(tk.Toplevel(pantalla3))

def ver_sugerencias():
    Sugerencias(tk.Toplevel(pantalla3), ver=True)

def ver_reclamos():
    Reclamos(tk.Toplevel(pantalla3), ver=True)

class Sugerencias:
    db_name = 'databaseSUGERENCIAS.db'

    def __init__(self, window, ver=False):
        self.wind = window
        self.wind.title('SUGERENCIAS')
        self.ver = ver

        frame = ttk.LabelFrame(self.wind, text='Hacer una Sugerencia' if not self.ver else 'Ver Sugerencias')
        frame.grid(row=0, column=0, columnspan=3, pady=20)

        ttk.Label(frame, text='Autor: ' if not self.ver else '').grid(row=1, column=0)
        self.author = ttk.Entry(frame) if not self.ver else None
        if self.author:
            self.author.grid(row=1, column=1)
            self.author.focus()

        ttk.Label(frame, text='Sugerencia: ' if not self.ver else '').grid(row=2, column=0)
        self.suggestion = ttk.Entry(frame) if not self.ver else None
        if self.suggestion:
            self.suggestion.grid(row=2, column=1)

        ttk.Label(frame, text='Fecha: ' if not self.ver else '').grid(row=3, column=0)
        self.date = ttk.Entry(frame) if not self.ver else None
        if self.date:
            self.date.insert(0, datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
            self.date.grid(row=3, column=1)

        if not self.ver:
            ttk.Button(frame, text='Guardar Sugerencia', command=self.add_suggestion).grid(row=4, columnspan=2, sticky=tk.W + tk.E)
        
        self.message = ttk.Label(text='', foreground='red')
        self.message.grid(row=3, column=0, columnspan=2, sticky=tk.W + tk.E)

        self.tree = ttk.Treeview(height=10, columns=('sugerencia', 'fecha'))
        self.tree.grid(row=4, column=0, columnspan=2)
        self.tree.heading('#0', text='Autor', anchor=tk.CENTER)
        self.tree.heading('#1', text='Sugerencia', anchor=tk.CENTER)
        self.tree.heading('#2', text='Fecha', anchor=tk.CENTER)

        if self.ver:
            ttk.Button(text='EDITAR', command=self.edit_suggestion).grid(row=5, column=1, sticky=tk.W + tk.E)

        self.get_suggestions()

    def run_query(self, query, parameters=()):
        with sqlite3.connect(self.db_name) as conn:
            cursor = conn.cursor()
            result = cursor.execute(query, parameters)
            conn.commit()
        return result

    def get_suggestions(self):
        records = self.tree.get_children()
        for element in records:
            self.tree.delete(element)
        query = 'SELECT * FROM Sugerencias ORDER BY fecha DESC'
        db_rows = self.run_query(query)
        for row in db_rows:
            self.tree.insert('', 0, text=row[1], values=(row[2], row[3]))

    def validation(self):
        return len(self.author.get()) != 0 and len(self.suggestion.get()) != 0

    def add_suggestion(self):
        if self.validation():
            query = 'INSERT INTO Sugerencias VALUES(NULL, ?, ?, ?)'
            parameters = (self.author.get(), self.suggestion.get(), self.date.get())
            self.run_query(query, parameters)
            self.message['text'] = f'Sugerencia {self.author.get()} añadida exitosamente'
            self.author.delete(0, tk.END)
            self.suggestion.delete(0, tk.END)
            self.date.delete(0, tk.END)
            self.date.insert(0, datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
        else:
            self.message['text'] = 'Autor y Sugerencia son requeridos'
        self.get_suggestions()

    def edit_suggestion(self):
        self.message['text'] = ''
        try:
            self.tree.item(self.tree.selection())['values'][0]
        except IndexError as e:
            self.message['text'] = 'Por favor, seleccione un registro'
            return
        autor = self.tree.item(self.tree.selection())['text']
        old_suggestion = self.tree.item(self.tree.selection())['values'][0]
        old_date = self.tree.item(self.tree.selection())['values'][1]

        self.edit_wind = tk.Toplevel()
        self.edit_wind.title('Editar Sugerencia')

        ttk.Label(self.edit_wind, text='Autor:').grid(row=0, column=1)
        ttk.Entry(self.edit_wind, textvariable=tk.StringVar(self.edit_wind, value=autor), state='readonly').grid(row=0, column=2)

        ttk.Label(self.edit_wind, text='Sugerencia Antigua:').grid(row=1, column=1)
        ttk.Entry(self.edit_wind, textvariable=tk.StringVar(self.edit_wind, value=old_suggestion), state='readonly').grid(row=1, column=2)

        ttk.Label(self.edit_wind, text='Sugerencia Nueva:').grid(row=2, column=1)
        new_suggestion = ttk.Entry(self.edit_wind)
        new_suggestion.grid(row=2, column=2)

        ttk.Label(self.edit_wind, text='Fecha Antigua:').grid(row=3, column=1)
        ttk.Entry(self.edit_wind, textvariable=tk.StringVar(self.edit_wind, value=old_date), state='readonly').grid(row=3, column=2)

        ttk.Label(self.edit_wind, text='Fecha Nueva:').grid(row=4, column=1)
        new_date = ttk.Entry(self.edit_wind)
        new_date.grid(row=4, column=2)
        new_date.insert(0, datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

        ttk.Button(self.edit_wind, text='Actualizar', command=lambda: self.edit_records(new_suggestion.get(), new_date.get(), autor, old_suggestion, old_date)).grid(row=5, column=2, sticky=tk.W)
        self.edit_wind.mainloop()

    def edit_records(self, new_suggestion, new_date, autor, old_suggestion, old_date):
        query = 'UPDATE Sugerencias SET sugerencia = ?, fecha = ? WHERE autor = ? AND sugerencia = ? AND fecha = ?'
        parameters = (new_suggestion, new_date, autor, old_suggestion, old_date)
        self.run_query(query, parameters)
        self.edit_wind.destroy()
        self.message['text'] = f'Registro {autor} actualizado exitosamente'
        self.get_suggestions()

class Reclamos:
    db_name = 'databaseRECLAMOS.db'

    def __init__(self, window, ver=False):
        self.wind = window
        self.wind.title('RECLAMOS')
        self.ver = ver

        frame = ttk.LabelFrame(self.wind, text='Hacer un Reclamo' if not self.ver else 'Ver Reclamos')
        frame.grid(row=0, column=0, columnspan=3, pady=20)

        ttk.Label(frame, text='Autor: ' if not self.ver else '').grid(row=1, column=0)
        self.author = ttk.Entry(frame) if not self.ver else None
        if self.author:
            self.author.grid(row=1, column=1)
            self.author.focus()

        ttk.Label(frame, text='Reclamo: ' if not self.ver else '').grid(row=2, column=0)
        self.reclamo = ttk.Entry(frame) if not self.ver else None
        if self.reclamo:
            self.reclamo.grid(row=2, column=1)

        ttk.Label(frame, text='Fecha: ' if not self.ver else '').grid(row=3, column=0)
        self.date = ttk.Entry(frame) if not self.ver else None
        if self.date:
            self.date.insert(0, datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
            self.date.grid(row=3, column=1)

        if not self.ver:
            ttk.Button(frame, text='Guardar Reclamo', command=self.add_reclamo).grid(row=4, columnspan=2, sticky=tk.W + tk.E)
        
        self.message = ttk.Label(text='', foreground='red')
        self.message.grid(row=3, column=0, columnspan=2, sticky=tk.W + tk.E)

        self.tree = ttk.Treeview(height=10, columns=('reclamo', 'fecha'))
        self.tree.grid(row=4, column=0, columnspan=2)
        self.tree.heading('#0', text='Autor', anchor=tk.CENTER)
        self.tree.heading('#1', text='Reclamo', anchor=tk.CENTER)
        self.tree.heading('#2', text='Fecha', anchor=tk.CENTER)

        if self.ver:
            ttk.Button(text='EDITAR', command=self.edit_reclamo).grid(row=5, column=1, sticky=tk.W + tk.E)

        self.get_reclamos()

    def run_query(self, query, parameters=()):
        with sqlite3.connect(self.db_name) as conn:
            cursor = conn.cursor()
            result = cursor.execute(query, parameters)
            conn.commit()
        return result

    def get_reclamos(self):
        records = self.tree.get_children()
        for element in records:
            self.tree.delete(element)
        query = 'SELECT * FROM Reclamos ORDER BY fecha DESC'
        db_rows = self.run_query(query)
        for row in db_rows:
            self.tree.insert('', 0, text=row[1], values=(row[2], row[3]))

    def validation(self):
        return len(self.author.get()) != 0 and len(self.reclamo.get()) != 0

    def add_reclamo(self):
        if self.validation():
            query = 'INSERT INTO Reclamos VALUES(NULL, ?, ?, ?)'
            parameters = (self.author.get(), self.reclamo.get(), self.date.get())
            self.run_query(query, parameters)
            self.message['text'] = f'Reclamo {self.author.get()} añadido exitosamente'
            self.author.delete(0, tk.END)
            self.reclamo.delete(0, tk.END)
            self.date.delete(0, tk.END)
            self.date.insert(0, datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
        else:
            self.message['text'] = 'Autor y Reclamo son requeridos'
        self.get_reclamos()

    def edit_reclamo(self):
        self.message['text'] = ''
        try:
            self.tree.item(self.tree.selection())['values'][0]
        except IndexError as e:
            self.message['text'] = 'Por favor, seleccione un registro'
            return
        autor = self.tree.item(self.tree.selection())['text']
        old_reclamo = self.tree.item(self.tree.selection())['values'][0]
        old_date = self.tree.item(self.tree.selection())['values'][1]

        self.edit_wind = tk.Toplevel()
        self.edit_wind.title('Editar Reclamo')

        ttk.Label(self.edit_wind, text='Autor:').grid(row=0, column=1)
        ttk.Entry(self.edit_wind, textvariable=tk.StringVar(self.edit_wind, value=autor), state='readonly').grid(row=0, column=2)

        ttk.Label(self.edit_wind, text='Reclamo Antiguo:').grid(row=1, column=1)
        ttk.Entry(self.edit_wind, textvariable=tk.StringVar(self.edit_wind, value=old_reclamo), state='readonly').grid(row=1, column=2)

        ttk.Label(self.edit_wind, text='Reclamo Nuevo:').grid(row=2, column=1)
        new_reclamo = ttk.Entry(self.edit_wind)
        new_reclamo.grid(row=2, column=2)

        ttk.Label(self.edit_wind, text='Fecha Antigua:').grid(row=3, column=1)
        ttk.Entry(self.edit_wind, textvariable=tk.StringVar(self.edit_wind, value=old_date), state='readonly').grid(row=3, column=2)

        ttk.Label(self.edit_wind, text='Fecha Nueva:').grid(row=4, column=1)
        new_date = ttk.Entry(self.edit_wind)
        new_date.grid(row=4, column=2)
        new_date.insert(0, datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

        ttk.Button(self.edit_wind, text='Actualizar', command=lambda: self.edit_records(new_reclamo.get(), new_date.get(), autor, old_reclamo, old_date)).grid(row=5, column=2, sticky=tk.W)
        self.edit_wind.mainloop()

    def edit_records(self, new_reclamo, new_date, autor, old_reclamo, old_date):
        query = 'UPDATE Reclamos SET reclamo = ?, fecha = ? WHERE autor = ? AND reclamo = ? AND fecha = ?'
        parameters = (new_reclamo, new_date, autor, old_reclamo, old_date)
        self.run_query(query, parameters)
        self.edit_wind.destroy()
        self.message['text'] = f'Registro {autor} actualizado exitosamente'
        self.get_reclamos()

if __name__ == '__main__':
    menu_pantalla()
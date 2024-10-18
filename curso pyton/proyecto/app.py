import tkinter as tk
from tkinter import messagebox, PhotoImage, ttk
from datetime import datetime
import sqlite3
from database import create_user_db, create_suggestion_db, create_reclamo_db

class Application(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Sistema de Reclamos y Sugerencias")
        self.geometry("300x380")
        self._setup_main_screen()
    
    def _setup_main_screen(self):
        tk.Label(text="Acceso al Sistema", bg="slateblue1", fg="white", width="250", height="3", font=("Comic Sans", 15)).pack()
        tk.Label(text="").pack()
        
        image = PhotoImage(file="usuario2/usuario2.gif")
        image = image.subsample(1, 1)
        label = tk.Label(image=image)
        label.image = image
        label.pack()
        
        tk.Button(text="Iniciar Sesión", bg="deep sky blue", height="3", width="30", command=self._login_screen).pack()
        tk.Label(text="").pack()
        tk.Button(text="Registrarse", bg="light grey", height="3", width="30", command=self._register_screen).pack()

    def _login_screen(self):
        pantalla1 = tk.Toplevel(self)
        pantalla1.geometry("350x250")
        pantalla1.title("Inicio de Sesión")
        
        tk.Label(pantalla1, text="Ingrese su Usuario o Código y Contraseña", width="250", bg="slateblue1", fg="white").pack()
        tk.Label(pantalla1, text="").pack()
        
        codigo_verify = tk.StringVar()
        contrasena_verify = tk.StringVar()
        
        tk.Label(pantalla1, text="Código").pack()
        codigo_entry = tk.Entry(pantalla1, textvariable=codigo_verify)
        codigo_entry.pack()
        tk.Label(pantalla1).pack()
        
        tk.Label(pantalla1, text="Contraseña").pack()
        contrasena_entry = tk.Entry(pantalla1, show="*", textvariable=contrasena_verify)
        contrasena_entry.pack()
        tk.Label(pantalla1).pack()
        
        tk.Button(pantalla1, text="Iniciar Sesión", bg="deep sky blue", command=lambda: self._validate_login(codigo_verify, contrasena_verify)).pack()

    def _register_screen(self):
        pantalla2 = tk.Toplevel(self)
        pantalla2.geometry("300x400")
        pantalla2.title("Registrarse")
        
        tk.Label(pantalla2, text="Por favor complete la siguiente información", width="250", bg="slateblue1", fg="white").pack()
        tk.Label(pantalla2, text="").pack()
        
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
        
        tk.Button(pantalla2, text="Registrarse", bg="deep sky blue", command=lambda: self._register_user(nombreusuario_entry, codigousuario_entry, correousuario_entry, contrasena_entry, contrasenarepe_entry)).pack()

    def _register_user(self, nombreusuario, codigousuario, correo, contrasena, contrasenarepe):
        conexion = sqlite3.connect(r'D:\Programas\DB.Browser.for.SQLite-3.12.2-win64\DB Browser for SQLite\usuarios\usuarios.db')
        cursor = conexion.cursor()
        cursor.execute("SELECT usuario FROM usuarios WHERE usuario = ?", (nombreusuario.get(),))
        if cursor.fetchone():
            messagebox.showinfo(message="El usuario ya está registrado en el sistema.", title="Aviso")
        else:
            if contrasena.get() == contrasenarepe.get():
                cursor.execute("INSERT INTO usuarios (usuario, codigo, correo, contraseña) VALUES (?, ?, ?, ?)", 
                               (nombreusuario.get(), codigousuario.get(), correo.get(), contrasena.get()))
                conexion.commit()
                messagebox.showinfo(message="Registro exitoso!", title="Aviso")
            else:
                messagebox.showinfo(message="Las contraseñas no coinciden", title="Aviso")
        conexion.close()

    def _validate_login(self, codigo, contrasena):
        conexion = sqlite3.connect(r'D:\Programas\DB.Browser.for.SQLite-3.12.2-win64\DB Browser for SQLite\usuarios\usuarios.db')
        cursor = conexion.cursor()
        cursor.execute("SELECT contraseña FROM usuarios WHERE codigo = ? AND contraseña = ?", (codigo.get(), contrasena.get()))
        if cursor.fetchone():
            messagebox.showinfo(title="Inicio de sesión correcto", message="Usuario y Contraseña correctos")
            self._main_menu_screen()
        else:
            messagebox.showinfo(title="Inicio de sesión incorrecto", message="Código o Contraseña incorrectos")
        conexion.close()

    def _main_menu_screen(self):
        pantalla3 = tk.Toplevel(self)
        pantalla3.geometry("300x400")
        pantalla3.title("Menú Principal")
        
        tk.Label(pantalla3, text="Menú Principal", bg="slateblue1", fg="white", width="250", height="3", font=("Comic Sans", 15)).pack()
        tk.Label(pantalla3, text="").pack()
        
        tk.Button(pantalla3, text="Hacer Sugerencia", bg="deep sky blue", height="3", width="30", command=lambda: self._suggestion_screen(pantalla3)).pack()
        tk.Label(pantalla3, text="").pack()
        tk.Button(pantalla3, text="Hacer Reclamo", bg="deep sky blue", height="3", width="30", command=lambda: self._reclamo_screen(pantalla3)).pack()
        tk.Label(pantalla3, text="").pack()
        tk.Button(pantalla3, text="Ver Sugerencias", bg="light grey", height="3", width="30", command=lambda: self._suggestion_screen(pantalla3, ver=True)).pack()
        tk.Label(pantalla3, text="").pack()
        tk.Button(pantalla3, text="Ver Reclamos", bg="light grey", height="3", width="30", command=lambda: self._reclamo_screen(pantalla3, ver=True)).pack()

    def _suggestion_screen(self, parent, ver=False):
        Sugerencias(parent, ver)

    def _reclamo_screen(self, parent, ver=False):
        Reclamos(parent, ver)

class Sugerencias:
    db_name = r'D:\Programas\DB.Browser.for.SQLite-3.12.2-win64\DB Browser for SQLite\base_datos.db'

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
            self.date.insert(0, datetime.now().strftime("%Y-%m-%d %H:%:M:%S"))
        else:
            self.message['text'] = 'Autor y Sugerencia son requeridos'
        self.get_suggestions()

class Reclamos:
    db_name = r'D:\Programas\DB.Browser.for.SQLite-3.12.2-win64\DB Browser for SQLite\base_datos.db'

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

if __name__ == '__main__':
    app = Application()
    app.mainloop()
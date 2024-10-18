from tkinter import ttk
from tkinter import *
from datetime import datetime
import sqlite3

class Reclamos:
    # connection dir property
    db_name = 'databaseRECLAMOS.db'

    def __init__(self, window):
        # Initializations 
        self.wind = window
        self.wind.title('RECLAMOS')

        # Creating a Frame Container 
        frame = LabelFrame(self.wind, text='Hacer un Reclamo')
        frame.grid(row=0, column=0, columnspan=3, pady=20)

        # Autor Input
        Label(frame, text='Autor: ').grid(row=1, column=0)
        self.author = Entry(frame)
        self.author.focus()
        self.author.grid(row=1, column=1)

        # Reclamo Input
        Label(frame, text='Reclamo: ').grid(row=2, column=0)
        self.reclamo = Entry(frame)
        self.reclamo.grid(row=2, column=1)

        # Fecha Input
        Label(frame, text='Fecha: ').grid(row=3, column=0)
        self.date = Entry(frame)
        self.date.insert(0, datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
        self.date.grid(row=3, column=1)

        # Button Add Reclamos 
        ttk.Button(frame, text='Guardar Reclamo', command=self.add_reclamo).grid(row=4, columnspan=2, sticky=W+E)

        # Output Messages 
        self.message = Label(text='', fg='red')
        self.message.grid(row=3, column=0, columnspan=2, sticky=W+E)

        # Table
        self.tree = ttk.Treeview(height=10, columns=('reclamo', 'fecha'))
        self.tree.grid(row=4, column=0, columnspan=2)
        self.tree.heading('#0', text='Autor', anchor=CENTER)
        self.tree.heading('#1', text='Reclamo', anchor=CENTER)
        self.tree.heading('#2', text='Fecha', anchor=CENTER)

        # Buttons
        ttk.Button(text='MENÚ PRINCIPAL', command=self.delete_reclamo).grid(row=5, column=0, sticky=W+E)
        ttk.Button(text='EDITAR', command=self.edit_reclamo).grid(row=5, column=1, sticky=W+E)

        # Filling the Rows
        self.get_reclamos()

    # Function to Execute Database Queries
    def run_query(self, query, parameters=()):
        with sqlite3.connect(self.db_name) as conn:
            cursor = conn.cursor()
            result = cursor.execute(query, parameters)
            conn.commit()
        return result

    # Get Reclamos from Database
    def get_reclamos(self):
        # Cleaning Table 
        records = self.tree.get_children()
        for element in records:
            self.tree.delete(element)
        # Getting data
        query = 'SELECT * FROM Reclamos ORDER BY fecha DESC'
        db_rows = self.run_query(query)
        # Filling data
        for row in db_rows:
            self.tree.insert('', 0, text=row[1], values=(row[2], row[3]))

    # User Input Validation
    def validation(self):
        return len(self.author.get()) != 0 and len(self.reclamo.get()) != 0

    def add_reclamo(self):
        if self.validation():
            query = 'INSERT INTO Reclamos VALUES(NULL, ?, ?, ?)'
            parameters = (self.author.get(), self.reclamo.get(), self.date.get())
            self.run_query(query, parameters)
            self.message['text'] = 'Reclamo {} añadido exitosamente'.format(self.author.get())
            self.author.delete(0, END)
            self.reclamo.delete(0, END)
            self.date.delete(0, END)
            self.date.insert(0, datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
        else:
            self.message['text'] = 'Autor y Reclamo son requeridos'
        self.get_reclamos()

    def delete_reclamo(self):
        self.message['text'] = ''
        try:
            self.tree.item(self.tree.selection())['values'][0]
        except IndexError as e:
            self.message['text'] = 'Por favor, seleccione un registro'
            return
        autor = self.tree.item(self.tree.selection())['text']
        query = 'DELETE FROM Reclamos WHERE autor = ?'
        self.run_query(query, (autor,))
        self.message['text'] = 'Registro {} eliminado exitosamente'.format(autor)
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

        self.edit_wind = Toplevel()
        self.edit_wind.title('Editar Reclamo')

        # Old Autor
        Label(self.edit_wind, text='Autor:').grid(row=0, column=1)
        Entry(self.edit_wind, textvariable=StringVar(self.edit_wind, value=autor), state='readonly').grid(row=0, column=2)

        # Old Reclamo
        Label(self.edit_wind, text='Reclamo Antiguo:').grid(row=1, column=1)
        Entry(self.edit_wind, textvariable=StringVar(self.edit_wind, value=old_reclamo), state='readonly').grid(row=1, column=2)

        # New Reclamo
        Label(self.edit_wind, text='Reclamo Nuevo:').grid(row=2, column=1)
        new_reclamo = Entry(self.edit_wind)
        new_reclamo.grid(row=2, column=2)

        # Old Date
        Label(self.edit_wind, text='Fecha Antigua:').grid(row=3, column=1)
        Entry(self.edit_wind, textvariable=StringVar(self.edit_wind, value=old_date), state='readonly').grid(row=3, column=2)

        # New Date
        Label(self.edit_wind, text='Fecha Nueva:').grid(row=4, column=1)
        new_date = Entry(self.edit_wind)
        new_date.grid(row=4, column=2)
        new_date.insert(0, datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

        Button(self.edit_wind, text='Actualizar', command=lambda: self.edit_records(new_reclamo.get(), new_date.get(), autor, old_reclamo, old_date)).grid(row=5, column=2, sticky=W)
        self.edit_wind.mainloop()

    def edit_records(self, new_reclamo, new_date, autor, old_reclamo, old_date):
        query = 'UPDATE Reclamos SET reclamo = ?, fecha = ? WHERE autor = ? AND reclamo = ? AND fecha = ?'
        parameters = (new_reclamo, new_date, autor, old_reclamo, old_date)
        self.run_query(query, parameters)
        self.edit_wind.destroy()
        self.message['text'] = 'Registro {} actualizado exitosamente'.format(autor)
        self.get_reclamos()

if __name__ == '__main__':
    window = Tk()
    application = Reclamos(window)
    window.mainloop()

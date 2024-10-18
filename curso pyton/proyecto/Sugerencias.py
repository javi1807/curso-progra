from tkinter import ttk
from tkinter import *
from datetime import datetime
import sqlite3

class Sugerecias:
    # connection dir property
    db_name = 'databaseSUGERENCIAS.db'

    def __init__(self, window):
        # Initializations 
        self.wind = window
        self.wind.title('SUGERENCIAS')

        # Creating a Frame Container 
        frame = LabelFrame(self.wind, text='Hacer una Sugerencia')
        frame.grid(row=0, column=0, columnspan=3, pady=20)

        # Autor Input
        Label(frame, text='Autor: ').grid(row=1, column=0)
        self.author = Entry(frame)
        self.author.focus()
        self.author.grid(row=1, column=1)

        # Sugerencia Input
        Label(frame, text='Sugerencia: ').grid(row=2, column=0)
        self.suggestion = Entry(frame)
        self.suggestion.grid(row=2, column=1)

        # Fecha Input
        Label(frame, text='Fecha: ').grid(row=3, column=0)
        self.date = Entry(frame)
        self.date.insert(0, datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
        self.date.grid(row=3, column=1)

        # Button Add Sugerecias 
        ttk.Button(frame, text='Guardar Sugerencia', command=self.add_suggestion).grid(row=4, columnspan=2, sticky=W+E)

        # Output Messages 
        self.message = Label(text='', fg='red')
        self.message.grid(row=3, column=0, columnspan=2, sticky=W+E)

        # Table
        self.tree = ttk.Treeview(height=10, columns=('sugerencia', 'fecha'))
        self.tree.grid(row=4, column=0, columnspan=2)
        self.tree.heading('#0', text='Autor', anchor=CENTER)
        self.tree.heading('#1', text='Sugerencia', anchor=CENTER)
        self.tree.heading('#2', text='Fecha', anchor=CENTER)

        # Buttons
        ttk.Button(text='MENÚ PRINCIPAL', command=self.delete_suggestion).grid(row=5, column=0, sticky=W+E)
        ttk.Button(text='EDITAR', command=self.edit_suggestion).grid(row=5, column=1, sticky=W+E)

        # Filling the Rows
        self.get_suggestions()

    # Function to Execute Database Queries
    def run_query(self, query, parameters=()):
        with sqlite3.connect(self.db_name) as conn:
            cursor = conn.cursor()
            result = cursor.execute(query, parameters)
            conn.commit()
        return result

    # Get Suggestions from Database
    def get_suggestions(self):
        # Cleaning Table 
        records = self.tree.get_children()
        for element in records:
            self.tree.delete(element)
        # Getting data
        query = 'SELECT * FROM Sugerecias ORDER BY fecha DESC'
        db_rows = self.run_query(query)
        # Filling data
        for row in db_rows:
            self.tree.insert('', 0, text=row[1], values=(row[2], row[3]))

    # User Input Validation
    def validation(self):
        return len(self.author.get()) != 0 and len(self.suggestion.get()) != 0

    def add_suggestion(self):
        if self.validation():
            query = 'INSERT INTO Sugerecias VALUES(NULL, ?, ?, ?)'
            parameters = (self.author.get(), self.suggestion.get(), self.date.get())
            self.run_query(query, parameters)
            self.message['text'] = 'Sugerencia {} añadida exitosamente'.format(self.author.get())
            self.author.delete(0, END)
            self.suggestion.delete(0, END)
            self.date.delete(0, END)
            self.date.insert(0, datetime.now().strftime("%Y-%m-%d %H:%M:%S"))
        else:
            self.message['text'] = 'Autor y Sugerencia son requeridos'
        self.get_suggestions()

    def delete_suggestion(self):
        self.message['text'] = ''
        try:
            self.tree.item(self.tree.selection())['values'][0]
        except IndexError as e:
            self.message['text'] = 'Por favor, seleccione un registro'
            return
        name = self.tree.item(self.tree.selection())['text']
        query = 'DELETE FROM Sugerecias WHERE autor = ?'
        self.run_query(query, (name,))
        self.message['text'] = 'Registro {} eliminado exitosamente'.format(name)
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

        self.edit_wind = Toplevel()
        self.edit_wind.title('Editar Sugerencia')

        # Old Autor
        Label(self.edit_wind, text='Autor:').grid(row=0, column=1)
        Entry(self.edit_wind, textvariable=StringVar(self.edit_wind, value=autor), state='readonly').grid(row=0, column=2)

        # Old Suggestion
        Label(self.edit_wind, text='Sugerencia Antigua:').grid(row=1, column=1)
        Entry(self.edit_wind, textvariable=StringVar(self.edit_wind, value=old_suggestion), state='readonly').grid(row=1, column=2)

        # New Suggestion
        Label(self.edit_wind, text='Sugerencia Nueva:').grid(row=2, column=1)
        new_suggestion = Entry(self.edit_wind)
        new_suggestion.grid(row=2, column=2)

        # Old Date
        Label(self.edit_wind, text='Fecha Antigua:').grid(row=3, column=1)
        Entry(self.edit_wind, textvariable=StringVar(self.edit_wind, value=old_date), state='readonly').grid(row=3, column=2)

        # New Date
        Label(self.edit_wind, text='Fecha Nueva:').grid(row=4, column=1)
        new_date = Entry(self.edit_wind)
        new_date.grid(row=4, column=2)
        new_date.insert(0, datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

        Button(self.edit_wind, text='Actualizar', command=lambda: self.edit_records(new_suggestion.get(), new_date.get(), autor, old_suggestion, old_date)).grid(row=5, column=2, sticky=W)
        self.edit_wind.mainloop()

    def edit_records(self, new_suggestion, new_date, autor, old_suggestion, old_date):
        query = 'UPDATE Sugerecias SET sugerencia = ?, fecha = ? WHERE autor = ? AND sugerencia = ? AND fecha = ?'
        parameters = (new_suggestion, new_date, autor, old_suggestion, old_date)
        self.run_query(query, parameters)
        self.edit_wind.destroy()
        self.message['text'] = 'Registro {} actualizado exitosamente'.format(autor)
        self.get_suggestions()

if __name__ == '__main__':
    window = Tk()
    application = Sugerecias(window)
    window.mainloop()

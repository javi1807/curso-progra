import tkinter as tk

# Crear la ventana principal
root = tk.Tk()
root.title('Hola')
root.geometry('250x100')
root.counter = 0

# Definir la función que se ejecutará cuando se haga clic en el botón
def clicked():
    root.counter += 1
    L.config(text="Button clicked: " + str(root.counter))

# Crear un botón
b = tk.Button(root, text="Click Me", command=clicked)
b.pack()

# Crear una etiqueta
L = tk.Label(root, text="No clicks yet.")
L.pack()

# Iniciar el bucle principal de la aplicación
root.mainloop

        
import sqlite3

# Conexión a la base de datos SQLite
conn = sqlite3.connect('usuarios.db')
c = conn.cursor()

# Crear tabla de usuarios si no existe
c.execute('''CREATE TABLE IF NOT EXISTS usuarios
             (usuario TEXT, codigo TEXT, correo TEXT, contraseña TEXT)''')
conn.commit()
conn.close()
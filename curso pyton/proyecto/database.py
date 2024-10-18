import sqlite3
import os

def create_user_db():
    db_path = r'C:/Users/ACER/Desktop/curso pyton/proyecto/database.db'
    if not os.path.exists(db_path):
        with sqlite3.connect(db_path) as conn:
            cursor = conn.cursor()
            cursor.execute('''CREATE TABLE IF NOT EXISTS usuarios (
                                id INTEGER PRIMARY KEY AUTOINCREMENT,
                                usuario TEXT NOT NULL,
                                codigo TEXT NOT NULL,
                                correo TEXT NOT NULL,
                                contraseña TEXT NOT NULL)''')
            conn.commit()

def create_suggestion_db():
    db_path = r'C:/Users/ACER/Desktop/curso pyton/proyecto/database.db'
    if not os.path.exists(db_path):
        with sqlite3.connect(db_path) as conn:
            cursor = conn.cursor()
            cursor.execute('''CREATE TABLE IF NOT EXISTS Sugerencias (
                                id INTEGER PRIMARY KEY AUTOINCREMENT,
                                autor TEXT NOT NULL,
                                sugerencia TEXT NOT NULL,
                                fecha TEXT NOT NULL)''')
            conn.commit()

def create_reclamo_db():
    db_path = r'C:/Users/ACER/Desktop/curso pyton/proyecto/database.db'
    if not os.path.exists(db_path):
        with sqlite3.connect(db_path) as conn:
            cursor = conn.cursor()
            cursor.execute('''CREATE TABLE IF NOT EXISTS Reclamos (
                                id INTEGER PRIMARY KEY AUTOINCREMENT,
                                autor TEXT NOT NULL,
                                reclamo TEXT NOT NULL,
                                fecha TEXT NOT NULL)''')
            conn.commit()

# Inicializar las bases de datos
create_user_db()
create_suggestion_db()
create_reclamo_db()
from tkinter import Tk,Label,Button,Entry
ventana=Tk()
ventana.title("Calculdora")
ventana.geometry("400x200")
def fnSuma():
    n1=text1.get()
    n2=text2.get()
    r=float(n1)+float(n2)
    text3.delete(0,"end")
    text3.insert(0,r)
lbl1=Label(ventana,text="Primer numero")
lbl1.place(x=10 , y=10)
text1=Entry(ventana)
text1.place(x=120, y=10)
lbl2=Label(ventana,text="segundo numero")
lbl2.place(x=10 , y=50)
text2=Entry(ventana)
text2.place(x=120, y=50)
boton=Button(ventana,text="Sumar",command=fnSuma)
boton.place(x=250,y= 60)
lbl3=Label(ventana,text="resultado")
lbl3.place(x=10 , y=100)
text3=Entry(ventana)
text3.place(x=120, y=100)
ventana.mainloop()
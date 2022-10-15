import tkinter as tk
from tkinter import ttk
from tkinter import *


class FirstPage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        Label = tk.Label(self,text="FirstPage", font=("Arial Bold", 30))
        Label.place(x=230,y=230)

        Button = tk.Button(self, text="Next", font=("Arial", 15), command = lambda : controller.show_frame(SecondPage))
        Button.place(x=650,y=450)



class SecondPage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)

        Label = tk.Label(self,text="SecondPage", font=("Arial Bold", 30))
        Label.place(x=230,y=230)

        Button = tk.Button(self, text="Next", font=("Arial", 15), command = lambda : controller.show_frame(ThirdPage))
        Button.place(x=650,y=450)
        
        Button = tk.Button(self, text="Back", font=("Arial", 15), command = lambda : controller.show_frame(FirstPage))
        Button.place(x=100,y=450)


class ThirdPage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)

        Label = tk.Label(self,text="ThirdPage", font=("Arial Bold", 30))
        Label.place(x=230,y=230)

        Button = tk.Button(self, text="Home", font=("Arial", 15), command = lambda : controller.show_frame(FirstPage))
        Button.place(x=650,y=450)

        Button = tk.Button(self, text="Back", font=("Arial", 15), command = lambda : controller.show_frame(SecondPage))
        Button.place(x=100,y=450)



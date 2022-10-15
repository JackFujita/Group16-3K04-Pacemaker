from pickle import TRUE
import tkinter as tk
from tkinter import messagebox
import csv

class FirstPage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        
        border = tk.LabelFrame(self, text='Login', bg='ivory', bd = 10, font=("Arial", 20))
        border.pack(fill="both", expand="yes", padx = 150, pady=150)
        
        L1 = tk.Label(border, text="Username", font=("Arial Bold", 15), bg='ivory')
        L1.place(x=50, y=20)
        Username_login = tk.Entry(border, width = 30, bd = 5)
        Username_login.place(x=180, y=20)
        
        L2 = tk.Label(border, text="Password", font=("Arial Bold", 15), bg='ivory')
        L2.place(x=50, y=80)
        Password_login = tk.Entry(border, width = 30, show='*', bd = 5)
        Password_login.place(x=180, y=80)
        
        def verify():
            input_username = Username_login.get()
            input_password = Password_login.get()

            try:
                with open("Secrets.csv", 'r') as file:
                    csv_reader=csv.reader(file)
                    login_true = False
                    for line in csv_reader:
                        if (line[0]==input_username) and (line[1]==input_password):
                            login_true = True
                            break
                    if login_true:
                        print("he valid")
                        controller.show_frame(SecondPage)
                    else:
                        print("invalid")
                        messagebox.showinfo("Error", "Please provide correct username and password")
            except:
                messagebox.showinfo("Error", "Please provide correct username and password")
         
        verify_button = tk.Button(border, text="Submit", font=("Arial", 15), command=verify)
        verify_button.place(x=320, y=115)
        
        def register():
            window = tk.Tk()
            window.resizable(0,0)
            window.configure(bg="deep sky blue")
            window.title("Register")
            l1 = tk.Label(window, text="Username:", font=("Arial",15), bg="deep sky blue")
            l1.place(x=10, y=10)
            Username_register = tk.Entry(window, width=30, bd=5)
            Username_register.place(x = 200, y=10)
            
            l2 = tk.Label(window, text="Password:", font=("Arial",15), bg="deep sky blue")
            l2.place(x=10, y=60)
            Password_register = tk.Entry(window, width=30, show="*", bd=5)
            Password_register.place(x = 200, y=60)
            
            l3 = tk.Label(window, text="Confirm Password:", font=("Arial",15), bg="deep sky blue")
            l3.place(x=10, y=110)
            Password_register_2 = tk.Entry(window, width=30, show="*", bd=5)
            Password_register_2.place(x = 200, y=110)
            
            def check():
                if Username_register.get()!="" or Password_register.get()!="" or Password_register_2.get()!="":
                    if Password_register.get()==Password_register_2.get():
                        with open("Secrets.csv", 'a', newline='') as file:
                            writer = csv.writer(file)
                            writer.writerow([Username_register.get(), Password_register.get()])
                        messagebox.showinfo("Welcome","You are registered successfully")
                    else:
                        messagebox.showinfo("Error","Your password didn't get match")
                else:
                    messagebox.showinfo("Error", "Please fill the complete field")
                    
            b1 = tk.Button(window, text="Sign in", font=("Arial",15), bg="#ffc22a", command=check)
            b1.place(x=170, y=150)
            
            window.geometry("470x220")
            window.mainloop()
            
        B2 = tk.Button(self, text="Register", bg = "dark orange", font=("Arial",15), command=register)
        B2.place(x=650, y=20)
        
class SecondPage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        
        
        Button = tk.Button(self, text="Next", font=("Arial", 15), command=lambda: controller.show_frame(ThirdPage))
        Button.place(x=650, y=450)
        
        Button = tk.Button(self, text="Back", font=("Arial", 15), command=lambda: controller.show_frame(FirstPage))
        Button.place(x=100, y=450)
        
class ThirdPage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        
        self.configure(bg='Tomato')
        
        Label = tk.Label(self, text="Tomato lol", bg = "orange", font=("Arial Bold", 25))
        Label.place(x=40, y=150)
        
        Button = tk.Button(self, text="Back To Login", font=("Arial", 15), command=lambda: controller.show_frame(FirstPage))
        Button.place(x=650, y=450)
        
        Button = tk.Button(self, text="Back", font=("Arial", 15), command=lambda: controller.show_frame(SecondPage))
        Button.place(x=100, y=450)
        
        
class Application(tk.Tk):
    def __init__(self, *args, **kwargs):
        tk.Tk.__init__(self, *args, **kwargs)
        
        #creating a window
        window = tk.Frame(self)
        window.pack()
        
        window.grid_rowconfigure(0, minsize = 500)
        window.grid_columnconfigure(0, minsize = 800)
        
        self.frames = {}
        for F in (FirstPage, SecondPage, ThirdPage):
            frame = F(window, self)
            self.frames[F] = frame
            frame.grid(row = 0, column=0, sticky="nsew")
            
        self.show_frame(FirstPage)
        
    def show_frame(self, page):
        frame = self.frames[page]
        frame.tkraise()
        self.title("Application")
            
app = Application()
app.maxsize(800,500)
app.mainloop()
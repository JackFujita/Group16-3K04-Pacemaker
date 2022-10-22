from atexit import register
from calendar import c
from pickle import TRUE
import tkinter as tk
from tkinter import ttk
from tkinter import StringVar, messagebox
import csv
import sv_ttk

class Welcome(ttk.Frame):
    def __init__(self, parent, controller):
        ttk.Frame.__init__(self, parent)

        welcomeLabel = ttk.Label(self, text = 'Welcome to Pacemaker', font = ("Roboto medium", 20))
        #welcomeLabel.grid(row = 0, column = 2, padx = 10, pady = 5)
        welcomeLabel.pack(pady = 20)

        # Button = tk.Button(self, text="Login", font=("Arial", 15), command=lambda: controller.show_frame(Login))
        # Button.grid(row = 3, column = 2, padx = 10, pady = 10)
                
        # Button = tk.Button(self, text="Register", font=("Arial", 15), command=lambda: controller.register)
        # Button.grid(row = 4, column = 2, padx = 20, pady = 5)

        Button = ttk.Button(self, text = "Login", command=lambda: controller.show_frame(Login), width=30)
        #Button.grid(row = 3, column = 2, padx = 10, pady = 5)
        Button.pack()

class Login(ttk.Frame):
    def __init__(self, parent, controller):
        ttk.Frame.__init__(self, parent)
        
        border = ttk.LabelFrame(self, text='Login')
        border.pack(fill="both", expand="yes", padx = 150, pady=150)
        
        L1 = ttk.Label(border, text="Username", font=("Arial", 15))
        L1.place(x=50, y=20)
        Username_login = ttk.Entry(border, width = 30)
        Username_login.place(x=180, y=20)
        
        L2 = ttk.Label(border, text="Password", font=("Arial", 15))
        L2.place(x=50, y=80)
        Password_login = ttk.Entry(border, width = 30, show='*')
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
                        controller.show_frame(ModeSelect)
                    else:
                        print("invalid")
                        messagebox.showinfo("Error", "Please provide correct username and password")
            except:
                messagebox.showinfo("Error", "Please provide correct username and password")
         
        verify_button = ttk.Button(border, text="Submit", command=verify)
        verify_button.place(x=320, y=130)
        
        def register():
            window = tk.Tk()
            window.geometry('470x220')
            window.resizable(0,0)
            window.title("Register")
            l1 = ttk.Label(window, text="Username:", font=("Arial",15))
            l1.place(x=10, y=10)
            Username_register = ttk.Entry(window, width=30)
            Username_register.place(x = 200, y=10)
            
            l2 = ttk.Label(window, text="Password:", font=("Arial",15))
            l2.place(x=10, y=60)
            Password_register = ttk.Entry(window, width=30, show="*")
            Password_register.place(x = 200, y=60)
            
            l3 = ttk.Label(window, text="Confirm Password:", font=("Arial",15))
            l3.place(x=10, y=110)
            Password_register_2 = tk.Entry(window, width=30, show="*")
            Password_register_2.place(x = 200, y=110)
            
            def check():
                if Username_register.get()!="" or Password_register.get()!="" or Password_register_2.get()!="":
                    if Password_register.get()==Password_register_2.get():
                        with open("Secrets.csv", 'a', newline='') as file:
                            writer = csv.writer(file)
                            writer.writerow([Username_register.get(), Password_register.get()])
                        messagebox.showinfo("Welcome","You are registered successfully")
                        ###IMPLEMENT MAX USER FUNCTIONALITY
                    else:
                        messagebox.showinfo("Error","Your password didn't get match")
                else:
                    messagebox.showinfo("Error", "Please fill the complete field")
                    
            b1 = ttk.Button(window, text="Register", command=check)
            b1.place(x=220, y=150)

            sv_ttk.set_theme("light")
            window.mainloop()
            
        B2 = ttk.Button(self, text="Register", command=register)
        B2.place(x=650, y=10)

        B3 = ttk.Button(self, text = "Back to welcome", command=lambda: controller.show_frame(Welcome))
        #B3.grid(row = 4, column = 2, padx = 20, pady = 5) #WHY DOESNT THIS WORK?
        B3.place(x=10,y=10)
        
class ModeSelect(ttk.Frame):
    def __init__(self, parent, controller):
        ttk.Frame.__init__(self, parent)

        #img = ttk.Label(self, image="./disconect.png", compound="image")
        
        border = ttk.LabelFrame(self, text='Mode Select')
        border.pack(fill="both", expand="yes", padx = 150, pady=150)

        Button = ttk.Button(self, text="Back To Login", command=lambda: controller.show_frame(Login))
        Button.place(x=150, y=450)
        
        Button = ttk.Button(self, text="Next", command=lambda: controller.show_frame(ParamSelect))
        Button.place(x=600, y=450)

        ##CHECK TO SEE IF THEY HAVE FILLED OUT THE FORM BEFORE GOING TO NEXT

        def save_mode():
            print(selected.get())

        modes = ["AOO", 'VOO', 'AAI', 'VII']
        selected = StringVar()

        for mode in modes:
            r = ttk.Radiobutton(border, text=mode, value=mode,variable = selected)
            r.pack(fill='x', padx = 5, pady = 5)

        button = ttk.Button(border, text = "Apply", command = save_mode)
        button.pack(fill='x', padx=5,pady=5)

        #Button = tk.Button(self, text="Submit", font=("Arial", 15), command=lambda: controller.submit(data) )
        
        
class ParamSelect(ttk.Frame):
    def __init__(self, parent, controller):
        ttk.Frame.__init__(self, parent)
        # Implement checks to see if the parameter values are valid
        # will they mess up the pacemaker? (check that here)

        posY = 25
        posX = 250

        border = ttk.LabelFrame(self, text='Parameters')
        border.pack(fill="both", expand="yes", padx = 100, pady=75)

        Label = ttk.Label(self, text="Programmable Parameters", font=("Arial Bold", 20))
        Label.place(x=40, y=40)

        BackToLogin = ttk.Button(self, text="Back To Login", command=lambda: controller.show_frame(Login))
        BackToLogin.place(x=650, y=450)

        Back = ttk.Button(self, text="Back", command=lambda: controller.show_frame(ModeSelect))
        Back.place(x=100, y=450)

        L1 = ttk.Label(border, text="Lower Rate Limit", font=("Arial Bold", 10))
        L1.place(x=50, y=posY)

        param1 = ttk.Entry(border, width = 30)
        param1.place(x=posX, y=posY-5)

        L1 = ttk.Label(border, text="Upper Rate Limit", font=("Arial Bold", 10))
        L1.place(x=50, y=posY+40)

        param2 = ttk.Entry(border, width = 30)
        param2.place(x=posX, y=posY+35)

        L1 = ttk.Label(border, text="Atrial Amplitude", font=("Arial Bold", 10))
        L1.place(x=50, y=posY+80)

        param3 = ttk.Entry(border, width = 30)
        param3.place(x=posX, y=posY+75)

        L1 = ttk.Label(border, text="Atrial Pulse Width", font=("Arial Bold", 10))
        L1.place(x=50, y=posY+120)

        param4 = ttk.Entry(border, width = 30)
        param4.place(x=posX, y=posY+115)

        L1 = ttk.Label(border, text="Ventricular Amplitude", font=("Arial Bold", 10))
        L1.place(x=50, y=posY+160)

        param5 = ttk.Entry(border, width = 30)
        param5.place(x=posX, y=posY+155)

        L1 = ttk.Label(border, text="Ventricular Pulse Width", font=("Arial Bold", 10))
        L1.place(x=50, y=posY+200)

        param6 = ttk.Entry(border, width = 30)
        param6.place(x=posX, y=posY+195)

        L1 = ttk.Label(border, text="VRP", font=("Arial Bold", 10))
        L1.place(x=50, y=posY+240)

        param7 = ttk.Entry(border, width = 30)
        param7.place(x=posX, y=posY+235)

        L1 = ttk.Label(border, text="ARP", font=("Arial Bold", 10))
        L1.place(x=50, y=posY+280)

        param8 = ttk.Entry(border, width = 30)
        param8.place(x=posX, y=posY+275)

        def applyChanges():
            intLRL = int(param1.get())
            intURL = int(param2.get())
            intAAMP = int(param3.get())
            #intAPW = int(param4.get())
            #intVAMP = int(param5.get())
            #intVPW = int(param6.get())
            #intVRP = int(param7.get())
            #intARP = int(param8.get())

            if ((intLRL >= 30 and intLRL <= 50 and intLRL % 5 == 0) or (intLRL >= 50 and intLRL <= 90 and intLRL % 1 == 0) or (intLRL >= 90 and intLRL <= 175 and intLRL % 5 == 0)):
                lowerRateLimit = param1.get()
            else:
                param1.delete(0, 100)
                
            if (intURL >= 50 and intURL <= 175 and intURL % 5 == 0):
                upperRateLimit = param2.get()
            else:
                param2.delete(0, 100)


            atrialAmp = param3.get()
            atrialPW = param4.get()
            ventAmp = param5.get()
            ventPW = param6.get()
            vrp = param7.get()
            arp = param8.get()

        Apply = ttk.Button(self, text="Apply Changes", command=applyChanges)
        Apply.place(x=400, y=450)


class Application(tk.Tk):
    def __init__(self, *args, **kwargs):
        tk.Tk.__init__(self, *args, **kwargs)
        
        #creating a window
        window = tk.Frame(self)
        window.pack()
        
        window.grid_rowconfigure(0, minsize = 500)
        window.grid_columnconfigure(0, minsize = 800)
        
        self.frames = {}
        for F in (Welcome, Login, ModeSelect, ParamSelect):
            frame = F(window, self)
            self.frames[F] = frame
            frame.grid(row = 0, column=0, sticky="nsew")
            
        self.show_frame(Welcome)
        
    def show_frame(self, page):
        frame = self.frames[page]
        frame.tkraise()
        self.title("Pacemaker")

app = Application()
app.maxsize(1280,720)
sv_ttk.set_theme("light")
app.mainloop()
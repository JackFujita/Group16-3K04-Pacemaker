from atexit import register
from calendar import c
from pickle import TRUE
from statistics import mode
import tkinter as tk
from tkinter import BOTTOM, LEFT, RAISED, RIGHT, TOP, PhotoImage, ttk
from tkinter import StringVar, messagebox
import csv
from turtle import left, right
import sv_ttk
from PIL import ImageTk, Image

class Welcome(ttk.Frame):
    def __init__(self, parent, controller):
        ttk.Frame.__init__(self, parent)  
# ---------------------------------------------------------------------------------------------------
        #Make sure we know what this stuff actually means for the discussion

        frame = ttk.Frame(self, padding = 200)
        frame.pack()
        welcomeLabel = ttk.Label(frame, text = 'Welcome to Pacemaker', font = ("Roboto medium", 20))
        #welcomeLabel.grid(row = 0, column = 2, padx = 10, pady = 5)
        welcomeLabel.pack(pady = 20)

        # Button = tk.Button(self, text="Login", font=("Arial", 15), command=lambda: controller.show_frame(Login))
        # Button.grid(row = 3, column = 2, padx = 10, pady = 10)
                
        # Button = tk.Button(self, text="Register", font=("Arial", 15), command=lambda: controller.register)
        # Button.grid(row = 4, column = 2, padx = 20, pady = 5)

        Button = ttk.Button(frame, text = "Login", command=lambda: controller.show_frame(Login), width=30)
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

        controller.set_mode("AOO")
        
        top_frame = ttk.Frame(self, padding = 20, width = 300)
        top_frame.pack(fill='x', side = TOP)

        second_top = ttk.LabelFrame(self, text = "Connection Status", padding = 20, width = 200) ## Width doesnt work if grid propogate is not called
        second_top.pack(fill = 'x', padx = 150, pady = 10, side = TOP)

        bottom_frame = ttk.Frame(self, padding = 10, width = 400)
        bottom_frame.pack(fill = 'x', side=BOTTOM)

        options = ["123", "234", "345", "456", "567", "678"]
        clicked = StringVar()

        Test_label = ttk.Label(top_frame, text="Pacemaker ID simulation: ")
        Test_label.pack(side=LEFT)
        w = ttk.OptionMenu(top_frame, clicked, options[0], *options)
        w.pack(side=LEFT)

        new_pacemaker_label = ttk.Label(second_top)
        new_pacemaker_label.pack(pady = 20)

        icon = ttk.Label(second_top)
        icon.pack(side = LEFT, padx=10)

        label = ttk.Label(second_top)
        label.pack(side = LEFT)

        prev_IDs = []
        global connected ## GLOBAL IS BAD
        global applied 
        connected = False
        applied = False

        def connect():
            label.config(text="Pacemaker Connected")
            image = Image.open('Pictures/connect.png')
            image = image.resize((20,20), Image.ANTIALIAS)
            global my_image
            my_image = ImageTk.PhotoImage(image)
            icon.config(image = my_image)

            new_pm = True
            for id in prev_IDs:
                if id == clicked.get():
                    new_pm = False
            prev_IDs.append(clicked.get())
            if new_pm:
                new_pacemaker_label.config(text = "New Pacemaker Connected!")
            else:
                new_pacemaker_label.config(text = "Welcome Back!")
            global connected  #GLOBAL IS BAD
            connected = True


        def disconnect():
            label.config(text="No Pacemaker Connected...")
            image = Image.open('Pictures/disconnect2.png')
            image = image.resize((20,20), Image.ANTIALIAS)
            global my_image
            my_image = ImageTk.PhotoImage(image)
            icon.config(image = my_image)

            new_pacemaker_label.config(text = "")
            global connected ## GLOBAL IS BAD
            connected = False


        disconnect_button = ttk.Button(top_frame, command= disconnect, text='Disonnect Pacemaker Simulation')
        disconnect_button.pack(side=RIGHT)
        
        connect_button = ttk.Button(top_frame, command= connect, text='Connect Pacemaker Simulation')
        connect_button.pack(side=RIGHT)

        options = ["123", "234", "345", "456", "567", "678"]
        
        border = ttk.LabelFrame(self, text='Mode Select')
        border.pack(fill="x", expand="yes", padx = 150, pady=10)

        Button = ttk.Button(bottom_frame, text="Back To Login", command=lambda: controller.show_frame(Login))
        Button.pack(side= LEFT)

        def switch_check():
            if connected and applied:
                print("switch page")
                controller.show_frame(ParamSelect)
            else:
                errormsg.config(text = "Please connect or select a mode")

        
        # Button = ttk.Button(bottom_frame, text="Next", command=lambda: controller.show_frame(ParamSelect))
        Button = ttk.Button(bottom_frame, text="Next", command= switch_check)
        Button.pack(side = RIGHT)

        errormsg = ttk.Label(bottom_frame, foreground='#fff000000')
        errormsg.pack(side = TOP)

        ##CHECK TO SEE IF THEY HAVE FILLED OUT THE FORM BEFORE GOING TO NEXT

        def save_mode():
            if connected:
                print(selected.get())
                global applied
                applied = True
                errormsg.config(text = '')
                controller.set_mode(selected.get())
                # self.mode = selected.get()
            else:
                # messagebox.showinfo("Error","Please connect a pacemaker")
                errormsg.config(text = "Please connect a pacemaker")
                return

            if selected.get() == '':
                errormsg.config(text = "Please select an option")
                # messagebox.showinfo("Error","Please select an option")

        modes = ["AOO", 'VOO', 'AAI', 'VII']
        selected = StringVar()

        for mode in modes:
            r = ttk.Radiobutton(border, text=mode, value=mode,variable = selected)
            r.pack(fill='x', padx = 5, pady = 5)

        button = ttk.Button(border, text = "Apply", command = save_mode)
        button.pack(fill='x', padx=5,pady=5)

        #Button = tk.Button(self, text="Submit", font=("Arial", 15), command=lambda: controller.submit(data) )
        
    def get_mode(self):
        print(self.mode)
        return self.mode 
    # def set_mode():
    #     return
    # private: mode

class ParamSelect(ttk.Frame):
    def __init__(self, parent, controller):
        ttk.Frame.__init__(self, parent)
        # Implement checks to see if the parameter values are valid
        # will they mess up the pacemaker? (check that here)

        posY = 25
        posX = 250

        yPad = 15
        yPadEntry = 8

        top = ttk.Frame(self, width = 500)
        top.pack(side = TOP)

        bottom = ttk.Frame(self, width = 500)
        bottom.pack(side = BOTTOM)

        border = ttk.Frame(self, width = 300)
        border.pack(side = LEFT)

        entry = ttk.Frame(self, width = 300)
        entry.pack(side = LEFT)

        Label = ttk.Label(top, text="Programmable Parameters", font=("Arial Bold", 20))
        Label.pack(pady = 25)

        BackToLogin = ttk.Button(bottom, text="Back To Login", command=lambda: controller.show_frame(Login))
        BackToLogin.pack(side = LEFT, padx = 100)

        Back = ttk.Button(bottom, text="Back", command=lambda: controller.show_frame(ModeSelect))
        Back.pack(side = LEFT, padx = 100)

        L1 = ttk.Label(border, text="Lower Rate Limit", font=("Arial Bold", 10))
        L1.pack(padx = 200, pady = yPad)

        param1 = ttk.Entry(entry, width = 30)
        param1.pack(pady = yPadEntry)

        L1 = ttk.Label(border, text="Upper Rate Limit", font=("Arial Bold", 10))
        L1.pack(pady = yPad)

        param2 = ttk.Entry(entry, width = 30)
        param2.pack(pady = yPadEntry)

        L1 = ttk.Label(border, text="Atrial Amplitude", font=("Arial Bold", 10))
        L1.pack(pady = yPad)

        param3 = ttk.Entry(entry, width = 30)
        param3.pack(pady = yPadEntry)

        L1 = ttk.Label(border, text="Atrial Pulse Width", font=("Arial Bold", 10))
        L1.pack(pady = yPad)

        param4 = ttk.Entry(entry, width = 30)
        param4.pack(pady = yPadEntry)

        L1 = ttk.Label(border, text="Ventricular Amplitude", font=("Arial Bold", 10))
        L1.pack(pady = yPad)

        param5 = ttk.Entry(entry, width = 30)
        param5.pack(pady = yPadEntry)

        L1 = ttk.Label(border, text="Ventricular Pulse Width", font=("Arial Bold", 10))
        L1.pack(pady = yPad)

        param6 = ttk.Entry(entry, width = 30)
        param6.pack(pady = yPadEntry)

        L1 = ttk.Label(border, text="VRP", font=("Arial Bold", 10))
        L1.pack(pady = yPad)

        param7 = ttk.Entry(entry, width = 30)
        param7.pack(pady = yPadEntry)

        L1 = ttk.Label(border, text="ARP", font=("Arial Bold", 10))
        L1.pack(pady = yPad)

        param8 = ttk.Entry(entry, width = 30)
        param8.pack(pady = yPadEntry)

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

        Apply = ttk.Button(bottom, text="Apply Changes", command=applyChanges)
        Apply.pack(side = LEFT, padx = 100)

class Application(tk.Tk):
    def __init__(self, *args, **kwargs):
        tk.Tk.__init__(self, *args, **kwargs)
        self.mode = "test mode"
        #creating a window
        self.window = tk.Frame(self)
        self.window.pack()
        
        self.window.grid_rowconfigure(0, minsize = 500)
        self.window.grid_columnconfigure(0, minsize = 800)
        
        self.frames = {}
        # for F in (Welcome, Login, ModeSelect, ParamSelect):
        #     frame = F(self.window, self)
        #         #frame = Welcome(window, self)
        #     self.frames[F] = frame
        #     frame.grid(row = 0, column=0, sticky="nsew")
        # # self.frames = {Welcome(window, self), Login(window, self), ModeSelect(windoe,self), ParamSelect(window,self)}
        self.show_frame(Welcome)
        
    def show_frame(self, page):
        frame = page(self.window, self)
        self.frames[page] = frame
        frame.grid(row = 0, column=0, sticky="nsew")
        frame.tkraise()
        self.title("Pacemaker")

    def back(self, page):
        frame = self.frames[page]
        frame.tkraise()
        self.title("Pacemaker")


    def set_mode(self, input_mode):
        self.mode = input_mode
        print("set mode:", self.mode)

    def get_mode(self):
        print("get mode:", self.mode)
        return self.mode

app = Application()
app.maxsize(1280,720)
sv_ttk.set_theme("light")
app.mainloop()
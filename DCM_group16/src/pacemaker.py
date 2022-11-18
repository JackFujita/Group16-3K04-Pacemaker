import secrets
import tkinter as tk
from tkinter import BOTTOM, LEFT, RAISED, RIGHT, TOP, PhotoImage, ttk
from tkinter import StringVar, messagebox
import csv
import sv_ttk
from PIL import ImageTk, Image

class Welcome(ttk.Frame):
    def __init__(self, parent, controller):
        ttk.Frame.__init__(self, parent)  

        frame = ttk.Frame(self, padding = 200)
        frame.pack()
        welcomeLabel = ttk.Label(frame, text = 'Welcome to Pacemaker', font = ("Roboto medium", 20))

        welcomeLabel.pack(pady = 20)

        Button = ttk.Button(frame, text = "Login", command=lambda: controller.show_frame(Login), width=30)
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
            try:
                with open("Secrets.csv", 'r') as file:
                    csv_reader=csv.reader(file)
                    row_count = sum(1 for row in csv_reader)
                if row_count >= 10:
                    Username_login.config(text="aaa")
                    messagebox.showinfo("Error", "You have reached the maximum number of registered members on this device")
                    return
            except:
                pass
            
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

        Button = ttk.Button(bottom_frame, text="Next", command= switch_check)
        Button.pack(side = RIGHT)

        errormsg = ttk.Label(bottom_frame, foreground='#fff000000')
        errormsg.pack(side = TOP)

        def save_mode():
            if connected:
                print(selected.get())
                global applied
                applied = True
                errormsg.config(text = '')
                controller.set_mode(selected.get())
            else:
                errormsg.config(text = "Please connect a pacemaker")
                return

            if selected.get() == '':
                errormsg.config(text = "Please select an option")

        modes = ["AOO", 'VOO', 'AAI', 'VVI']
        selected = StringVar()

        for mode in modes:
            r = ttk.Radiobutton(border, text=mode, value=mode,variable = selected)
            r.pack(fill='x', padx = 5, pady = 5)

        button = ttk.Button(border, text = "Apply", command = save_mode)
        button.pack(fill='x', padx=5,pady=5)

class ParamSelect(ttk.Frame):
    def __init__(self, parent, controller):
        ttk.Frame.__init__(self, parent)

        yPad = 15
        yPadEntry = 8

        yPad = 30
        yPadEntry = 23

        top = ttk.Frame(self, width = 500)
        top.pack(side = TOP)

        bottom = ttk.Frame(self, width = 500)
        bottom.pack(side = BOTTOM)

        border = ttk.Frame(self, width = 300)
        border.pack(side = LEFT, padx = 150)

        entry = ttk.Frame(self, width = 300)
        entry.pack(side = LEFT)

        errors = ttk.Frame(self, width = 300)
        errors.pack(side = LEFT, padx = 25)

        Label = ttk.Label(top, text="Programmable Parameters", font=("Arial Bold", 20))
        Label.pack(pady = 25)

        BackToLogin = ttk.Button(bottom, text="Back To Login", command=lambda: controller.show_frame(Login))
        BackToLogin.pack(side = LEFT, padx = 100)

        Back = ttk.Button(bottom, text="Back", command=lambda: controller.back(ModeSelect))
        Back.pack(side = LEFT, padx = 100)

        L1 = ttk.Label(border, text="Lower Rate Limit", font=("Arial Bold", 10))
        L1.pack(pady = yPad)

        param1 = ttk.Entry(entry, width = 30)
        param1.pack(pady = yPadEntry)

        error1 = ttk.Label(errors, foreground='#fff000000')
        error1.pack(pady = yPad)

        L1 = ttk.Label(border, text="Upper Rate Limit", font=("Arial Bold", 10))
        L1.pack(pady = yPad)

        param2 = ttk.Entry(entry, width = 30)
        param2.pack(pady = yPadEntry)

        error2 = ttk.Label(errors, foreground='#fff000000')
        error2.pack(pady = yPad)

        # Switch depending on mode
        mode = controller.get_mode()

        if (mode == "AOO" or mode == "AAI"):
            L1 = ttk.Label(border, text="Atrial Amplitude", font=("Arial Bold", 10))
            L1.pack(pady = yPad)

            param3 = ttk.Entry(entry, width = 50)
            param3.pack(pady = yPadEntry)

            error3 = ttk.Label(errors, foreground='#fff000000')
            error3.pack(pady = yPad)

            L1 = ttk.Label(border, text="Atrial Pulse Width", font=("Arial Bold", 10))
            L1.pack(pady = yPad)

            param4 = ttk.Entry(entry, width = 30)
            param4.pack(pady = yPadEntry)

            error4 = ttk.Label(errors, foreground='#fff000000')
            error4.pack(pady = yPad)

        if (mode == "VOO" or mode == "VVI"):
            L1 = ttk.Label(border, text="Ventricular Amplitude", font=("Arial Bold", 10))
            L1.pack(pady = yPad)

            param5 = ttk.Entry(entry, width = 30)
            param5.pack(pady = yPadEntry)

            error5 = ttk.Label(errors, foreground='#fff000000')
            error5.pack(pady = yPad)

            L1 = ttk.Label(border, text="Ventricular Pulse Width", font=("Arial Bold", 10))
            L1.pack(pady = yPad)

            param6 = ttk.Entry(entry, width = 30)
            param6.pack(pady = yPadEntry)

            error6 = ttk.Label(errors, foreground='#fff000000')
            error6.pack(pady = yPad)

        if (mode == "VVI"):
            L1 = ttk.Label(border, text="VRP", font=("Arial Bold", 10))
            L1.pack(pady = yPad)

            param7 = ttk.Entry(entry, width = 30)
            param7.pack(pady = yPadEntry)

            error7 = ttk.Label(errors, foreground='#fff000000')
            error7.pack(pady = yPad)

        if (mode == "AAI"):
            L1 = ttk.Label(border, text="ARP", font=("Arial Bold", 10))
            L1.pack(pady = yPad)

            param8 = ttk.Entry(entry, width = 30)
            param8.pack(pady = yPadEntry)

            error8 = ttk.Label(errors, foreground='#fff000000')
            error8.pack(pady = yPad)

        def applyChanges():
            error1.config(text = '')
            error2.config(text = '')

            if (param1.get()):
                try:
                    intLRL = int(param1.get())

                    stringLRL = param1.get()

                    checkLRL = controller.check_noDigits(stringLRL)

                    if (checkLRL):
                        param1.delete(0, 100)
                        error1.config(text = 'Please enter an integer between 30 and 50 divisible by 5 or \nbetween 50 and 90 divisible by 1 or between 90 and 175 divisible by 5')
                    else:
                        if ((intLRL >= 30 and intLRL <= 50 and intLRL % 5 == 0) or (intLRL >= 50 and intLRL <= 90 and intLRL % 1 == 0) or (intLRL >= 90 and intLRL <= 175 and intLRL % 5 == 0)):
                            lowerRateLimit = intLRL
                        else:
                            param1.delete(0, 100)
                            error1.config(text = 'Please enter an integer between 30 and 50 divisible by 5 or \nbetween 50 and 90 divisible by 1 or between 90 and 175 divisible by 5')
                except:
                    param1.delete(0, 100)
                    error1.config(text = 'Please enter an integer')
            else:
                error1.config(text = 'Please make entries for all fields')

            if (param2.get()):
                try:
                    intURL = int(param2.get())
                    stringURL = param2.get()

                    checkURL = controller.check_noDigits(stringURL)

                    if (checkLRL):
                        param2.delete(0, 100)
                        error2.config(text = 'Please enter an integer \nbetween 50 and 175 divisible by 5')
                    else:
                        if (intURL >= 50 and intURL <= 175 and intURL % 5 == 0):
                            upperRateLimit = intURL
                        else:
                            param2.delete(0, 100)
                            error2.config(text = 'Please enter an integer \nbetween 50 and 175 divisible by 5')
                except:
                    param2.delete(0, 100)
                    error2.config(text = 'Please enter an integer')
            else:
                error2.config(text = 'Please make entries for all fields')
            
            if (mode == "AOO" or mode == "AAI"):
                error3.config(text = '')
                error4.config(text = '')

                if (param3.get()):
                    try:
                        intAAMP = int(float(param3.get()) * 10)
                        stringAAMP = param3.get()

                        checkAAMP = controller.check_digits(stringAAMP)

                        if (checkAAMP):
                            param3.delete(0, 100)
                            error3.config(text = 'Please enter 0 or a decimal between 0.5 and 3.2 divisible by 0.1 \nor between 3.5 and 7 divisible by 0.5')
                        else:
                            if (intAAMP == 0 or (intAAMP >= 5 and intAAMP <= 32 and intAAMP % 1 == 0) or (intAAMP >= 35 and intAAMP <= 70 and intAAMP % 5 == 0)):
                                atrialAmp = intAAMP
                            else:
                                param3.delete(0, 100)
                                error3.config(text = 'Please enter 0 or a decimal between 0.5 and 3.2 divisible by 0.1 \nor between 3.5 and 7 divisible by 0.5')
                    except:
                        param3.delete(0, 100)
                        error3.config(text = 'Please enter an decimal value or 0')
                else:
                    error3.config(text = 'Please make entries for all fields')

                if (param4.get()):
                    try:
                        intAPW = int(float(param4.get()) * 100)
                        stringAPW = param4.get()

                        checkAPW = controller.check_digits(stringAPW)

                        if (checkAPW):
                            param4.delete(0, 100)
                            error4.config(text = 'Please enter 0.05 or a decimal between \n0.1 and 1.9 divisible by 0.1')
                        else:
                            if (intAPW == 5 or (intAPW >= 10 and intAPW <= 190 and intAPW % 10 == 0)):
                                atrialPW = intAPW
                            else:
                                param4.delete(0, 100)
                                error4.config(text = 'Please enter 0.05 or a decimal between \n0.1 and 1.9 divisible by 0.1')
                    except:
                        param4.delete(0, 100)
                        error4.config(text = 'Please enter a decimal')
                else:
                    error4.config(text = 'Please make entries for all fields')


            if (mode == "VOO" or mode == "VVI"):
                error5.config(text = '')
                error6.config(text = '')

                if (param5.get()):
                    try:
                        intVAMP = int(float(param5.get()) * 10)
                        stringVAMP = param5.get()

                        checkVAMP = controller.check_digits(stringVAMP)

                        if (checkVAMP):
                            param5.delete(0, 100)
                            error5.config(text = 'Please enter 0 or a decimal between 0.5 and 3.2 divisible by 0.1 \nor between 3.5 and 7 divisible by 0.5')
                        else:
                            if (intVAMP == 0 or (intVAMP >= 5 and intVAMP <= 32 and intVAMP % 1 == 0) or (intVAMP >= 35 and intVAMP <= 70 and intVAMP % 5 == 0)):
                                ventricularAmp = intVAMP
                            else:
                                param5.delete(0, 100)
                                error5.config(text = 'Please enter 0 or a decimal between 0.5 and 3.2 divisible by 0.1 \nor between 3.5 and 7 divisible by 0.5')
                    except:
                        param5.delete(0, 100)
                        error5.config(text = 'Please enter a decimal or 0')
                else:
                    error5.config(text = 'Please make entries for all fields')

                if (param6.get()):
                    try:
                        intVPW = int(float(param6.get()) * 100)
                        stringVPW = param6.get()

                        checkVPW = controller.check_digits(stringVPW)

                        if (checkVPW):
                            param6.delete(0, 100)
                            error6.config(text = 'Please enter 0.05 or a decimal between \n0.1 and 1.9 divisible by 0.1')
                        else:
                            if (intVPW == 5 or (intVPW >= 10 and intVPW <= 190 and intVPW % 10 == 0)):
                                ventricularPW = intVPW
                            else:
                                param6.delete(0, 100)
                                error6.config(text = 'Please enter 0.05 or a decimal between \n0.1 and 1.9 divisible by 0.1')
                    except:
                        param6.delete(0, 100)
                        error6.config(text = 'Please enter a decimal')
                else:
                    error6.config(text = 'Please make entries for all fields')

            if (mode == "VVI"):
                error7.config(text = '')

                if (param7.get()):
                    try:
                        intVRP = int(param7.get())
                        stringVRP = param7.get()

                        checkVRP = controller.check_noDigits(stringVRP)

                        if (checkVRP):
                            param7.delete(0, 100)
                            error7.config(text = 'Please enter a valid integer between \n150 and 500 divisible by 10')
                        else:
                            if (intVRP >= 150 and intVRP <= 500 and intVRP % 10 == 0):
                                vrp = intVRP
                            else:
                                param7.delete(0, 100)
                                error7.config(text = 'Please enter a valid integer between \n150 and 500 divisible by 10')
                    except:
                        param7.delete(0, 100)
                        error7.config(text = 'Please enter an integer')
                else:
                    error7.config(text = 'Please make entries for all fields')

            if (mode == "AAI"):
                error8.config(text = '')

                if(param8.get()):
                    try:
                        intARP = int(param8.get())
                        stringARP = param8.get()

                        checkARP = controller.check_noDigits(stringARP)

                        if (checkARP):
                            param7.delete(0, 100)
                            error7.config(text = 'Please enter a valid integer between \n150 and 500 divisible by 10')
                        else:
                            if (intARP >= 150 and intARP <= 500 and intARP % 10 == 0):
                                arp = intARP
                            else:
                                param8.delete(0, 100)
                                error8.config(text = 'Please enter a valid integer between \n150 and 500 divisible by 10')
                    except:
                        param8.delete(0, 100)
                        error8.config(text = 'Please enter an integer')
                else:
                    error8.config(text = 'Please make entries for all fields')


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

    def check_digits(self, inputP):
        #Janky solution for checking inputs
        badInput = False

        for i in range(0, len(inputP)):
            if (inputP[i] == '.'):
                for j in range(i + 2, len(inputP)):
                    print(j)
                    if (inputP[j] != 0):
                        badInput = True
                        break
        return badInput

    def check_noDigits(self, inputP):
        badInput = False

        for i in range(0, len(inputP)):
            if (inputP[i] == '.'):
                badInput = True
                break

        return badInput

app = Application()
app.maxsize(1280,720)
sv_ttk.set_theme("light")
app.mainloop()
import tkinter as tk
from tkinter import BOTTOM, LEFT, RAISED, RIGHT, TOP, PhotoImage, ttk
from tkinter import StringVar, messagebox
import csv
import sv_ttk
from PIL import ImageTk, Image

# The first welcome frame block
class Welcome(ttk.Frame):
    def __init__(self, parent, controller):
        ttk.Frame.__init__(self, parent)  

        frame = ttk.Frame(self, padding = 200)                                                                          #setting up the size of the frame
        frame.pack()                                                                                                    #pack the frame
        welcomeLabel = ttk.Label(frame, text = 'Welcome to Pacemaker', font = ("Roboto medium", 20))                    #set a label inside the frame

        welcomeLabel.pack(pady = 20)

        Button = ttk.Button(frame, text = "Login", command=lambda: controller.show_frame(Login), width=30)              #set a button which linked to the login frame
        Button.pack()

#the login frame block
class Login(ttk.Frame):
    def __init__(self, parent, controller):
        ttk.Frame.__init__(self, parent)

        # this block of code is use to creat a label use to contain username entry and password entry.
        border = ttk.LabelFrame(self, text='Login')
        border.pack(fill="both", expand="yes", padx = 150, pady=150)

        # the username entry
        L1 = ttk.Label(border, text="Username", font=("Arial", 15))
        L1.place(x=50, y=20)
        Username_login = ttk.Entry(border, width = 30)
        Username_login.place(x=180, y=20)

        # the password entry
        L2 = ttk.Label(border, text="Password", font=("Arial", 15))
        L2.place(x=50, y=80)
        Password_login = ttk.Entry(border, width = 30, show='*')
        Password_login.place(x=180, y=80)

        # This method is used to verify the user's input password and username is correct
        def verify():
            # get user input
            input_username = Username_login.get()
            input_password = Password_login.get()

            try:
                with open("Secrets.csv", 'r') as file:                                                                  # open the csv file which store all usernames and passwords, if there is no such file, creat a new one
                    csv_reader=csv.reader(file)
                    login_true = False
                    for line in csv_reader:                                                                             # read line in the csv file, and check is there any username and it's corresponding password match the user input
                        if (line[0]==input_username) and (line[1]==input_password):
                            login_true = True
                            break
                    if login_true:                                                                                      #if matchs, print message and go to the mode select frame
                        print("he valid")
                        controller.show_frame(ModeSelect)
                    else:                                                                                               #if not match, print message and show a message box which let user input again.
                        print("invalid")
                        messagebox.showinfo("Error", "Please provide correct username and password")
            except:                                                                                                     #show the error
                messagebox.showinfo("Error", "Please provide correct username and password")
         
        verify_button = ttk.Button(border, text="Submit", command=verify)                                               #set a button link to verify method
        verify_button.place(x=320, y=130)

        # this method is use to let new user to register a new account
        def register():
            try:                                                                                                        #check the total register user number less than 10
                with open("Secrets.csv", 'r') as file:
                    csv_reader=csv.reader(file)
                    row_count = sum(1 for row in csv_reader)
                if row_count >= 10:
                    Username_login.config(text="aaa")
                    messagebox.showinfo("Error", "You have reached the maximum number of registered members on this device")
                    return
            except:
                pass

            # this block set the size of frame and three entries which let user input their username and password
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

            # this method is use to check the user's input is obey the rule
            def check():
                if Username_register.get()!="" or Password_register.get()!="" or Password_register_2.get()!="":         # check all three input is not empty
                    if Password_register.get()==Password_register_2.get():                                              # check two password input is same
                        with open("Secrets.csv", 'a', newline='') as file:                                              # if all input is good, write the username and password into the store csv file(if there is no such file, creat one)
                            writer = csv.writer(file)
                            writer.writerow([Username_register.get(), Password_register.get()])
                        messagebox.showinfo("Welcome","You are registered successfully")                                #show a message box as welcome if all check pass
                        ###IMPLEMENT MAX USER FUNCTIONALITY
                    else:
                        messagebox.showinfo("Error","Your password didn't get match")                                   #show a message box as error if some step is not pass
                else:
                    messagebox.showinfo("Error", "Please fill the complete field")                                      #show a message box which remind user do not input empty
                    
            b1 = ttk.Button(window, text="Register", command=check)                                                     #set a button linked to check method
            b1.place(x=220, y=150)

            sv_ttk.set_theme("light")
            window.mainloop()                                                                                           #make register frame runing before any other frame until the register step over
            
        B2 = ttk.Button(self, text="Register", command=register)                                                        #set a button to call the register frame
        B2.place(x=650, y=10)

        B3 = ttk.Button(self, text = "Back to welcome", command=lambda: controller.show_frame(Welcome))                 #set a button back to the welcome frame
        B3.place(x=10,y=10)



#the mode select frame
class ModeSelect(ttk.Frame):
    def __init__(self, parent, controller):
        ttk.Frame.__init__(self, parent)

        # creating mode select frame and inside it has some label to show the connetion state and each mode that user can select
        controller.set_mode("AOO")
        
        top_frame = ttk.Frame(self, padding = 20, width = 300)
        top_frame.pack(fill='x', side = TOP)

        second_top = ttk.LabelFrame(self, text = "Connection Status", padding = 20, width = 200) ## Width doesnt work if grid propogate is not called
        second_top.pack(fill = 'x', padx = 150, pady = 10, side = TOP)

        bottom_frame = ttk.Frame(self, padding = 10, width = 400)
        bottom_frame.pack(fill = 'x', side=BOTTOM)

        # provide the different id that you can select
        options = ["123", "234", "345", "456", "567", "678"]
        clicked = StringVar()   #make the string change when user change the select

        # set the connection part label block size and position
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
        # two global variable that used in following methods.
        global connected ## GLOBAL IS BAD
        global applied 
        connected = False
        applied = False

        # method to connect the pacemaker
        def connect():
            label.config(text="Pacemaker Connected")
            image = Image.open('Pictures/connect.png')                                                                           #show a connecting picture when connected
            image = image.resize((20,20), Image.ANTIALIAS)
            global my_image
            my_image = ImageTk.PhotoImage(image)
            icon.config(image = my_image)

            new_pm = True                                                                                               #check is this pacemaker connected before during the windows runing
            for id in prev_IDs:
                if id == clicked.get():                                                                                 #check is the pacemaker id connected before
                    new_pm = False
            prev_IDs.append(clicked.get())                                                                              #put the current id into the store list
            if new_pm:
                new_pacemaker_label.config(text = "New Pacemaker Connected!")                                           #if it is a new pacemaker, print a text
                controller.setDefaultParams(12345) #Creates default parameters (need a real id to send here)
            else:
                new_pacemaker_label.config(text = "Welcome Back!")                                                      #if it is a old pacemaker, show welcome back
            global connected  #GLOBAL IS BAD
            connected = True                                                                                            #the pacemaker is now connected

        # mehtod to disconnect the pacemaker
        def disconnect():
            label.config(text="No Pacemaker Connected...")                                                              #show a picture when disconnect
            image = Image.open('Pictures/disconnect2.png')
            image = image.resize((20,20), Image.ANTIALIAS)
            global my_image
            my_image = ImageTk.PhotoImage(image)
            icon.config(image = my_image)

            new_pacemaker_label.config(text = "")
            global connected ## GLOBAL IS BAD
            connected = False                                                                                           #the pacemaker is now disconnect


        disconnect_button = ttk.Button(top_frame, command= disconnect, text='Disonnect Pacemaker Simulation')           #set the disconnect button like to disconnect method
        disconnect_button.pack(side=RIGHT)
        
        connect_button = ttk.Button(top_frame, command= connect, text='Connect Pacemaker Simulation')                   #set the connect button like to connect method
        connect_button.pack(side=RIGHT)

        options = ["123", "234", "345", "456", "567", "678"]                                                            #the giving pacemaker ID
        
        border = ttk.LabelFrame(self, text='Mode Select')                                                               #the different mode label
        border.pack(fill="x", expand="yes", padx = 150, pady=10)

        Button = ttk.Button(bottom_frame, text="Back To Login", command=lambda: controller.show_frame(Login))           #back to login frame button, link to show login frame method
        Button.pack(side= LEFT)

        # this method is use to check is pacemaker connect and mode is select
        def switch_check():
            if connected and applied:                                                                                   #if pacemaker is connected and mode is selected, go to the param select frame
                print("switch page")
                controller.show_frame(ParamSelect)
            else:
                errormsg.config(text = "Please connect or select a mode")                                               #if not connect or didn't select a mode, show a error

        Button = ttk.Button(bottom_frame, text="Next", command= switch_check)                                           #the button link to switch check method
        Button.pack(side = RIGHT)

        errormsg = ttk.Label(bottom_frame, foreground='#fff000000')                                                     #the error message label
        errormsg.pack(side = TOP)

        # this method is used to check can the option be apply
        def save_mode():
            if connected:                                                                                               #if pacemaker is connected, the applied will be true
                print(selected.get())
                global applied
                applied = True
                errormsg.config(text = '')
                controller.set_mode(selected.get())                                                                     #set the mode as user selected
            else:
                errormsg.config(text = "Please connect a pacemaker")                                                    # if pacemaker is not connected, return a error to tell user to connect the pacemaker
                return

            if selected.get() == '':
                errormsg.config(text = "Please select an option")                                                       #if user didn't select an option, return a error message to tell user select one

        modes = ["AOO", 'VOO', 'AAI', 'VVI']                                                                            # four modes
        selected = StringVar()                                                                                          # the selected mode will change when the user select

        for mode in modes:
            r = ttk.Radiobutton(border, text=mode, value=mode,variable = selected)                                      #creat four radio button of four modes
            r.pack(fill='x', padx = 5, pady = 5)

        button = ttk.Button(border, text = "Apply", command = save_mode)                                                #apply button link to save_mode method
        button.pack(fill='x', padx=5,pady=5)

#the param select frame
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

        BackToLogin = ttk.Button(bottom, text="Back To Login", command=lambda: controller.show_frame(Login))            #the button link to show login frame
        BackToLogin.pack(side = LEFT, padx = 100)

        Back = ttk.Button(bottom, text="Back", command=lambda: controller.back(ModeSelect))                             #the button link to mode select frame
        Back.pack(side = LEFT, padx = 100)

        # Get default parameters from file
        with open("Parameters.csv", 'r') as file:
            csv_reader=csv.reader(file)
            for line in csv_reader:
                if (line[0]): # Need proper ID checking here
                    lrl = line[1]
                    url = line[2]
                    aamp = line[3]
                    vamp = line[4]
                    apw = line[5]
                    vpw = line[6]
                    arp = line[7]
                    vrp = line[8]
                    break
                else:
                    print("No matching ID")

        L1 = ttk.Label(border, text="Lower Rate Limit", font=("Arial Bold", 10))
        L1.pack(pady = yPad)

        #set all entry bars and labels
        #the entry bar will have a default parameters
        param1 = ttk.Entry(entry, width = 30)
        try:
            param1.insert(0, lrl)                                                                                       #default parameter
        except:
            pass
        param1.pack(pady = yPadEntry)

        error1 = ttk.Label(errors, foreground='#fff000000')
        error1.pack(pady = yPad)

        L1 = ttk.Label(border, text="Upper Rate Limit", font=("Arial Bold", 10))
        L1.pack(pady = yPad)

        #same as param1
        param2 = ttk.Entry(entry, width = 30)
        try:
            param2.insert(0, url)
        except:
            pass
        param2.pack(pady = yPadEntry)

        error2 = ttk.Label(errors, foreground='#fff000000')
        error2.pack(pady = yPad)

        # Switch depending on mode
        mode = controller.get_mode()


        #according to different mode user selected before, show different label and different default parameters
        if (mode == "AOO" or mode == "AAI"):
            L1 = ttk.Label(border, text="Atrial Amplitude", font=("Arial Bold", 10))
            L1.pack(pady = yPad)

            param3 = ttk.Entry(entry, width = 30)
            try:
                param3.insert(0, aamp)
            except:
                pass
            param3.pack(pady = yPadEntry)

            error3 = ttk.Label(errors, foreground='#fff000000')
            error3.pack(pady = yPad)

            L1 = ttk.Label(border, text="Atrial Pulse Width", font=("Arial Bold", 10))
            L1.pack(pady = yPad)

            param4 = ttk.Entry(entry, width = 30)
            try:
                param4.insert(0, apw)
            except:
                pass
            param4.pack(pady = yPadEntry)

            error4 = ttk.Label(errors, foreground='#fff000000')
            error4.pack(pady = yPad)

        if (mode == "VOO" or mode == "VVI"):
            L1 = ttk.Label(border, text="Ventricular Amplitude", font=("Arial Bold", 10))
            L1.pack(pady = yPad)

            param5 = ttk.Entry(entry, width = 30)
            try:
                param5.insert(0, vamp)
            except:
                pass
            param5.pack(pady = yPadEntry)

            error5 = ttk.Label(errors, foreground='#fff000000')
            error5.pack(pady = yPad)

            L1 = ttk.Label(border, text="Ventricular Pulse Width", font=("Arial Bold", 10))
            L1.pack(pady = yPad)

            param6 = ttk.Entry(entry, width = 30)
            try:
                param6.insert(0, vpw)
            except:
                pass
            param6.pack(pady = yPadEntry)

            error6 = ttk.Label(errors, foreground='#fff000000')
            error6.pack(pady = yPad)

        if (mode == "VVI"):
            L1 = ttk.Label(border, text="VRP", font=("Arial Bold", 10))
            L1.pack(pady = yPad)

            param7 = ttk.Entry(entry, width = 30)
            try:
                param7.insert(0, vrp)
            except:
                pass
            param7.pack(pady = yPadEntry)

            error7 = ttk.Label(errors, foreground='#fff000000')
            error7.pack(pady = yPad)

        if (mode == "AAI"):
            L1 = ttk.Label(border, text="ARP", font=("Arial Bold", 10))
            L1.pack(pady = yPad)

            param8 = ttk.Entry(entry, width = 30)
            try:
                param8.insert(0, arp)
            except:
                pass
            param8.pack(pady = yPadEntry)

            error8 = ttk.Label(errors, foreground='#fff000000')
            error8.pack(pady = yPad)

        #apply changes method, when call this method, it will check the user input parameters are coorect or not
        def applyChanges():
            error1.config(text = '')
            error2.config(text = '')

            LRLSet = False
            URLSet = False

            #for parameter 1, check the input is digits and the value is in range, else give user a message to remind user.
            #the range is between 30 and 50 divisible by 5 or between 50 and 90 divisible by 1 or between 90 and 175 divisible by 5
            # if pass, the LRLSet became Ture, and lowerRateLimit = intLRL
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
                            LRLSet = True
                        else:
                            param1.delete(0, 100)
                            error1.config(text = 'Please enter an integer between 30 and 50 divisible by 5 or \nbetween 50 and 90 divisible by 1 or between 90 and 175 divisible by 5')
                except:
                    param1.delete(0, 100)
                    error1.config(text = 'Please enter an integer')
            else:
                error1.config(text = 'Please make entries for all fields')

            # for parameter 2, check the input is digits and the value is in range, else give user a message to remind user.
            #the range is between 50 and 175 divisible by 5
            #if pass, the URLSet became Ture and upperRateLimit = intURL
            if (param2.get()):
                try:
                    intURL = int(param2.get())
                    stringURL = param2.get()

                    checkURL = controller.check_noDigits(stringURL)

                    if (checkURL):
                        param2.delete(0, 100)
                        error2.config(text = 'Please enter an integer \nbetween 50 and 175 divisible by 5')
                    else:
                        if (intURL >= 50 and intURL <= 175 and intURL % 5 == 0):
                            upperRateLimit = intURL
                            URLSet = True
                        else:
                            param2.delete(0, 100)
                            error2.config(text = 'Please enter an integer \nbetween 50 and 175 divisible by 5')
                except:
                    param2.delete(0, 100)
                    error2.config(text = 'Please enter an integer')
            else:
                error2.config(text = 'Please make entries for all fields')

            #if the URLSet and LRLSet all true and lowerRateLimit > upperRateLimit, give an error message to user and delete the user input
            if (LRLSet and URLSet):
                if (lowerRateLimit > upperRateLimit):
                    param1.delete(0, 100)
                    error1.config(text = 'Please make sure that \nlower rate limit is less than \nupper rate limit')
                    param2.delete(0, 100)


            #if user select mode AOO or AAI
            #make all parameters are in range and not empty
            #range of AAMP is between 0.5 and 3.2 divisible by 0.1 or between 3.5 and 7 divisible by 0.5
            #the range of APW is 0.05 or a decimal between 0.1 and 1.9 divisible by 0.1
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
                        error3.config(text = 'Please enter a decimal value or 0')
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



            # if user select mode VOO or VVI
            # make all parameters are in range and not empty
            # range of VAMP is 0 or a decimal between 0.5 and 3.2 divisible by 0.1 or between 3.5 and 7 divisible by 0.5
            #the range of VPW is 0.05 or a decimal between 0.1 and 1.9 divisible by 0.1
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



            #if user select mode VVI
            # make all parameters are in range and not empty
            #the range of VRP is between 150 and 500 divisible by 10 and larger than (1000 / (lowerRateLimit / 60))
            VRPSet = False

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
                                VRPSet = True
                            else:
                                param7.delete(0, 100)
                                error7.config(text = 'Please enter a valid integer between \n150 and 500 divisible by 10')
                    except:
                        param7.delete(0, 100)
                        error7.config(text = 'Please enter an integer')
                else:
                    error7.config(text = 'Please make entries for all fields')


                if (VRPSet and LRLSet):
                    if (vrp > (int)(1000 / (lowerRateLimit / 60))):
                        param7.delete(0, 100)
                        error7.config(text = 'Please make sure VRP does not interfere with rate limit')



            #if user select mode AAI
            # make all parameters are in range and not empty
            #the range of ARP is between 150 and 500 divisible by 10 and ARP must larger than (1000 / (lowerRateLimit / 60))
            ARPSet = False

            if (mode == "AAI"):
                error8.config(text = '')

                if(param8.get()):
                    try:
                        intARP = int(param8.get())
                        stringARP = param8.get()

                        checkARP = controller.check_noDigits(stringARP)

                        if (checkARP):
                            param8.delete(0, 100)
                            error8.config(text = 'Please enter a valid integer between \n150 and 500 divisible by 10')
                        else:
                            if (intARP >= 150 and intARP <= 500 and intARP % 10 == 0):
                                arp = intARP
                                ARPSet = True
                            else:
                                param8.delete(0, 100)
                                error8.config(text = 'Please enter a valid integer between \n150 and 500 divisible by 10')
                    except:
                        param8.delete(0, 100)
                        error8.config(text = 'Please enter an integer')
                else:
                    error8.config(text = 'Please make entries for all fields')

                if (ARPSet and LRLSet):
                    if (arp > (int)(1000 / (lowerRateLimit / 60))):
                        param8.delete(0, 100)
                        error8.config(text = 'Please make sure ARP does not interfere with rate limit')


        Apply = ttk.Button(bottom, text="Apply Changes", command=applyChanges)                                          #button link to apply changes method, and check all input are allowed
        Apply.pack(side = LEFT, padx = 100)


#the main frame of the program
class Application(tk.Tk):
    def __init__(self, *args, **kwargs):
        tk.Tk.__init__(self, *args, **kwargs)

        #creating main frame structures and set it parameters

        self.mode = "test mode"

        self.window = tk.Frame(self)
        self.window.pack()
        
        self.window.grid_rowconfigure(0, minsize = 500)
        self.window.grid_columnconfigure(0, minsize = 800)
        
        self.frames = {}
        self.show_frame(Welcome)    #the first show frame is welcome frame

    #show the corresponding frame method
    def show_frame(self, page):
        frame = page(self.window, self)
        self.frames[page] = frame
        frame.grid(row = 0, column=0, sticky="nsew")
        frame.tkraise()
        self.title("Pacemaker")

    #back to last frame method
    def back(self, page):
        frame = self.frames[page]
        frame.tkraise()
        self.title("Pacemaker")

    #set mode method
    def set_mode(self, input_mode):
        self.mode = input_mode
        print("set mode:", self.mode)

    #get current mode method
    def get_mode(self):
        print("get mode:", self.mode)
        return self.mode


    # the method use for loop to check the input is proper digits( more than two decimal places will return True as bad input )
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

    # the method use for loop to check the input is not contain digits(if contain digits, return True as bad input)
    def check_noDigits(self, inputP):
        badInput = False

        for i in range(0, len(inputP)):
            if (inputP[i] == '.'):
                badInput = True
                break

        return badInput
    #the defualt parameters store method
    def setDefaultParams(self, pmID):
        #Default values
        lrl = 50
        url = 60
        aamp = 2.5
        vamp = 2.5
        apw = 1
        vpw = 1
        arp = 300
        vrp = 300

        with open("Parameters.csv", 'a', newline='') as file:
            writer = csv.writer(file)
            writer.writerow([pmID, lrl, url, aamp, vamp, apw, vpw, arp, vrp])

# run the frame
app = Application()
app.maxsize(1280,720)
sv_ttk.set_theme("light")
app.mainloop()
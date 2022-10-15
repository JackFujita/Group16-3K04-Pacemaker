from tkinter import *
from functools import partial
#import numpy as np
import csv

header = ['Username', 'Password']
data1 = [
	['Jack','password123'],
	['Shu','password789']]

with open("Secrets.csv", 'w', newline='') as file:
	writer = csv.writer(file)
	writer.writerow(header)
	writer.writerows(data1)
	writer.writerow(['Tim','dad'])

# secret_array = np.empty([2, 2], dtype=str)

def validateLogin(username, password):
	input_username = username.get()
	input_password = password.get()
	# print("username entered :", input_username)
	# print("password entered :", input_password)

	with open("Secrets.csv", 'r') as file:
		csv_reader = csv.reader(file)
		login_true = FALSE
		for line in csv_reader:
			if (line[0]==input_username) and (line[1]==input_password):
				login_true = TRUE
				break
		if login_true:
			print("he valid")
		else:
			print("invalid")

	# #for setting up a user
	# with open("Secrets.csv", 'w', newline='') as file:
	# 	writer = csv.writer(file)
	# 	writer.writerow([input_username, input_password])


	# with open('test.npy', 'wb') as f:
	# 	np.save(f, np.array([1, 2]))
	# 	np.save(f, np.array([1, 3]))
	# with open('test.npy', 'rb') as f:
	# 	a = np.load(f)
	# 	b = np.load(f)
	# print(a, b)


	# f = open("secrets.txt", "a")
	# f.write(input_username+', '+input_password)
	# x = np.array([input_username, input_password])
	# f.close()
	
	return

#window
tkWindow = Tk()  
tkWindow.geometry('400x150')  
tkWindow.title('Tkinter Login Form - pythonexamples.org')

#username label and text entry box
usernameLabel = Label(tkWindow, text="User Name").grid(row=0, column=0)
username = StringVar()
usernameEntry = Entry(tkWindow, textvariable=username).grid(row=0, column=1)  

#password label and password entry box
passwordLabel = Label(tkWindow,text="Password").grid(row=1, column=0)  
password = StringVar()
passwordEntry = Entry(tkWindow, textvariable=password, show='*').grid(row=1, column=1)  

validateLogin = partial(validateLogin, username, password)

#login button
loginButton = Button(tkWindow, text="Login", command=validateLogin).grid(row=4, column=0)  

tkWindow.mainloop()
import matplotlib
matplotlib.use("TkAgg")
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2Tk
from matplotlib.figure import Figure
import matplotlib.animation as animation
from matplotlib import style
import tkinter as tk
from tkinter import ttk
import pacemaker
import sv_ttk

# initializing graph
f = Figure(figsize=(5,4), dpi=100)
a = f.add_subplot(111)

# start data at 0
data = open('data.txt', 'w')
data.write("0,0")
data_file = data.filename()
data.close()

# function to animate and update graph
def animate(i):
    pullData = open(data_file,'r').read()
    dataArray = pullData.split('\n')
    xar=[]
    yar=[]
    for eachLine in dataArray:
        if len(eachLine)>1:
            x,y = eachLine.split(',')
            xar.append(int(x))
            yar.append(int(y))
    a.clear()
    a.plot(xar,yar)

class Egram(tk.Frame):
    
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        label = ttk.Label(self, text="Electrogram", font=("Arial", 12))
        label.pack(pady=10,padx=10)

        B3 = ttk.Button(self, text = "Back to parameters", command=lambda: controller.show_frame(pacemaker.ParamSelect))
        B3.place(x=10,y=10)

        canvas = FigureCanvasTkAgg(f, self)
        canvas.show()
        canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=1)

        toolbar = NavigationToolbar2Tk(canvas, self)
        toolbar.update()
        canvas._tkcanvas.pack(side=tk.TOP, fill=tk.BOTH, expand=1)

app = pacemaker.Application()
app.maxsize(1280,720)
sv_ttk.set_theme("light")
app.mainloop()
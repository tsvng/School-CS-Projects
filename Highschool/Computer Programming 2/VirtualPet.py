#William T., CP2 Mods 4-5, Virtual Pet
from nodebox.graphics import *
from nodebox.gui import *
from os.path import exists
import pickle
import time
import math
class Pet:
    def __init__(self):
        self.weight = 50
        self.loss = .1
        self.alive = True
        self.birthday = time.time()
        self.age = 0
    def show(self):
        fill(1.00,.89,.94)
        ellipse(250,150,50+self.weight,50+self.weight)
        
        if self.alive:
            self.age = time.time() - self.birthday
            fill(0)
            text(str(int(self.age)),100,250)
        if int(self.age) % 10 == 0:
            self.weight-=.01
if exists("save.p") == True:
    bob = pickle.load( open( "save.p", "rb" ) )
else:
    bob = Pet();
 
def buttonPress(button):
    bob.weight+=5
def closeProgram(button):
    pickle.dump(bob,open("save.p","wb" ))
    canvas.stop()
b = Button(caption="Feed me!", action=buttonPress, x=350, y=50, width=125, id=None)
canvas.append(b)
c = Button(caption="Close Program", action=closeProgram, x=350, y=10, width=125, id=None)
canvas.append(c)
def draw (canvas):
        background(1)
        bob.show()
        
        
canvas.size = 500,300
canvas.run(draw)

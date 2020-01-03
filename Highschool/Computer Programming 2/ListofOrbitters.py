#WIlliam Tsang, CP2 Mods 4-5, A List of Spinners
from nodebox.graphics import *
from nodebox.gui import *
import random

class Orbitter:
    def __init__(self):
        self.x = canvas.mouse.x
        self.y = canvas.mouse.y
        self.angle = random.randint(0,360)
        self.radius = random.randint(10,50)
        self.speed = random.randint(-10,10)
    def show(self):
        
        push()
        translate(self.x,self.y)
        rotate(self.angle)
        translate(self.radius,0)
        ellipse(0,0,10,10)
        pop()
    def spin (self):
            self.angle+= self.speed
amount=[]

def draw (canvas):
    if canvas.keys.pressed == False:
        background(1,1,1,.2)
    if canvas.mouse.pressed == True:
        amount.append(Orbitter())
    for i in amount:
        i.show()
        i.spin()
    
canvas.fullscreen = True
canvas.run(draw)

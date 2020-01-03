#William T. CP2 Mods 4-5, Fractal Tree
from nodebox.graphics import *
from nodebox.gui import *
import math
import random
class Tree:
    def __init__(self):
        self.branchMultiplyer = .8
        self.smallestBranch = 10
        self.branchAngle = .3
    def show(self):
        
        stroke(.4656,.2672,.2672,.5)
        line(canvas.width/2,20,canvas.width/2,120)
        self.drawBranches(canvas.width/2,120,200,math.pi/2+random.uniform(.008,0.015))
    def drawBranches(self,x,y,branchLength,angle):
        if branchLength < 25:
            stroke(0,1,0,.2)
        elif branchLength >= 25:
            stroke(.4656,.2672,.2672,.5)
        angle1 = angle + self.branchAngle
        branchLength = branchLength*self.branchMultiplyer
        endX1 = int((branchLength*math.cos(angle1) + x))
        endY1 = int((branchLength*math.sin(angle1) + y))
        line(x,y,endX1,endY1)
        angle2 = angle - self.branchAngle
        endX2 = int((branchLength*math.cos(angle2) + x))
        endY2 = int((branchLength*math.sin(angle2) + y))
        line(x,y,endX2,endY2)
        if branchLength > self.smallestBranch:
            self.drawBranches(endX1,endY1,branchLength,angle1)
            self.drawBranches(endX2,endY2,branchLength,angle2)
    
def draw (canvas):
    
    background(.25,42,.92)
    fill(.5,1,0)
    ellipse(random.randint(50,canvas.width-50),random.randint(100,canvas.height),70,70)
    fill(.4297,.3333,.2373)
    rect(0,0,canvas.width,100)
    bob.show()
 
canvas.size=850,500
bob = Tree()
strokewidth(5) 
canvas.fullscreen = True
canvas.fps=30
canvas.run(draw)

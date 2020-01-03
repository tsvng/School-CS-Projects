#William Tsang, CP2 Mods 4-5, Two Dice
from nodebox.graphics import *
import random
class Die:
    def __init__(self):
        self.roll()
    def roll(self):
        self.dots = random.randint(1,6)
    def show(self,x,y):
        a = random.uniform(0,1)
        b = random.uniform(0,1)
        stroke(0)
        fill(random.uniform(0,1),random.uniform(0,1),random.uniform(0,1))
        rect(x,y,30,30)
        fill(random.uniform(0,1),random.uniform(0,1),random.uniform(0,1))
        if self.dots == 1:
            ellipse(x + 15,y + 15,5,5)
        if self.dots == 2:
            ellipse(x + 7,y + 23,5,5)
            ellipse(x + 23,y + 7,5,5)
        if self.dots == 3:
            ellipse(x + 7,y + 23,5,5)
            ellipse(x + 15,y + 15,5,5)
            ellipse(x + 23,y + 7,5,5)
        if self.dots == 4:
            ellipse(x + 7,y + 23,5,5)
            ellipse(x + 23,y + 7,5,5)
            ellipse(x + 23,y + 23,5,5)
            ellipse(x + 7,y + 7,5,5)
        if self.dots == 5:
            ellipse(x + 7,y + 23,5,5)
            ellipse(x + 23,y + 7,5,5)
            ellipse(x + 23,y + 23,5,5)
            ellipse(x + 7,y + 7,5,5)
            ellipse(x + 15,y + 15,5,5)
        if self.dots == 6:
            ellipse(x + 7,y + 23,5,5)
            ellipse(x + 23,y + 7,5,5)
            ellipse(x + 23,y + 23,5,5)
            ellipse(x + 7,y + 7,5,5)
            ellipse(x + 7,y + 15,5,5)
            ellipse(x + 23,y + 15,5,5)
            
  
def draw (canvas):
    
    if canvas.mouse.pressed or canvas.frame == 1:
        background(1,1,1)
        i = 0
        total = 0
        while i < 14:
            lucky = Die()
            lucky.roll()
            lucky.show(i*36,canvas.height/2)
            total = total + lucky.dots
            i+=1
        
        fill(0)
        text("Total roll: " + str(total),10,10)
    
canvas.size = 500,500
canvas.fps = 10
canvas.run(draw)

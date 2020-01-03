#William Tsang, CP2 Mods 4-5, City Skyline
from nodebox.graphics import *
import random
class Building:
    def __init__(self):
        self.width = random.randint(50,100)
        self.height = random.randint(100,350)
        self.win = random.randint(25,40)
        self.confusingjarviswithtoomanyvariablesv2 = random.randint(0,10) 
    def show(self,x):
        fill(0)
        rect(x,0,self.width,self.height)
        while self.confusingjarviswithtoomanyvariablesv2 < 15:
            fill(.98,1,.36)
            rect(x + self.win,self.height - self.win,5,10)
            self.confusingjarviswithtoomanyvariablesv2+=1
            self.win = random.randint(5,40)
            self.height-=25
                    
def draw (canvas):
    if canvas.mouse.pressed or canvas.frame == 1:
        background(0.05,0,.37)
        i = 0
        locX = random.randint(-10,850)
        locY = random.randint(-10,500)
        confusingjarviswithtoomanyvariables = random.randint(0,10)
        fill(0.87,0.88,0.84)
        ellipse(random.randint(100,800),random.randint(0,450),200,200)
        while confusingjarviswithtoomanyvariables < 500:
            fill(.91,.94,.56)
            ellipse(locX,locY,2,2)
            confusingjarviswithtoomanyvariables+=1
            locX = random.randint(-10,850)
            locY = random.randint(-10,500)
        while i <17 :
            city = Building()
            city.show(i*50)
            i+=1
        canvas.size = 800,450
canvas.run(draw)

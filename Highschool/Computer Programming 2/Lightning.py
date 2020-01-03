#William Tsang, CP2 Mods 4-5, Lightning
from nodebox.graphics import *
import random

def draw (canvas):
    xi = 0
    yi = canvas.height/2
    background(0,0,0,0.6)
    if canvas.mouse.pressed:
        while xi < 2400:
            xf = xi + random.randint(1,10)
            yf = yi + random.randint(-10,10)
            stroke(random.uniform(0,1),random.uniform(0,1),random.uniform(0,1),0.5)
            strokewidth(3)
            line(xi,yi,xf,yf)
            xi = xf
            yi = yf
       
        
canvas.size = 500,500
canvas.fullscreen = True
canvas.fps = 10
canvas.run(draw)


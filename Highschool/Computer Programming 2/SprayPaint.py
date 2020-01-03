#William Tsang, CP2 Mods 4-5, Spray Paint

#Press q to change the color of the spray paint.
#Press e to change the color of the background. Pressing the spacebar will change the background to white.
from nodebox.graphics import *
import random
import math
background(1,1,1)
def draw (canvas):
    if canvas.keys.pressed and canvas.keys.char == 'q':
        fill(random.uniform(0,1),random.uniform(0,1),random.uniform(0,1))
    if canvas.keys.pressed and canvas.keys.char == 'e':
        background(random.uniform(0,1),random.uniform(0,1),random.uniform(0,1))
    simon = 250
    snooplion = 10
    if canvas.mouse.pressed:
        while simon > snooplion:
            theta = random.uniform(0,2*math.pi)  #random angle in radians
            radius = random.randint(0,40) #maximum radius is 20
            x = canvas.mouse.x + int(math.cos(theta)*radius)
            y = canvas.mouse.y + int(math.sin(theta)*radius)
            ellipse(x,y,2,2)
            simon -=1
    if canvas.keys.pressed and canvas.keys.char == ' ':
            background(1,1,1)
canvas.fullscreen = True
canvas.run(draw)

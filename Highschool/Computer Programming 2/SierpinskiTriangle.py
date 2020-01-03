#William T. CP2 Mods 4-5, Sierpinski's Triangle
#IT'S EQUILATERAL
from nodebox.graphics import *
import random
def sierpinski(x,y,len):
     triangle(x,y,x+len/2,y+(len*3**(1/2.))/2,x+len,y)
     if len > 20:
          stroke(random.uniform(0,1),random.uniform(0,1),random.uniform(0,1))
          sierpinski(x,y,len/2)
          sierpinski(x+len/2,y,len/2)
          sierpinski(x+len/4,y+(len/2*3**(1/2.)/2),len/2)
     
          
def draw (canvas):
    if canvas.mouse.pressed or canvas.frame == 1:
          background(0)
          sierpinski(5,5,490.)
canvas.size = 500,500
canvas.run(draw)

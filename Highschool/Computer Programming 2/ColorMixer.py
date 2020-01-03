#William Tsang, CP2 Mods 4-5, Color Mixer4
from nodebox.graphics import *
from nodebox.gui import *
import random

panel = Panel("Color Mixing", width=300, height=200)
s = Slider(default=1, min=0.0, max=1.0, steps=256)
t = Slider(default=.5, min=0.0, max=1.0, steps=256)
u = Slider(default=.5, min=0.0, max=1.0, steps=256)
v = Slider(default=.5, min=0.0, max=1.0, steps=256)

panel.append(
    Rows(controls=[
      ("alpha", s),
      ("red", t),
      ("green", u),
      ("blue", v)
      ]))
panel.x = 50
panel.y = 50
panel.pack()
canvas.append(panel)

def draw (canvas):
    background(1)
    a = s.value
    r = t.value
    g = u.value
    b = v.value
    fill(r,g,b,a)
    ellipse(250,350,250,250)
    fill(0,0,0,a)
    text("Alpha Percentage: " + str(int(a*100)) + "%",260,130)
    fill(r,0,0)
    text("Red Percentage: " + str(int(r*100)) + "%",260,110)
    fill(0,g,0)
    text("Green Percentage: " + str(int(g*100)) + "%",260,90)
    fill(0,0,b)
    text("Blue Percentage: " + str(int(b*100)) + "%",260,70)
   

canvas.size = 500,500
canvas.run(draw)

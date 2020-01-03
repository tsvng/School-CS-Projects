#William T., CP 2 Mods 4-5, BattleShip
from nodebox.graphics import *
from nodebox.gui import *
import random
 
class Ship:
    def __init__(self):
        self.x = random.randint(0,9)
        self.y = random.randint(0,6)
        self.hiding = [[(self.x,self.y),(self.x,self.y+1),(self.x,self.y+2),(self.x,self.y+3)],[(self.y,self.x),(self.y+1,self.x),(self.y+2,self.x),(self.y+3,self.x)]]
        if random.randint(0,1) == 1:
            self.hiding = self.hiding[0]
        else:
            self.hiding = self.hiding[1]
        self.hits = 0
    def isHit (self, id):
        if id in self.hiding:
            self.hiding.remove(id)
            self.hits+=1
            return True
        else:
            return False
    
    def isSunk(self):
        if self.hits >= 4:
            return True
        else:
            return False
        
 
def buttonPress(button):
    if button.caption != " ":
        return
    if bob.isHit(button.id) == True:
        button.caption = "Hit!"
    elif bob.isHit(button.id) == False:
        button.caption = "Miss"
    
    
    
def buttonSetup():
    buttons = []
    for r in range(10):
        buttons.append([])
        for c in range(10):
            buttons[r].append(Button(caption=None, action=buttonPress, x=20 + 40 * c, y=20 + 29 * r, width=40, id=(r,c)))
            canvas.append(buttons[r][c])
 
def draw (canvas):
    background(1)
    fill(0)
    if bob.isSunk() == True:
        text("DURKER DURR!",175,350)
    
   
canvas.size = 500,500
bob = Ship()
buttonSetup()
canvas.run(draw)

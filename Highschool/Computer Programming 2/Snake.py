#William T., CP2 Mods 4-5, Snake
from nodebox.graphics import *

class Snake:
    def __init__(self):
        self.segments =[Segment(20,0)]
        self.segments[0].clr = Color(1,1,0)
        self.dir = UP
        self.gameOver = False
        self.scr = 0
    def show(self):
        
        if self.gameOver == False:
            if canvas.frame % 10 == 0:
              self.scr+=1
        if self.gameOver == True:
            background(0)
            fill(1)
            fontsize(30) 
            text("Game Over",canvas.width/2-100,canvas.height/2)
            fontsize(15)
            text("Press the Spacebar to Restart",canvas.width/2-135,canvas.height/2-30)
            text("Score:" + str(self.scr),canvas.width/2-135,canvas.height/2-50)
        elif self.gameOver == False:
            for seg in self.segments:
                seg.show()
        
   
    def move(self):
        last = len(self.segments) - 1
        for i in range(last,0,-1):
            self.segments[i].x = self.segments[i-1].x
            self.segments[i].y = self.segments[i-1].y
        if self.dir == UP:
            self.segments[0].y+=20
        elif self.dir == DOWN:
            self.segments[0].y-=20
        elif self.dir == LEFT:
            self.segments[0].x-=20
        elif self.dir == RIGHT:
            self.segments[0].x+=20
        for i in range(1,len(self.segments),1):      
            if self.segments[0].x == self.segments[i].x and self.segments[0].y == self.segments[i].y:
                self.gameOver = True
            if self.segments[0].x < 0 or self.segments[0].x > canvas.width - 20 or self.segments[0].y < 0 or self.segments[0].y > canvas.height - 20:
                self.gameOver = True
                    
    
    
class Segment:
    def __init__(self,x,y):
        self.x = x
        self.y = y
        self.size = 20
        self.clr = Color(1,0,0)

    def show(self):
        stroke(0)
        fill(self.clr)
        rect(self.x,self.y,self.size,self.size)
    
def on_key_press(canvas,keys):
    if canvas.keys.code == UP and bob.dir != DOWN  or canvas.keys.char == 'w' and bob.dir != DOWN:
        bob.dir = UP
    elif canvas.keys.code ==DOWN and bob.dir != UP or canvas.keys.char == 's'and bob.dir != UP:
        bob.dir = DOWN
    elif canvas.keys.code == LEFT and bob.dir != RIGHT or canvas.keys.char == 'a'and bob.dir != RIGHT:
        bob.dir = LEFT
    elif canvas.keys.code == RIGHT and bob.dir != LEFT or canvas.keys.char == 'd'and bob.dir != LEFT:
        bob.dir = RIGHT
    elif bob.gameOver == True and canvas.keys.pressed and canvas.keys.char == ' ':
        bob.segments =[Segment(20,0)]
        bob.segments[0].clr = Color(1,1,0)
        bob.dir = UP
        bob.gameOver = False
        bob.scr = 0
        
bob = Snake()

def draw (canvas):
    background(1)
    bob.move()
    bob.show()
    if canvas.frame % 10 == 0:
        bob.segments.append(Segment(0,0))

canvas.fps = 15
canvas.on_key_press = on_key_press
canvas.size = 600,400
canvas.run(draw)


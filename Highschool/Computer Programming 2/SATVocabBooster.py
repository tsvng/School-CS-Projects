#William T,, CP2 Mods 4-5, SAT Vocabulary Booster
from nodebox.graphics import *
from nodebox.gui import *
import random
dict={} 
satWords = open("SAT4991.txt", "r") 
for line in satWords:
    first = line.find('\t')
    second = line.find('\t',first+1)
    dict[line[:first]] = line[second+1:]
word1 = random.choice(dict.keys())
word2 = random.choice(dict.keys())
word3 = random.choice(dict.keys())
word4 = random.choice(dict.keys())
randint = random.randint(1,4)
if randint == 1:
    worddef = dict[word1]
elif randint == 2:
    worddef = dict[word2]
elif randint == 3:
    worddef = dict[word3]
elif randint == 4:
    worddef = dict[word4]

satWords.close()


def buttonPress(button):
    global correct, incorrect, tscore
    background(1)
    word1 = random.choice(dict.keys())
    word2 = random.choice(dict.keys())
    word3 = random.choice(dict.keys())
    word4 = random.choice(dict.keys())
    randint = random.randint(1,4)
    if randint == 1:
        worddef = dict[word1]
    elif randint == 2:
        worddef = dict[word2]
    elif randint == 3:
        worddef = dict[word3]
    elif randint == 4:
        worddef = dict[word4]
    background(1)
    space = (worddef.find(" ",40))
    text(worddef[:space],250,200)
    text(worddef[space:],245,170)
    button1.caption = word1
    button2.caption = word2
    button3.caption = word3
    button4.caption = word4
    if worddef == dict[word1] and button.caption == word1:
        correct+=1
    elif worddef == dict[word2] and button.caption == word2:
        correct+=1
    elif worddef == dict[word3] and button.caption == word3:
        correct+=1
    elif worddef == dict[word4] and button.caption == word4:
        correct+=1
    else:
        incorrect+=1
    
    text("Amount Correct:" + str(correct),150,250)
    text("Amount Incorrect:" + str(incorrect),550,250)
    
    
    
button1 = Button(caption= word1, action=buttonPress, x=225, y=70, width=125, id=None)
canvas.append(button1)
button2 = Button(caption= word2 , action=buttonPress, x=225, y=20, width=125, id=None)
canvas.append(button2)
button3 = Button(caption= word3 , action=buttonPress, x=525, y=70, width=125, id=None)
canvas.append(button3)
button4 = Button(caption= word4 , action=buttonPress, x=525, y=20, width=125, id=None)
canvas.append(button4)

def draw (canvas):
    if canvas.frame == 1:
        global correct, incorrect, space
        correct = 0
        incorrect = 0
        background(1)
        space = (worddef.find(" ",40))
        text(worddef[:space],250,200)
        text(worddef[space:],245,170)
        text("Amount Correct:" + str(correct),150,250)
        text("Amount Incorrect:" + str(incorrect),550,250)

canvas.size = 900,300
canvas.run(draw)

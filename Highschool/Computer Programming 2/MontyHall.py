#William Tsang, CP2 Mods 4-5, Monty Hall Problem
import random
count = 1
wc = 0
carswap = 0
while count <= 100000:
    countr = (random.randint(1,3))
    pick = (random.randint(1,3))
    car = (random.randint(1,3))
    if countr == 1 and car == 1:
        countr = random.randint(2,3)
    elif countr == 2 and car == 1:
        countr = 1
    elif countr == 3 and car == 1:
        countr = 1
    elif countr == 1 and car == 2:
        countr = 2
    elif countr == 2 and car == 2:
        countr = random.randint(0,1)
        countr = 1+2*countr
    elif countr == 3 and car == 2:
        countr = 2
    elif countr == 1 and car == 3:
        countr = 3
    elif countr == 2 and car == 3:
        countr = 3
    elif countr == 3 and car == 3:
        countr = random.randint(1,2)
    if countr == car:
        carswap = carswap + 1
    if pick == countr:  
         wc = wc + 1
    count = count + 1
print("The win percentage if you don't switch is"),
print(wc/1000.),
print("%")
print("The win percentage if you DO switch is"),
print(carswap/1000.),
print("%")



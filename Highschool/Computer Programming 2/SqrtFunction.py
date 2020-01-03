#William Tsang, CP2 Mods 4-5,Square Root Function

def sqrt(y):
    global newGuess
    oldGuess = y/2
    x = 0
    while x < 100:
        newGuess = ((y/oldGuess)+oldGuess)/2.0
        oldGuess = newGuess
        x = x + 1
def main():
    print("Enter a positive number (or a negative number to quit) : ")
    y = float(raw_input())
    sqrt(y)
    if y < 0:
        print("Quitting, goodbye!")
    else:
        print("Square root is : " + str(newGuess))
        print("Difference is : " + str(newGuess - y ** 0.5))
        main()
main()

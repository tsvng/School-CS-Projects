#William Tsang, CP2 Mods 4-5, Computus
print("Please enter a year:")
y = int(raw_input())
a = y%19
b = y/100
c = y%100
d = b/4
e = b%4
g = ((8*b) + 13)/25
h = ((19*a)+b-d-g+15)%30
j = c/4
k = c%4
m = (a+11*h)/319
r = ((2*e)+(2*j)-k-h+m+32)%7
n = (h-m+r+90)/25
p = (h-m+r+n+19)%32
if y <= 2012:
     print("Easter Sunday was on"),
else:
    print("Easter Sunday will be on"),
if n == 3:
     print("March"),
else:
    print("April"),
print(p),
print(","),
print(y),
print(".")




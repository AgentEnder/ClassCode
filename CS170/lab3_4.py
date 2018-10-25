from math import sqrt
a = 0.0
b = 0.0
c = 0.0
sides = 0.0
area = 0.0
while True:
    a = input("What is the first leg?")
    b = input("What is the second leg?")
    c = input("What is the hypotenous?")
    if(a.lower() == "exit" or b.lower() == "exit" or c.lower() == "exit"):
            break
    a = float(a)
    b = float(b)
    c = float(c)
    sides = (a + b + c)/2
    area = sqrt(sides*(sides - a)*(sides - b)*(sides - c))
    print ("Your area is: ", area)
    

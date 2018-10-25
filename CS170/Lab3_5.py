import math
a = 0.0
b = 0.0
length = 0.0
radians = 0.0
while True:
    a = input("What is the height of the ladder in feet?")
    b = input("What is the angle in degrees of the ladder?")
    if(a.lower() == "exit" or b.lower() == "exit"):
            break
    a = float(a)
    b = math.radians(float(b))
    length = a/math.sin(b)
    
    print ("The length of the ladder is: ", length, "ft")
    

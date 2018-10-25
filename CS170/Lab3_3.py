x1 = 0.0
x2 = 0.0
y1 = 0.0
y2 = 0.0
distance = 0.0
while True:
    x1 = input("What is the first x cordinate?")
    y1 = input("What is the first y cordinate?")
    x2 = input("What is the second x cordinate?")
    y2 = input("What is the second y cordinate?")
    if(x1.lower() == "exit" or x2.lower() == "exit" or y1.lower() == "exit" or y2.lower() == "exit"):
            break
    x1 = float(x1)
    x2 = float(x2)
    y1 = float(y1)
    y2 = float(y2)
    distance = (y2 - y1)/(x2 - x1)
    print ("Your distance is: ", distance)
    

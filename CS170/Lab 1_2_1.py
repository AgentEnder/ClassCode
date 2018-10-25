#Name: Josh Webb, Craigory Coppola (Group 9)
#Date: 9/6/2016
#This is the Chaos program (Lab #1 Number 2.1)
#By changing the Chaos program's 3.9 value to 2.0 it causes the values of x to
#approach the value .5 and does not go any greater. 

def main():
    print("This program illustrates a chaotic function")
    x = eval(input("Enter a number between 0 and 1: "))
    for i in range(10):
        x = 2.0 * x * (1 - x)
        print(x)

main()
    

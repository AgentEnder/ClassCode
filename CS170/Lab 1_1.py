#Name: Josh Webb, Craigory Coppola (Group 9)
#Date: 9/6/2016
#This program converts Fahrenheit to Celsius (Lab #1 Number 1)
def main():
    fahrenheit = eval(input("What is the fahrenheit temperature? "))
    celsius = (fahrenheit - 32)*(5/9)
    print("The temperature is", celsius, "degrees.")

main()

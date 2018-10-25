#Name: Josh Webb, Craigory Coppola (Group 9)
#Date: 9/6/2016
#This program converts fahrenheit to celsius (Lab #1 Number 3)
#The task of this program to is show the intervals between 10 degrees in Fahrenheit
#to it's coressponding degrees in celsius

def main(): #Defines your function
    for i in range(10): #This is the for loop that will run 10 times
        fahrenheit = i * 10 + 32 #Calculates your fahrenheit value based on what i is 
        celsius = (fahrenheit - 32) * 5.0 / 9.0 #Calculates your celsius value based on your fahrenheit value
        print (fahrenheit, "degrees Fahrenheit =", celsius, "degrees Celsius\n") #Prints the results of your fahrenheit and celsius calculations

main() #Calls the function to run
    

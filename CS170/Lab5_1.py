def average (a,b,c):
    avr = (a + b + c)/3.0
    return avr
def main():
    a1,b1,c1 = eval(input("Please enter any three numbers(Seperated by a comma): "))
    avr1 = average(a1,b1,c1)
    print("The average of these numbers = ", avr1)
main()

    

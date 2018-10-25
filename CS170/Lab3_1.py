n = 0.0
priceOfCoffee = 0.0
while True:
    
     n = (input("How many of pounds of coffee do you want?"))
     if (n.lower() == "exit"):
            break
     n = float(n)
     priceOfCoffee = 10.50 + 0.86 * n + 1.50
     print ("Your order costs: $", priceOfCoffee)

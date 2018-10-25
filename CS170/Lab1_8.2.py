#Names: Craigory Coppola, Joshua Web (Group 9)
#Date: 9/6/16
#Purpose: calculate the area of a circle

import enderInput
import math

a = enderInput.getFloat(prompt="Enter side length A:")
b = enderInput.getFloat(prompt="Enter side length B:")
c = math.sqrt((a**2+b**2))
print("C:%d \nPerimeter:%d \nArea:%d" %(c, a+b+c, a*b/2))
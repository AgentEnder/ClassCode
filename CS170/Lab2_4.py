import enderInput
from math import sin
from math import pi
while(True):
	a = enderInput.getFloat(prompt = "Enter side a:")
	b = enderInput.getFloat(prompt = "Enter side b:")
	theta = enderInput.getFloat(0,180, "Enter the angle between sides a and b:")
	radians = theta/180*pi
	area = (1/2)*a*b*sin(radians)
	print(area)
	con = enderInput.getString("Would you like to continue?")
	if con.lower()[0] == "n":
		break;
import enderInput
from math import pi
def sphereVolume(radius):
	return (4/3)*pi*radius**3
def sphereArea(radius):
	return 4*pi*radius**2
	
r = enderInput.getFloat(prompt = "What is the radius of the sphere?")
print("The sphere's surface area is %f, the volume is %f"%(sphereArea(r),sphereVolume(r)))

import enderInput
from math import pi
n = enderInput.getInt(prompt="How many numbers would you like to use?")
sln = 0
for i in range(n):
	if (i%2 == 1):
		sln -= (4/((i*2)+1))
	else:
		sln += (4/((i*2)+1))
print(sln)
print("The estimation is off by: %.9f" %(pi - sln))
import enderInput
from math import pi
def sumN(n):
	x = 0
	for i in range(n):
		x+=(i+1)
	return x
def sumNCubes(n):
	x = 0
	for i in range(n):
		x+=(n+1)**3
	return x
n = enderInput.getInt(prompt="What number would you like to go up to?")
print("The sum of the first %d natural numbers is %d, and the sum of the cubes is %d"%(n,sumN(n),sumNCubes(n)))
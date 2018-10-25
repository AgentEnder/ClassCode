import enderInput

n = enderInput.getInt(prompt="How many numbers would you like to add?")
sln = 0
for i in range(n):
	sln+=i
print(sln)
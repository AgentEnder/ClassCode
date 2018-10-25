import enderInput

n = enderInput.getInt(prompt="How many numbers would you like to add?")
sln = 0
for i in range(n):
	sln += enderInput.getInt(prompt  = "Enter number %d" %(i+1))
print(sln)
import enderInput
print("What words would you like to make an acronym of?")
words = enderInput.getString().split()
for w in words:
	print(w[0].upper(), end="")

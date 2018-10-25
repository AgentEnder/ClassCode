import enderInput
count = 0;
print("Want to draw a box?")
while(True):
	if(count!=0):
		print("Want to draw another box? if not type exit at any time.")
	len = enderInput.getInt(prompt="What is the length?")
	wid = enderInput.getInt(prompt="What is the width?")
	char = enderInput.getChar(prompt="What charachter would you like?")
	for i in range(len):
		if(i==len-1 or i == 0):
			print(char*wid)
		else:
			for w in range(wid):
				if(w==0):
					print(char, end = "")
				elif(w==wid-1):
					print(char)
				else:
					print(" ", end ="")
	count+=1
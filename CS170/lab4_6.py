import enderInput
print("What string would you like to count charachters and letters in?")
str = enderInput.getString()
chrs = len(str);
wrds = len(str.split())
print("There are %d charachters and %d words"%(chrs, wrds))
